#include <bits/stdc++.h>
using namespace std;
//https://www.acmicpc.net/problem/2615

/*
<오목>
주요: 구현, 브루트포스
1. 5개가 연속으로 이루어져있는지 판단한다.
2. 6목을 조심해서 idx를 조사한다.
3. 조건이 맞다면 정답을 출력한다.

*/

int board[21][21];
bool game_end = false;
int ans_x, ans_y;

// 오른쪽 판단
void right(int x, int y){
  int cnt = 0;
  for (int i = 1; i <= 4; i++) {
    int nx = x, ny = y+i;
    if(nx > 19 || ny > 19 || nx < 1 || ny < 1) break;
    if(board[x][y] == board[nx][ny]) cnt++;
    else break;
  }

  if(cnt < 4) return;
  else if(cnt == 4){
    int prvx = x, prvy = y-1;
    int nx = x, ny = y+5;
    if(ny == 20){
      if(board[prvx][prvy] == board[x][y]) return;
    }
    else if (prvy == 0){
      if(board[nx][ny] == board[x][y]) return;
    }
    else{
      if(board[nx][ny] == board[x][y] || board[prvx][prvy] == board[x][y]) return;
    }

    game_end = true;
    ans_x = x, ans_y = y;
    return;
  }
}

// 오른쪽 대각선 아래
void rightdown(int x, int y){
  int cnt = 0;
  for (int i = 1; i <= 4; i++) {
    int nx = x+i, ny = y+i;
    if(nx > 19 || ny > 19 || nx < 1 || ny < 1) break;

    if(board[x][y] == board[nx][ny]) cnt++;
    else break;
  }
  if(cnt < 4) return;
  else if(cnt == 4){
    int prvx = x-1, prvy = y-1;
    int nx = x+5, ny = y+5;
    if(nx == 20 || ny == 20){
      if(board[prvx][prvy] == board[x][y]) return;
    }
    else if (prvx == 0){
      if(board[nx][ny] == board[x][y]) return;
    }
    else{
      if(board[nx][ny] == board[x][y] || board[prvx][prvy] == board[x][y]) return;
    }
    game_end = true;
    ans_x = x, ans_y = y;
    return;
  }
}

// 아래
void down(int x, int y){
  int cnt = 0;
  for (int i = 1; i <= 4; i++) {
    int nx = x+i, ny = y;
    if(nx > 19 || ny > 19 || nx < 1 || ny < 1) break;

    if(board[x][y] == board[nx][ny]) cnt++;
    else break;
  }
  if(cnt < 4) return;
  else if(cnt == 4){
    int prvx = x-1, prvy = y;
    int nx = x+5, ny = y;
    if(nx == 20){
      if(board[prvx][prvy] == board[x][y]) return;
    }
    else if (prvx == 0){
      if(board[nx][ny] == board[x][y]) return;
    }
    else{
      if(board[nx][ny] == board[x][y] || board[prvx][prvy] == board[x][y]) return;
    }
    game_end = true;
    ans_x = x, ans_y = y;
    return;
  }
}

// 왼쪽 아래
void leftdown(int x, int y){
  int cnt = 0;
  for (int i = 1; i <= 4; i++) {
    int nx = x+i, ny = y-i;
    if(nx > 19 || ny > 19 || nx < 1 || ny < 1) break;

    if(board[x][y] == board[nx][ny]) cnt++;
    else break;
  }

  if(cnt < 4) return;
  else if(cnt == 4){
    int prvx = x-1, prvy = y+1;
    int nx = x+5, ny = y-5;
    if(nx == 20){
      if(board[prvx][prvy] == board[x][y]) return;
    }
    else if (prvx == 0 || prvy == 20){
      if(board[nx][ny] == board[x][y]) return;
    }
    else{
      if(board[nx][ny] == board[x][y] || board[prvx][prvy] == board[x][y]) return;
    }
    game_end = true;
    ans_x = x+4, ans_y = y-4;
    return;
  }
}

int main(int argc, char const *argv[]) {

  for (int i = 1; i <=19 ; i++) {
    for (int j = 1; j <=19; j++) {
      cin >> board[i][j];
    }
  }

  // 오목 판단
  for (int i = 1; i <= 19; i++) {
    for (int j = 1; j <= 19; j++) {
      if(board[i][j] == 0) continue;
      right(i,j);
      rightdown(i,j);
      down(i,j);
      leftdown(i,j);
      if(game_end){
        cout << board[ans_x][ans_y] << endl;
        cout << ans_x << " " << ans_y;
        return 0;
      }
    }
  }
  cout << "0";
  return 0;
}
