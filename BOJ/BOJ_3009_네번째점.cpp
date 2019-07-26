#include <iostream>
using namespace std;
//https://www.acmicpc.net/problem/3009
/*
<네 번째 점>
주요: 수학
1. 단순 비교문제이다.
2. 첫 번째 입력값을 기준으로 2,3번째 입력값을 비교하여 마지막 값을 찾는다.
3. x, y좌표를 찾아 출력한다.

*/

int main() {

  int dot[3][2], x, y;

  for (int i = 0; i < 3; i++) {
    cin >> dot[i][0] >> dot[i][1];
  }

  // x 좌표 찾기
  if(dot[0][0] == dot[1][0]){ x = dot[2][0];}
  else if(dot[0][0] == dot[2][0]){ x = dot[1][0];}
  else{ x = dot[0][0];}

  // y좌표 찾기
  if(dot[0][1] == dot[1][1]){ y = dot[2][1];}
  else if(dot[0][1] == dot[2][1]){ y = dot[1][1];}
  else{ y = dot[0][1];}

  cout << x << " " << y;

  return 0;
}
