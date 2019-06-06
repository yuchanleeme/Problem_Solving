#include <iostream>
#include <algorithm>
using namespace std;
//https://www.acmicpc.net/problem/9465

/*
<카드 구매하기>
주요: DP를 활용한다.
1. 1번 카드팩만 이용해 1을 만들 때를 dp[1]이라고 하자.
2. 1,2번카드팩만 이용해 2를 만들 때를 dp[2]라고 하자.
  => dp[1]에 1번 카드팩 하나를 더 산 경우와 2번 카드팩 하나만을 산경우를 비교한다.
  => dp[2] = max(dp[1]+p[1], p[2])
3. 위와 같은 방법으로 1~N번카드팩을 이용할 때를 비교하면 된다.
  => dp[n] = max(dp[n-1]+p[1], dp[n-2]+p[2], ... dp[n-n/2]+p[n/2], p[n])
  => n/2 까지만 비교해주는 이유: 그 이하까지 했을 시 중복되기 때문이다.
4. 결론적으로 1~(n-1)번째 카드팩으로만 구매한 경우와 n번째 카드팩으로 바로 산 경우 중 촤댓값을 고르면 된다.

*/

int main() {

  int N, p[1001] = {0, };
  int dp[1001];

  cin >> N;
  for (int i = 1; i <= N; i++) {
    cin >> p[i];
  }

  // 2,3,4번
  for (int i = 1; i <= N; i++) {
    dp[i] = p[i];
    for (int j = 1; j <= i/2; j++) {
      dp[i] = max(dp[i-j] + p[j], dp[i]);
    }
  }

  cout << dp[N];

  return 0;
}
