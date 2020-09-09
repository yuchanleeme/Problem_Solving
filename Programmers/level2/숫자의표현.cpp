#include <bits/stdc++.h>
using namespace std;
//https://programmers.co.kr/learn/courses/30/lessons/12924

/*
<숫자의 표현>
주요: 브루트 포스
1. 모든 경우의 수를 다 해보면 된다.
2. temp = 1
          1 + 2
          .
          .
          1 + 2 + .... n/2+1
              2 + 3 + ..... n/2 + 1
              .
              .
              .
  2.1 n/2 + 1까지 하는 이유는 2로 나눴을때가 2개짜리의 마지노선이기 때문이다.
  2.2 각 경우의 수에서 temp == n 이면 answer을 1 증가시킨다.
3. 더하다가 temp가 n보다 크면 for문을 나간다.
4. 위에서 게산한 answer과 자기 자신 1을 더해 리턴한다.

*/

int solution(int n) {
  int answer = 0;
  for (int i = 1; i <= n/2; i++) {
    int temp = 0;
    for (int j = i; j <= n/2+1; j++) {
      temp += j;
      if(temp == n) answer++;
      else if(temp > n) break;
    }
  }
  return answer;
}
