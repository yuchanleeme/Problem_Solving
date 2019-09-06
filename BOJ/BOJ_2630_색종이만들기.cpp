#include <iostream>
#include <vector>
using namespace std;
//https://www.acmicpc.net/problem/2630

/*
<색종이 만들기>
주요: 분할 정복
1. 색종이를 4분할 해서 단위를 나눈다.
  => ex) 16*16 -> 8*8 -> 4*4 ... -> 1*1
2. 나눈 범위만큼 조사한다.
  => 만약 범위의 모든 값들이 같다면 흰 색종이, 파란 색종이 이므로 개수를 추가시켜준다.
  => 하나라도 다른 값들이 있다면 다시 단위를 나누어준다.
3. 다 조사한 뒤 흰 색종이, 파란 색종이의 개수를 출력해준다.

*/

int w = 0, b = 0;
vector<vector<int> > square;

void divide(int num, int x, int y){
  bool is_w = false;
  bool is_b = false;

  // 범위안에 같은 값만 있는지 조사 하는 for문
  for (int i = x; i < x+num; i++) {
    for (int j = y; j < y+num; j++) {
      if(square[i][j] == 0){
        // white
        is_w = true;
        if(is_b){
          j = y + num; // 즉시 종료
        }
      }
      else{
        // blue
        is_b = true;
        if(is_w){
          j = y + num; // 즉시 종료
        }
      }
    }
  }

  // 다시 분할 할것인지 아니면 개수 추가할 것인지 정해준다.
  if(is_w && !is_b){ w++;}
  else if(!is_w && is_b){ b++;}
  else{
    while(num != 1){
      int idx = num/2;
      divide(idx, x, y);  // left up
      divide(idx, x, y+idx);  // right up
      divide(idx, x+idx, y);  // left down
      divide(idx, x+idx, y+idx);  // right down
      return;
    }
  }
}

int main() {

  int N;
  cin >> N;

  square = vector<vector<int> > (N, vector<int>(N,0));
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cin >> square[i][j];
    }
  }

  divide(N, 0, 0);

  cout << w << endl << b;

  return 0;
}
