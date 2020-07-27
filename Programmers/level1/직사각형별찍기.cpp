#include <iostream>
//https://programmers.co.kr/learn/courses/30/lessons/12969

/*
<직사각형 별 찍기>
주요: 구현
1. 가로, 세로 값을 받는다.
2. 조건에 맞게 출력한다.

*/

using namespace std;

int N, M;
int main(void) {
  cin >> N >> M;
  for (int i = 0; i < M; i++) {
    for (int j = 0; j < N; j++) {
      cout << "*";
    }
    cout <<"\n";
  }
  return 0;
}
