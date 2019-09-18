#include <iostream>
#include <vector>
#include <queue>
using namespace std;
//https://www.acmicpc.net/problem/1261

/*
<알고스팟?>
주요: 다익스트라 알고리즘
1. 인접행렬로 미로의 정보를 받아온다.
2. 상하좌우로만 움직일 수 있다는 걸 인지한다.
  => [0][0]부터 시작한다고 하고 [M-1][N-1] 까지 이동하는 최단경로를 구한다.
3. 벽을 뚫는다면 1이란 값이 추가되는 것이다. (가중치 1인 노드)
  => 최소한의 벽을 뚫고 지나가야하기 때문에 가중치가 작은 방향으로 나아가는 것이다.
  => 이런 점에서 최단거리 - 다익스트라 알고리즘을 사용한다.
4. 마지막에 계산된 dist 벡터에서 [M-1][N-1]를 출력한다.

==========
* M, N 순서만 유의해서 풀자.
* BOJ_4485외 유사문제

*/

int INF = 100000;
int d_x[4] = {-1, 0, 0, 1}, d_y[4] = {0, -1, 1, 0};

int main() {

  int N, M;

  scanf("%d %d", &N, &M);

  vector<vector<int> > maze(M, vector<int>(N, 0));
  vector<vector<int> > dist(M, vector<int>(N, INF));

  for (int i = 0; i < M; i++) {
    for (int j = 0; j < N; j++) {
      scanf("%1d", &maze[i][j]);
    }
  }

  priority_queue<pair<int, pair<int,int> > > que;
  que.push({-maze[0][0] ,{0,0}});
  dist[0][0] = maze[0][0];

  while (!que.empty()) {
    int cur_nodeX = que.top().second.first;
    int cur_nodeY = que.top().second.second;
    int cur_dist = -que.top().first;
    que.pop();

    if(cur_dist > dist[cur_nodeX][cur_nodeY]){ continue;}
    for (int i = 0; i < 4; i++) {
      int tx = cur_nodeX + d_x[i];
      int ty = cur_nodeY + d_y[i];

      if(tx >= 0 && tx < M && ty >= 0 && ty < N){
        int next_nodeX = tx;
        int next_nodeY = ty;
        int next_dist = dist[cur_nodeX][cur_nodeY] + maze[tx][ty];

        if(next_dist < dist[next_nodeX][next_nodeY]){
          dist[next_nodeX][next_nodeY] = next_dist;
          que.push({-next_dist,{next_nodeX, next_nodeY}});
        }
      }
    }
  }

  printf("%d\n", dist[M-1][N-1]);

  return 0;
}
