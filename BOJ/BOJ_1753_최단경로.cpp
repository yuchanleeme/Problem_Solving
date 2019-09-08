#include <iostream>
#include <queue>
#include <vector>
using namespace std;
//https://www.acmicpc.net/problem/1753

/*
<최단 경로>
주요: 다익스트라 알고리즘
1. 다익스트라 알고리즘을 통해 구현한다.
2. 출발 노드를 기준으로 각 노드까지 가는 최소 비용을 저장한다. (w)
3. 출발 노드에서 다른 노드로 갈때 가장 비용이 적은 노드를 선택한다.
  => 그 노드로 가는 경우 중에 다른 특정 노드를 거쳐서 가는 경우와 다이렉트로 가는 노드의 거리값을 비교한다.
  => 더 작은값으로 최소 비용을 갱신한다.
  => 모든 정점과 간선을 계산할 때까지 큐에 넣으면서 비교한다.
  => 큐가 비면 종료한다.
4. 최소비용 값을 출력한다. (w)
  => 가는 길이 없으면 INF를 출력한다.

==========
* 인접핼렬로 놓고 풀었더니 시간초과가 떴다. (20000개의 정점을 생각 못함)
* 우선순위 큐는 first부터 비교하므로 거리 값을 먼저 pair로 넣는다.

*/

int INF = 2000000;
int main() {

  int V, E, K, x, y, z;
  scanf("%d %d %d", &V, &E, &K);

  vector<pair<int, int> > graph[V+1]; // 간선 정보(도착점, 거리)
  vector<int> w(V+1, INF); // 가중치

  for (int i = 0; i < E; i++) {
    scanf("%d %d %d", &x, &y, &z);
    graph[x].push_back({z,y}); // 우선순위 큐는 first 부터 비교하기에 거리 값을 먼저 first에 넣는다.
  }

  priority_queue<pair<int, int> > que;
  w[K] = 0;
  que.push({0, K});

  while(!que.empty()){
    int cur_node = que.top().second; // 도착하는 정점
    int cur_distance = -que.top().first; // 간선 정보의 음수화 및 이 정점까지의 최솟값
    que.pop(); // 정보를 다썼으니 pop

    if(w[cur_node] < cur_distance) continue; // 정점으로 이동후 계산이 더크기 때문에 기존값을 사용한다.
    for (int i = 0; i < graph[cur_node].size(); i++) {
      int next_node = graph[cur_node][i].second; // 연결되어있는 다음 정점
      int next_distance = cur_distance + graph[cur_node][i].first; // 여기까지의 최솟값 + 다음 정점까지 이동거리

      if(next_distance < w[next_node]){
        w[next_node] = next_distance;
        que.push({-next_distance, next_node});
      }
    }
  }

  for (int i = 1; i <= V; i++) {
    if(w[i] == INF){
      printf("INF\n");
    }
    else{
      printf("%d\n", w[i]);
    }
  }

  return 0;
}
