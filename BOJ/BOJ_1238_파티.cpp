#include <iostream>
#include <queue>
#include <vector>
using namespace std;
//https://www.acmicpc.net/problem/1238

/*
<파티>
주요: 다익스트라 알고리즘
1. 다익스트라 알고리즘을 이용한다.
2. 아이가 Y마을에 산다고 가정하면 (Y마을-> X마을) , (X마을-> Y마을)의 합의 최솟값이 각 아이의 최단거리이다.
  2-1) 저 두경로의 최단거리를 모든 N명을 기준으로 구하면 비효율적이다.
  2-2) X마을에서 각 1~N 마을까지의 최단거리를 구하면 함수호출 횟수를 줄일 수 있다.
3. 따라서 1~N 마을에서 X마을 까지의 최단거리를 구하고 미리 구해둔 최단거리(2-2)를 이용해 비교한다.
4. 모든 아이의 경로중 가장 시간이 소요가 많이 되는 값을 출력한다.

*/

int INF = 1000000;
int N, M, X;

// 1번
vector<int> time_dijk(vector<pair<int, int> > road[], int start){

  vector<int> dist(N+1, INF);

  priority_queue<pair<int, int> > que;
  dist[start] = 0;
  que.push({0, start});

  while (!que.empty()) {
    int cur_node = que.top().second;
    int cur_dist = -que.top().first;
    que.pop();

    if(cur_dist > dist[cur_node]){ continue;}
    for (int i = 0; i < road[cur_node].size(); i++) {
      int next_node = road[cur_node][i].second;
      int next_dist = cur_dist + road[cur_node][i].first;

      if(next_dist < dist[next_node]){
        dist[next_node] = next_dist;
        que.push({-next_dist, next_node});
      }
    }
  }
  return dist;
}

int main() {

  cin >> N >> M >> X;

  vector<pair<int, int> > road[N+1];
  for (int i = 0; i < M; i++) {
    int start, end, d;
    cin >> start >> end >> d;
    road[start].push_back({d, end});
  }

  int res = 0;
  // 2-2번
  vector<int> x_to_go = time_dijk(road, X);

  // 3번
  for (int i = 1; i <= N; i++) {
    vector<int> i_to_go = time_dijk(road, i);
    res = max(res, x_to_go[i] + i_to_go[X]);
  }

  // 4번
  cout << res;

  return 0;
}
