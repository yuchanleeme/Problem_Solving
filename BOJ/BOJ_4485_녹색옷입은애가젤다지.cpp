#include <iostream>
#include <vector>
#include <queue>
using namespace std;
//https://www.acmicpc.net/problem/4485

/*
<녹색 옷 입은 애가 젤다지?>
주요: 다익스트라 알고리즘
1. 인접행렬로 각 코인값을 받아온다.
2. 상하좌우로만 움직일 수 있다는 걸 인지한다.
  => 이를 인지한채 다익스트라 알고리즘을 사용한다.
  => [0][0]부터 시작한다고 하고 [N-1][N-1] 까지 이동하는 최단경로를 구한다.
3. 마지막에 dist[N-1][N-1] 출력하고 while문에서 N이 0을 받을 때까지 반복한다.

=========
* Problem을 소문자(problem)로 해 WA가 떴다.
  => 문제 출력 형식을 잘 살펴보자.

*/

int INF = 100000;
int d_x[4] = {-1, 0, 0, 1}, d_y[4] = {0, -1, 1, 0};

int main() {

  int N, problem = 1;
  
  while(cin >> N){
    if(N == 0) { break;}

    vector<vector<int> > cave(N, vector<int>(N, 0));
    vector<vector<int> > dist(N, vector<int>(N, INF));

    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
        cin >> cave[i][j];
      }
    }

    priority_queue<pair<int, pair<int,int> > > que;
    que.push({-cave[0][0] ,{0,0}});
    dist[0][0] = cave[0][0];

    while (!que.empty()) {
      int cur_nodeX = que.top().second.first;
      int cur_nodeY = que.top().second.second;
      int cur_dist = -que.top().first;
      que.pop();

      if(cur_dist > dist[cur_nodeX][cur_nodeY]){ continue;}
      for (int i = 0; i < 4; i++) {
        int tx = cur_nodeX + d_x[i];
        int ty = cur_nodeY + d_y[i];

        if(tx >= 0 && tx < N && ty >= 0 && ty < N){
          int next_nodeX = tx;
          int next_nodeY = ty;
          int next_dist = dist[cur_nodeX][cur_nodeY] + cave[tx][ty];

          if(next_dist < dist[next_nodeX][next_nodeY]){
            dist[next_nodeX][next_nodeY] = next_dist;
            que.push({-next_dist,{next_nodeX, next_nodeY}});
          }
        }
      }
    }

    printf("problem %d: %d\n", problem++, dist[N-1][N-1]);
  }
  return 0;
}
