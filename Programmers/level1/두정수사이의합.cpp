#include <algorithm>
#include <vector>
using namespace std;
//https://programmers.co.kr/learn/courses/30/lessons/12912

/*
<두 정수 사이의 합>
주요: 구현
1. 큰 수가 오른쪽에 오게 swap한다.
2. a~b까지 for문 돌면서 세준다.
==========
* 처음부터 효율성 고려해서 1~N의 합 f(N) = N*(N+1)/2 로 풀려 했지만,
  => 그냥 단순 for문 으로 하나씩 세도 되는 문제였다.
*/

long long solution(int a, int b) {
  long long answer = 0;
  if(a > b) swap(a,b);
  for (int i = a; i <= b; i++) {
    answer += i;
  }
  return answer;
}
