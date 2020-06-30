#include <iostream>
#include <vector>
using namespace std;
// https://www.acmicpc.net/problem/11055

/*
<가장 큰 증가하는 부분 수열>
주요: DP
1. dp[x] = x번째 원소를 포함했을때 그때 까지의 최대값
2. 자기 보다 작은 idx의 A값들 중에 가장 큰 값을 찾는다.
  => 그 큰 값과 자기 자신의 값을 더해 dp에 저장시킨다.
3. dp값들 중 가장 큰 값을 출력한다.

*/
int N;
int A[1010];
int dp[1010];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> N;
  for (int i = 0; i < N; i++)
    cin >> A[i];

  int ans = 0;
  for (int i = 0; i < N; i++) {
    int res = 0;
    for (int j = 0; j < i; j++) {
      // 2번
      if(A[j] < A[i])
        res = max(res, dp[j]);
    }
    dp[i] = res + A[i];
    ans = max(ans, dp[i]);  // 3번
  }
  cout << ans;

	return 0;
}
