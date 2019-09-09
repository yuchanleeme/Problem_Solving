#include <iostream>
#include <queue>
#include <vector>
using namespace std;
//https://www.acmicpc.net/problem/1504

/*
<특정한 최단 경로>
주요: 다익스트라 알고리즘
1. 1->A->B->N이나 1->B->A->N 으로 가야한다.
  => 구간 구간 끊어서 1->A(1->B), A->B(B->A), B->N(A->N)이 모든 값이 최소값이면 가능하다는 소리다.
  => 그런데 양방향이므로 A->B 최솟값이나 B->A의 최솟값이나 같다.
  => 또한  B->N(A->N)은 N->A(N->B)로 계산하면 된다.
2. 위의 1번 설명에 의해서 각 구간까지의 최솟값을 더하고 비교해서 계산하면 된다.
3. 만약 ans가 INF 이상이면 -1을 출력한다.(경로 없으므로) 아니면 ans 출력한다.

*/

int N, E, x, y, z;
int INF = 10000000;

pair<int, int> dijkstra(vector<pair<int, int> > graph[],int first, int num_1, int num_2){

  vector<int> w(N+1, INF);

  priority_queue<pair<int, int> > que;
  w[first] = 0;
  que.push({0, first});

  while (!que.empty()) {
    int cur_node = que.top().second;
    int cur_distance = -que.top().first;
    que.pop();

    if(w[cur_node] < cur_distance) continue;
    for (int i = 0; i < graph[cur_node].size(); i++) {
      int next_node = graph[cur_node][i].second;
      int next_distance = cur_distance + graph[cur_node][i].first;

      if(next_distance < w[next_node]){
        w[next_node] = next_distance;
        que.push({-next_distance, next_node});
      }
    }
  }

  return make_pair(w[num_1], w[num_2]);

}

int main() {

  int ans, a, b;
  cin >> N >> E;
  vector<pair<int, int> > graph[N+1];
  for (int i = 0; i < E; i++) {
    cin >> x >> y >> z;
    graph[x].push_back({z,y});
    graph[y].push_back({z,x});
  }
  cin >> a >> b;

  // 1번
  pair<int, int> t_1 = dijkstra(graph, 1, a, b); // 1->(a or b)
  pair<int, int> t_2 = dijkstra(graph, a, b, b); // a -> b or b -> a
  pair<int, int> t_3 = dijkstra(graph, N, b, a); // a-> N or b -> N

  // 2번
  ans = min(t_1.first + t_2.first + t_3.first, t_1.second + t_2.second + t_3.second);

  if(ans > INF){
    cout << "-1";
  }
  else{
    cout << ans;
  }
  return 0;
}
