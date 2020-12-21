#include <bits/stdc++.h>
using namespace std;
//https://www.acmicpc.net/problem/2636

/*
<치즈>
주요: BFS, 구현
1. 외부공기 덩어리 찾기 (BFS)
2. 찾으면서 접촉한 애들 싹 다 좌표에 넣기
3. 좌표에 넣은 애들 0으로 초기화
4. 다시 1번 부터 반복하다가 남은 치즈가 0개 일때 값 출력
===========
* 이 문제의 키포인트는 치즈의 입장에서 테두리를 따는게 아니라 외부공기의 입장에서 테두리를 따는것이다.

*/

int R, C, melttime, prevcheeze;
int baseboard[110][110];
int visitboard[110][110]; // 0 : 미방문, 1: 방문한 공기, 2: 방문한 치즈
int tx[4] = {-1,0,1,0}, ty[4] = {0,1,0,-1};

queue<pair<int, int> > outAir; // 외부공기
queue<pair<int, int> > cheeze; // 치즈

int main(int argc, char const *argv[]) {
  cin >> R >> C;
  for (int i = 0; i < R; i++) {
    for (int j = 0; j < C; j++) {
      cin >> baseboard[i][j];
      if(baseboard[i][j] == 1) prevcheeze++;
    }
  }

  // BFS 시작
  while(true){
    melttime++;
    // 1,2번
    visitboard[0][0] = 1;
    outAir.push({0, 0});
    while(!outAir.empty()){
      int temp_size = outAir.size();
      for (int i = 0; i < temp_size; i++) {
        for (int j = 0; j < 4; j++) {
          int nx = outAir.front().first + tx[j];
          int ny = outAir.front().second + ty[j];
          if(nx < 0 || nx >= R || ny < 0 || ny >= C || visitboard[nx][ny] == 1) continue;
          // 외부 공기인지 치즈인지 판단
          if(baseboard[nx][ny] == 0 && visitboard[nx][ny] == 0){
            visitboard[nx][ny] = 1;
            outAir.push({nx, ny});
          }
          else if(baseboard[nx][ny] == 1 && visitboard[nx][ny] != 2){
            visitboard[nx][ny] = 2;
            cheeze.push({nx, ny});
          }
        }
      }
      outAir.pop();
    }

    // 3번
    while(!cheeze.empty()){
      int nx = cheeze.front().first;
      int ny = cheeze.front().second;
      baseboard[nx][ny] = 0;
      cheeze.pop();
    }

    // 4번
    int remain = 0;
    for (int i = 0; i < R; i++) {
      for (int j = 0; j < C; j++) {
        if(baseboard[i][j] == 0) visitboard[i][j] = 0;
        else if(baseboard[i][j] == 1) remain++;
      }
    }
    if(remain == 0){
      cout << melttime << "\n" << prevcheeze;
      break;
    }
    prevcheeze = remain;

  }



  return 0;
}
