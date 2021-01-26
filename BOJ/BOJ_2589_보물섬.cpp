#include <bits/stdc++.h>
using namespace std;
//https://www.acmicpc.net/problem/2589

/*
<보물섬>
주요: BFS
1. 'L'을 만날 때마다 BFS 탐색을 돌아 그 round수를 계산한다.
2. 최대 round 수를 계산해 출력한다.
==========
* cnt-1을 리턴하는 이유
  => 큐가 다 비워지기 전 마지막 원소들 조사할 때 cnt가 1이 더 증가한다.

*/

int L, W, ans;
vector<string> island;
int dx[4] = {-1, 1, 0, 0}, dy[4] = {0, 0, 1, -1};

int bfs(int x, int y){

  int cnt = 0;
  int tempVisit[55][55] = {0, };
  queue<pair<int, int> > que;

  que.push({x, y});
  tempVisit[x][y] = 1;
  while (!que.empty()) {
    int temp_size = que.size();
    for (int i = 0; i < temp_size; i++) {
      for (int j = 0; j < 4; j++) {
        int nx = que.front().first + dx[j];
        int ny = que.front().second + dy[j];

        if(nx < 0 || ny < 0 || nx >= L || ny >= W) continue;
        if(tempVisit[nx][ny] == 1) continue;
        if(island[nx][ny] == 'L'){
          que.push({nx, ny});
          tempVisit[nx][ny] = 1;
        }
      }
      que.pop();
    }
    cnt++;
  }
  return cnt-1;
}


int main(int argc, char const *argv[]) {
  cin >> L >> W;
  for (int i = 0; i < L; i++) {
    string input; cin >> input;
    island.push_back(input);
  }

  // BFS
  for (int i = 0; i < L; i++) {
    for (int j = 0; j < W; j++) {
      if(island[i][j] == 'L'){
        ans = max(ans, bfs(i, j));
      }
    }
  }

  cout << ans;

  return 0;
}
