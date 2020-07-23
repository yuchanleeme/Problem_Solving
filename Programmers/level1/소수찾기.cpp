#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
//https://programmers.co.kr/learn/courses/30/lessons/12921

/*
<소수 찾기>
주요: 에라토스테네스의 체
1. 에라토스테네스의 체를 이용해서 소수를 구한다.
2. prime 배열을 순회하면서 소수일 때 answer값을 증가시킨다.
3. 최종 개수를 리턴한다.
==========
* 효율성을 위해 소수 찾는 알고리즘을 최적화 했다.

*/

int prime[1010101];
int solution(int n) {
  int answer = 0;
  for (int i = 2; i <= sqrt(n); i++) {
    if (prime[i] == 1) continue;
    else{
      for (int j = i*i; j <= n; j+=i) {
       prime[j] = 1;
      }
    }
  }
  for (int i = 2; i <= n; i++) {
    if (prime[i] == 0) answer++;
  }
  return answer;
}
