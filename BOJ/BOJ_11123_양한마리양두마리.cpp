#include <bits/stdc++.h>
using namespace std;
// https://www.acmicpc.net/problem/11123

/*
<양 한마리... 양 두마리...>
주요: BFS
1. BFS 탐색으로 양들의 그룹을 센다.
2. 테스트케이스만큼 센 다음 그 결과를 출력한다.

*/

int T, H, W;
int dx[4] = {-1,0,1,0}, dy[4] = {0,1,0,-1};
vector<string> sheep;

void bfs(){

  int visitSheep[110][110] = {0, };
  int cnt = 0;

  queue<pair<int, int> > que;
  for (size_t i = 0; i < H; i++) {
    for (size_t j = 0; j < W; j++) {
      if(visitSheep[i][j] == 0 && sheep[i][j] == '#'){
        cnt++;
        que.push({i,j});
        visitSheep[i][j] = 1;
        while (!que.empty()) {
          int temp_size = que.size();
          for (int k = 0; k < temp_size; k++) {
            for (size_t idx = 0; idx < 4; idx++) {
              int nx = que.front().first + dx[idx];
              int ny = que.front().second + dy[idx];

              if(nx < 0 || ny < 0 || nx >= H || ny >= W) continue;
              if(visitSheep[nx][ny] == 1 || sheep[nx][ny] == '.') continue;
              visitSheep[nx][ny] = 1;
              que.push({nx, ny});
            }
            que.pop();
          }
        }
      }
    }
  }
  cout << cnt << "\n";
}

int main(){
  cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);

  cin >> T;
  while (T--) {
    cin >> H >> W;
    sheep.clear();

    for (int i = 0; i < H; i++) {
      string temp; cin >> temp;
      sheep.push_back(temp);
    }
    bfs();
  }
  return 0;
}
