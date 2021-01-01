#include <bits/stdc++.h>
using namespace std;
//https://www.acmicpc.net/problem/16918

/*
<봄버맨>
주요: 구현
1. 폭탄 설치를 할 때 시간배열을 이용한다.
2. 폭탄 설치 시간과 경과시간을 비교해 폭탄을 터뜨린다.
3. 최종 폭탄 현황을 출력한다.

*/

int R, C, N;
vector<string> bomb;
int remainTime[210][210];
int tx[4] = {-1, 0, 1, 0}, ty[4] = {0, 1, 0, -1};

void bfs(int x, int y, int time){

  remainTime[x][y] = -1;
  bomb[x][y] = '.';
  for (int i = 0; i < 4; i++) {
    int nx = x + tx[i];
    int ny = y + ty[i];

    if(nx < 0 || ny < 0 || nx >= R || ny >= C) continue;
    if(remainTime[nx][ny] == time) continue;
    remainTime[nx][ny] = -1;
    bomb[nx][ny] = '.';
  }
}

int main(int argc, char const *argv[]) {
  cin >> R >> C >> N;
  for (int i = 0; i < R; i++) {
    string temp;
    cin >> temp;
    bomb.push_back(temp);
    for (int j = 0; j < temp.length(); j++) {
      if(temp[j] == 'O') remainTime[i][j] = 0;
      else remainTime[i][j] = -1;
    }
  }

  for (int time = 2; time <= N; time++) {
    for (int i = 0; i < R; i++) {
      for (int j = 0; j < C; j++) {
        if(time % 2 == 0){
          if(bomb[i][j] == '.'){
            remainTime[i][j] = time;
            bomb[i][j] = 'O';
          }
        }
        else{
          if(remainTime[i][j] == (time-3)){
            bfs(i, j, time-3);
          }
        }
      }
    }
  }

  for (int row = 0; row < R; row++) {
    for (int col = 0; col < C; col++) {
      cout << bomb[row][col];
    }
    cout << "\n";
  }
  return 0;
}
