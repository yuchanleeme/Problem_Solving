#include <iostream>
#include <algorithm>
using namespace std;
//https://www.acmicpc.net/problem/1463

/*
<1로 만들기>
주요: DP
1. 연산방법은 3가지 라는것에 주목한다.
2. 전형적인 DP 문제로 1,2,3 연산을 했을때 작은 것을 기준으로 문제를 풀면 된다.
  ex-1) dp[4] = dp[2] + 1  // dp[5] = dp[4] + 1
  ex-2) dp[6] = a[2] + 1 (1번연산)    /
              = a[3] + 1 (2번연산)    / -> 세가지 답중 최솟값이 답이 된다.
              = a[5] + 1 (3번연산)    /
3. 2,3으로 나눠질수 있다고 무조건 최솟값이 아니라는것을 알아야 한다.

*/
const int MAX_VAL = 1000000;
int dp[1000001] = {0,0,1,1,};
int main() {

  int N, a, b, c, minVal ,cnt = 4;
  scanf("%d", &N);
  while (cnt < N+1) {

    a = MAX_VAL;
    b = MAX_VAL;
    c = MAX_VAL;

    // 3으로 나눠 질 경우 a 에 저장
    if (cnt % 3 == 0) {
      a = dp[cnt/3];
    }

    // 2로 나눠 질 경우 b에 저장
    if (cnt % 2 == 0) {
      b = dp[cnt/2];
    }

    // 1을 뺀 값을 c에 저장
    c = dp[cnt-1];

    // a,b,c 중 최솟값 찾기
    minVal = min(a,b);
    minVal = min(minVal,c);

    // 최솟값 + 처음 1,2,3 연산 한 횟수인 1
    dp[cnt] = minVal + 1;
    cnt++;
  }

  printf("%d\n",dp[N]);

  return 0;
}
