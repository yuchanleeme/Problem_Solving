#include <bits/stdc++.h>
using namespace std;
//https://programmers.co.kr/learn/courses/30/lessons/12905

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

int dp[1010][1010] = {0, };
int solution(vector<vector<int>> board){
  int row = board.size();
  int col = board[0].size();
  int ans = 0;
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
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

  return ans*ans;
}
