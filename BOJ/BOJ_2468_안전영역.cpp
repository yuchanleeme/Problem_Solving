#include <iostream>
#include <queue>
#include <vector>
using namespace std;
//https://www.acmicpc.net/problem/2468

/*
<안전 영역>
주요: BFS
1. BFS로 그래프를 탐색한다.
2. 각 높이마다 안전 영역의 개수를 센 뒤 크기 비교해준다.
  => map[i][j]가 높이 h보다 낮은 값이면 visit[i][j] 를 1로만든다.
  => 이를 토대로 각 영역을 BFS 탐색한다.
3. 가장 많은 영역의 값을 출력한다.

*/
int N;
int dx[4] = {-1, 1, 0, 0}, dy[4] = {0, 0, 1, -1};
vector<vector<int> > map;

int bfs(int h){
  int res = 0;
  vector<vector<int> > visit(N, vector<int>(N, 0));
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if(map[i][j] < h){ visit[i][j] = 1;}
    }
  }

  queue<pair<int, int> > que;

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if(visit[i][j] == 0){
        res++;
        que.push({i, j});
        visit[i][j] = 1;

        while (!que.empty()) {
          for (int p = 0; p < 4; p++) {
            int tx = que.front().first + dx[p];
            int ty = que.front().second + dy[p];
            if(tx >= 0 && tx < N && ty >=0 && ty < N){
              if(visit[tx][ty] == 0){
                que.push({tx, ty});
                visit[tx][ty] = 1;
              }
            }
          }
          que.pop();
        }
      }
    }
  }

  return res;
}

int main() {

  cin >> N;
  map = vector<vector<int> >(N, vector<int>(N, 0));
  int maxValue = 0;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cin >> map[i][j];
      maxValue = max(maxValue, map[i][j]);
    }
  }

  int ans = 0;
  for (int k = 1; k <= maxValue; k++) {
    int cal_value = bfs(k);
    ans = max(ans, cal_value);
  }
  cout << ans;

  return 0;
}
