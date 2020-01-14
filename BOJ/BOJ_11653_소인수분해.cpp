#include <iostream>
#include <vector>
using namespace std;
//https://www.acmicpc.net/problem/11653

/*
<소인수분해>
주요: 수학
1. N이 1이 될 때까지 차례대로 소인수분해한다.
2. 2부터 차례대로 다음 값을 조사해서 출력한다.

*/

int main() {

  int N;
  cin >> N;

  int factor = 2;
  while (N != 1) {
    if(N % factor == 0){
      cout << factor << '\n';
      N /= factor;
    }
    else{
      factor++;
    }
  }
  return 0;
}
