#include <iostream>
using namespace std;
// https://www.acmicpc.net/problem/10773

/*
<제로>
주요: 가장 마지막에 삽입된 수를 빼준다.
1. 입력받은 수가 0 일때 마지막에 삽입된 수를 빼준다.
2. 정수가 '0'일 경우에 유의한다.
  - '0'이면 가장 최근에 쓴 수를 지우고, 아닐 경우 해당 수를 쓴다.
  - '0'이 처음 입력 받았을 때도 고려해주었음.

*/

int main() {

  int K, N, sum = 0, idx = 0;
  int data[100001];

  cin >> K;

  for (int i = 0; i < K; i++) {

    cin >> N;

    // 입력받은 수가 0 일때(idx 가 0이 아닐 때)
    if(N == 0 && idx != 0){
      data[idx--] = 0;
    }
    else{
      data[idx++] = N;
    }
  }

  for (int j = 0; j < idx; j++) {
    sum += data[j];
  }

  cout << sum << endl;

  return 0;
}
