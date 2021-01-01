#include <bits/stdc++.h>
using namespace std;
//https://www.acmicpc.net/problem/14582

/*
<오늘도 졌다>
주요: 구현
1. 이기고 있을때 winning 값을 true로 만든다.
2. 최종으로 졌는데, winning값이 true면 역전패로 간주한다.

*/

int U, S;
int ulim[11], startlink[11];
bool winning = false;
int main(int argc, char const *argv[]) {

  for (int i = 1; i <= 9; i++)
    cin >> ulim[i];
  for (int i = 1; i <= 9; i++)
    cin >> startlink[i];

  for (int i = 1; i <= 9; i++) {
    U += ulim[i];
    if(U > S) winning = true;
    S += startlink[i];
  }

  if(winning && U < S)
    printf("Yes");
  else
    printf("No");
  return 0;
}
