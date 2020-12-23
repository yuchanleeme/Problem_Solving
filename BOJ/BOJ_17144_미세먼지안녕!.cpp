#include <bits/stdc++.h>
using namespace std;
//https://www.acmicpc.net/problem/17144

/*
<미세먼지 안녕!>
주요: 구현
1. 확산된 미세먼지를 먼저 더해놓는다.
  => room[nx][ny][time+1](다음) += room[x][y][time]/5
  => room[x][y][time](기존) -= room[x][y][time]/5;
2. 미세먼지의 확산이 끝나면 기존에 있던 미세먼지의 값을 더해준다.
  => room[i][j][time+1] += room[i][j][time]
3. 이제 공기청정기를 돌려 미세먼지를 순환시킨다.
4. 마지막에 남은 미세먼지값을 계산한다.

*/

int R, C, T, ans;
int cleanerUR, cleanerDR; // 클리너의 위치
int tx[4] = {-1, 0, 1 ,0}, ty[4] = {0, 1, 0, -1};
int room[55][55][1010]; // room[R][C][시간]

// 미세먼지 확산
void spreadDirt(int x, int y, int time){

  int dirt = room[x][y][time]/5;
  for (int i = 0; i < 4; i++) {
    int nx = x + tx[i];
    int ny = y + ty[i];

    if(nx < 0 || ny < 0 || nx >= R || ny >= C) continue;
    if(ny == 0 && (nx == cleanerDR || nx == cleanerUR)) continue;
    room[nx][ny][time+1] += dirt;
    room[x][y][time] -= dirt;
  }
}

// 공기청정기 작동
void runClean(int time){

  // 위쪽 공기청정기
  room[cleanerUR-1][0][time+1] = 0;
  for (int i = cleanerUR-2; i >= 0; i--) {
    room[i+1][0][time+1] = room[i][0][time+1];
  }
  for (int i = 1; i < C; i++) {
    room[0][i-1][time+1] = room[0][i][time+1];
  }
  for (int i = 1; i <= cleanerUR; i++) {
    room[i-1][C-1][time+1] = room[i][C-1][time+1];
  }
  for (int i = C-2; i > 0; i--) {
    room[cleanerUR][i+1][time+1] = room[cleanerUR][i][time+1];
  }
  room[cleanerUR][1][time+1] = 0;

  // 아래쪽 공기청정기
  room[cleanerDR+1][0][time+1] = 0;
  for (int i = cleanerDR+2; i < R; i++) {
    room[i-1][0][time+1] = room[i][0][time+1];
  }
  for (int i = 1; i < C; i++) {
    room[R-1][i-1][time+1] = room[R-1][i][time+1];
  }
  for (int i = R-2; i >= cleanerDR; i--) {
    room[i+1][C-1][time+1] = room[i][C-1][time+1];
  }
  for (int i = C-2; i > 0; i--) {
    room[cleanerDR][i+1][time+1] = room[cleanerDR][i][time+1];
  }
  room[cleanerDR][1][time+1] = 0;

}

int main(int argc, char const *argv[]) {
  cin >> R >> C >> T;
  for (int i = 0; i < R; i++) {
    for (int j = 0; j < C; j++) {
      cin >> room[i][j][0];
      if(room[i][j][0] == -1){
        if(!cleanerUR) cleanerUR = i;
        else cleanerDR = i;
      }
    }
  }

  for (int time = 0; time < T; time++) {

    // 먼지 확산
    for (int i = 0; i < R; i++) {
      for (int j = 0; j < C; j++) {
        if(room[i][j][time] == -1)
          room[i][j][time+1] = -1;
        else
          spreadDirt(i, j, time);
      }
    }
    // 기존에 있떤 먼지 더하기
    for (int i = 0; i < R; i++) {
      for (int j = 0; j < C; j++) {
        if(room[i][j][time+1] != -1)
          room[i][j][time+1] += room[i][j][time];
      }
    }

    // 공기청정기 돌리기
    runClean(time);
  }

  // 값 계산
  for (int i = 0; i < R; i++) {
    for (int j = 0; j < C; j++) {
      if(room[i][j][T] != -1) ans += room[i][j][T];
    }
  }
  cout << ans;
  return 0;
}
