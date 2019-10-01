#include <iostream>
#include <vector>
using namespace std;
//https://www.acmicpc.net/problem/1094

/*
<막대기>
주요: 수학, 이진수
1. 어렵게 설명하고 있지만 사실은 2진수로 만들었을때 1의 수를 구를 하는 것이다.
2. 2로 나누면서 나머지가 1인 경우의 수를 찾는다.

*/

int main() {

  int X, cnt = 0;

  cin >> X;
  while (X != 0) {
    if(X % 2 == 1){ cnt++;}
    X /= 2;
  }

  cout << cnt;
  return 0;
}
