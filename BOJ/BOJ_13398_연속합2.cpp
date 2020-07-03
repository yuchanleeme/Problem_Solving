#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
//https://www.acmicpc.net/problem/13398

/*
<연속합 2>
주요: DP
1. dp[i][0] : 제외를 한번 했을때 i번째 수열까지의 최댓값
   dp[i][1] : 제외를 하지 않았을 때 i번째 수열까지의 최댓값
2. 두 기준을 잡고 DP값을 갱신한다.
  => 갱신 중 최대값이 나오는 것을 출력한다.
*/


int N;
int seq[101010];
int dp[101010][2];
int main() {

  cin >> N;
  for (int i = 1; i <= N; i++) {
    cin >> seq[i];
    dp[i][1] = seq[i];
  }

  int res = seq[1];
  dp[1][0] = 0;
  dp[1][1] = seq[1];
  for (int i = 2; i <= N; i++) {
    dp[i][1] = max(dp[i][1], dp[i-1][1] + seq[i]);
    dp[i][0] = max(dp[i-1][1], dp[i-1][0] + seq[i]);
    res = max(res, max(dp[i][1], dp[i][0]));
  }
  cout << res;
  return 0;
}
