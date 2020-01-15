#include <iostream>
#include <vector>
using namespace std;
//https://www.acmicpc.net/problem/11050

/*
<이항계수 1>
주요: DP, 파스칼 삼각형
1. 파스칼 삼각형의 성질을 이용한다.
2. top-down 방식의 DP를 이용한다.

*/

int dp[1010][1010];

int solve(int n, int k){

  if(n < 0){
    return 0;
  }
  else if (n == 0 || n == 1){
    return 1;
  }
  else if (k == 0 || n == k){
    return 1;
  }

  if(dp[n][k] != 0){ return dp[n][k];}

  return dp[n][k] = solve(n-1,k) + solve(n-1,k-1);

}

int main() {

  int N, K;
  cin >> N >> K;
  cout << solve(N,K);
  return 0;

}
