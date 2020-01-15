#include <iostream>
#include <vector>
using namespace std;
//https://www.acmicpc.net/problem/2193

/*
<이친수>
주요: DP
1. DP[x][0] : 0으로 끝나는 x자리 이친수의 개수
2. DP[x][1] : 1로 끝나는 x자리 이친수의 개수
3. 답 : DP[N][0] + DP[N][1]
==========
* long long 주의 (결과 값이 생각보다 크다.)

*/

long long dp[100][2] = {0, 0, 0, 1,};

long long solve(int X, int Y){
  if(X < 0){
    return 0;
  }

  if(dp[X][Y] != 0){
    return dp[X][Y];
  }

  if(Y == 0){
    return dp[X][Y] = solve(X-1, 0) + solve(X-1, 1);
  }
  else if (Y == 1){
    return dp[X][Y] = solve(X-1, 0);
  }
}

int main() {

  int N;
  cin >> N;
  cout << solve(N,0) + solve(N,1);

  return 0;
}
