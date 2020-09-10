#include <bits/stdc++.h>
using namespace std;
//https://programmers.co.kr/learn/courses/30/lessons/12945

/*
<피보나치 수>
주요: 구현
1. 피보나치 수를 만들어 나머지를 계산한다.
2. 나머지 계산 시 오버플로우를 방지한다.

*/

int num[101010] = {0,1,1, };
int solution(int n) {

  for (int i = 3; i <= n; i++) {
    num[i] = (num[i-1] + num[i-2]) % 1234567;
  }
  return num[n];

}
