#include <bits/stdc++.h>
using namespace std;
// https://www.acmicpc.net/problem/16713

/*
<점프왕 쩰리(small)>
주요: 구현
1. 모든 경우의 수를 센다.
  => 아래 아래 오른 오른
     아래 오른 아래 오른
     오른 오른 아래 아래
     오른 아래 오른 아래
2. -1을 만난다면 HaruHaru, 못 만났다면 Hing을 출력한다.

*/

int N;
int gameMap[6][6];
int tx[2] = {1, 0}, ty[2] = {0, 1};
int seq[4][4] = {{0,0,1,1}, {1,0,1,0}, {1,1,0,0}, {0,1,0,1}};

int main(){
  cin >> N;
  for (size_t i = 1; i <= N; i++) {
    for (size_t j = 1; j <= N; j++) {
      cin >> gameMap[i][j];
    }
  }

  for (int i = 0; i < 4; i++) {
    int x = 1, y = 1;
    for (int j = 0; j < 4; j++) {
      x += tx[seq[i][j]]*gameMap[x][y];
      y += ty[seq[i][j]]*gameMap[x][y];

      if(gameMap[x][y] == -1) return !printf("HaruHaru");
      else if(gameMap[x][y] == 0) break;
    }
  }
  printf("Hing");

  return 0;
}
