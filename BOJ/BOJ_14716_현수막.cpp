#include <bits/stdc++.h>
using namespace std;
// https://www.acmicpc.net/problem/14716

/*
<현수막>
주요: BFS
1. BFS 탐색을 통해 연결되어 있는 글자들을 묶는다.
2. 글자 하나를 찾을 때마다 ans++를 해주어 출력한다.

*/

int M, N, ans;
int mapVisit[260][260];
int mapBoard[260][260];
int tx[8] = {1,1,1,-1,-1,-1,0,0}, ty[8] = {-1,0,1,-1,0,1,-1,1};
void bfs(int x, int y){

  queue<pair<int, int> > que;
  que.push({x,y});
  mapVisit[x][y] = 1;

  while (!que.empty()) {
    int temp_size = que.size();
    for (int i = 0; i < temp_size; i++) {
      for (int j = 0; j < 8; j++) {
        int nx = que.front().first + tx[j];
        int ny = que.front().second + ty[j];
        if(nx < 0 || ny < 0 || nx >= M || ny >= N) continue;
        if(mapVisit[nx][ny] == 0 && mapBoard[nx][ny] == 1){
          que.push({nx,ny});
          mapVisit[nx][ny] = 1;
        }

      }
      que.pop();
    }
  }
}
int main(){
  cin >> M >> N;
  for (int i = 0; i < M; i++) {
    for (int j = 0; j < N; j++) {
      cin >> mapBoard[i][j];
    }
  }

  for (int i = 0; i < M; i++) {
    for (int j = 0; j < N; j++) {
      if(mapVisit[i][j] == 0 && mapBoard[i][j] == 1){
        bfs(i, j);
        ans++;
      }
    }
  }
  cout << ans;
  return 0;
}
