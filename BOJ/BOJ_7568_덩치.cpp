#include <iostream>
using namespace std;
//https://www.acmicpc.net/problem/7568

/*
<덩치>
주요: 나보다 덩치 큰 사람이 몇명인지 세 본다.
1. 결국 자신의 등수는 자신보다 덩치 큰사람이 몇명이냐에 따라 나뉘게 된다.
2. 몸무게와 키 큰 사람이 몇명인지 세주고 자기 자신까지 합쳐서 등수를 출력하면 된다.

*/

int main() {

  int N, body[51][2]; // 0 : 몸무게 , 1: 키
  int winner;

  cin >> N;

  for (int i = 0; i < N; i++) {
    cin >> body[i][0] >> body[i][1];
  }

  for (int i = 0; i < N; i++) {
    winner = 0;
    for (int j = 0; j < N; j++) {
      if(body[i][0] < body[j][0] && body[i][1] < body[j][1]){
        winner++;
      }
    }
    cout << winner + 1 << " ";
  }

  return 0;
}
