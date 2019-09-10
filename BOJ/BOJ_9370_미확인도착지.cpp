#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
//https://www.acmicpc.net/problem/9370

/*
<미확인 도착지>
주요: 다익스트라 알고리즘
1. 하나의 간선을 무조건 포함하는 다익스트라 알고리즘을 짜는것이다.
2. 경로를 따져보면 S -> g -> h -> (목적지) or S -> h -> g -> (목적지)가 되고 이중 최소값이 답이 된다.
  => 각각 구간을 나누어 보면 S->g , g->h , h->목적지 // S->h , h->g , g->목적지가 된다.
  => 각 두가지 경우중 최소거리를 구하면 된다.
3. 양방향 그래프를 인지하고 각 구간을 다시 나열해보면 g->S, g->h , g->(목적지) , h->S, h->g, h->(목적지)가 된다.
  => 즉, g에서 모든 노드까지의 최단거리, h에서 모든 노드까지의 최단거리 만 구하면 우리가 원하는 모든 구간의 최솟값을 알게 된다.
  => 따라서 위의 두 정점에서의 최단거리를 catch_artist(다익스트라)함수를 통해 구한다.
4. "그들이 급한 상황이기 때문에 목적지까지 우회하지 않고 최단거리로 갈 것이라 확신한다. 이상이다. (취익)"
  => 문제에서 이와 같이 서술 했으므로 위의 2번에서 계산한 최솟값이 S -> (목적지)까지 가는 거리 보다 길다면 res 벡터에 넣지 않는다.
  => 그게 아니라면 예정 목적지가 맞으므로  res 벡터에 그 목적지를 넣는다.
5. 오름차순으로 출력하라했으므로 sort로 정렬해주고 res의 원소들을 출력한다.

*/

int INF = 10000000;

// 다익스트라 알고리즘으로 start 로 시작해서 각 정점까지 도달하는 최단거리를 저장한 벡터를 리턴한다.
vector<int> catch_artist(vector<pair<int, int> > graph[], int start, int N){

  vector<int> w(N+1, INF);

  priority_queue<pair<int, int> > que;
  w[start] = 0;
  que.push({0, start});

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
  return w;
}

int main() {

  int T;
  cin >> T;

  for (int testcase = 0; testcase < T; testcase++) {
    int n, m, t, s, g, h;
    cin >> n >> m >> t >> s >> g >> h;

    vector<pair<int, int> > node[n+1];
    for (int road = 0; road < m; road++) {
      int a, b, d;
      cin >> a >> b >> d;
      node[a].push_back({d,b}); // 양방향
      node[b].push_back({d,a});
    }

    vector<int> goals; // 예상 목적지
    for (int goal = 0; goal < t; goal++) {
      int temp;
      cin >> temp;
      goals.push_back(temp);
    }

    vector<int> w_g = catch_artist(node, g, n); // g -> (1~N)
    vector<int> w_h = catch_artist(node, h, n); // h -> (1~N)
    vector<int> base = catch_artist(node, s, n); // S -> (1~N)

    vector<int> res;
    int g_h = w_g[h]; // g->h 거리
    for (int i = 0; i < goals.size(); i++) {
      int ans;
      int distance_a = w_g[s] + g_h + w_h[goals[i]];
      int distance_b = w_h[s] + g_h + w_g[goals[i]];

      ans = min(distance_a, distance_b);
      // 4번
      if(base[goals[i]] >= ans){
        res.push_back(goals[i]);
      }
    }

    // 5번
    sort(res.begin(),res.end()); // 오름차순으로 정렬한다.
    for (int i = 0; i < res.size(); i++) {
      cout << res[i] << " ";
    }
    cout << endl;
  }

  return 0;
}
