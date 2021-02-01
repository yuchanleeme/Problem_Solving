#include <bits/stdc++.h>
using namespace std;
//https://www.acmicpc.net/problem/1915

/*
<가장 큰 정사각형>
주요: DP
1. 만약 행이나 열의 idx가 0이면 dp[x][y] = board[x][y] (x == 0 || y == 0)
2. 인접한 위,좌상,왼쪽의 dp값이 모두 0이 아닐때
  => dp[x][y] = min(dp[x-1][y], dp[x-1][y-1], dp[x][y-1]) + 1
3. 인접한 위,좌상,왼쪽의 dp값 중 0이 있을 때
  => dp[x][y] = board[x][y]
4. dp값 중 가잔 큰 수의 제곱을 리턴한다.

*/

int ans, N, M;
int dp[1010][1010];
int board[1010][1010];

int main(int argc, char const *argv[]) {

  scanf("%d %d", &N, &M);
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      scanf("%1d ", &board[i][j]);
    }
  }

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      if(board[i][j] == 0) continue;
      if(i == 0 || j == 0){
        dp[i][j] = board[i][j];
        ans = max(ans, dp[i][j]);
        continue;
      }

      int up = dp[i-1][j];
      int diag = dp[i-1][j-1];
      int left = dp[i][j-1];
      int res = min(up,min(diag,left));

      if(res == 0){
        dp[i][j] = board[i][j];
      }
      else{
        dp[i][j] = res+1;
        ans = max(ans, res+1);
      }
    }
  }
  printf("%d", ans*ans);
  return 0;
}
