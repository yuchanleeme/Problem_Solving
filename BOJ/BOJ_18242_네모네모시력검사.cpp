#include <bits/stdc++.h>
using namespace std;
// https://www.acmicpc.net/problem/18242

/*
<네모네모 시력검사>
주요: 구현
1. 각 변의 연속적인 길이를 잰다.
2. 변의 길이가 홀수라고 했으니까 변의 길이 중 짝수인 부분이 해당 방향이다.
3. 위, 왼쪽, 오른쪽만 검사하고 다 아니면 아래라고 출력한다.

*/

int N, M;
int upS, leftS, rightS;
string ans;
vector<string> square;

void squareCheck(int x, int y){
  int by = y;
  // up
  for (int col = by; col < M; col++) {
    if(square[x][col] == '#'){
      upS++;
      by = col;
    }
  }

  // left
  for (int row = x; row < N; row++) {
    if(square[row][y] == '#')
      leftS++;
  }

  // right
  for (int row = x; row < N; row++) {
    if(square[row][by] == '#')
      rightS++;
  }

  if(upS % 2 == 0) ans = "UP";
  else if(leftS % 2 == 0) ans = "LEFT";
  else if(rightS % 2 == 0) ans = "RIGHT";
  else ans = "DOWN";

}

int main(){
  cin >> N >> M;

  for (int i = 0; i < N; i++) {
    string temp;
    cin >> temp;
    square.push_back(temp);
  }

  for (size_t i = 0; i < N; i++) {
    for (size_t j = 0; j < M; j++) {
      if(square[i][j] == '#'){
        squareCheck(i, j);
        i = N;
        break;
      }
    }
  }
  cout << ans;
  return 0;
}
