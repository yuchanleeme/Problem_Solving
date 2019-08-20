/*
https://leetcode.com/problems/climbing-stairs/

main : DP
1. 단순한 DP문제
2. N번째 칸에 오르는 경우는 N-1번째에서 1칸오르거나 N-2번째에서 2칸오르는 경우 두가지이다.
3. 이를 이용해 DP로 계산한다.

*/

class Solution {
public:
  int climbStairs(int n) {

    if(n == 1){
      return 1;
    }

    int dp[n+1] = {0, };

    dp[1] = 1; // first step
    dp[2] = 2; // second step

    for (int i = 3; i <= n; i++) {
      dp[i] = dp[i-2] + dp[i-1];
    }

    return dp[n];

    }
};
