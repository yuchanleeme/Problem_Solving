#include <bits/stdc++.h>
using namespace std;
//https://programmers.co.kr/learn/courses/30/lessons/42898

/*
<등굣길>
주요: DP
1. puddles 좌표를 borad에 1로 등록한다.
2. dp[x][y] = dp[x-1][y] + dp[x][y-1] (단, 해당 위치의 board값이 1이 아닐 때)
3. 계산 할 때마다 나머지 계산을 해준다.
4. 최종 dp[m][n]을 리턴한다.

*/

int dp[110][110];
int board[110][110];
int solution(int m, int n, vector<vector<int>> puddles) {
    int answer = 0;
    for (int i = 0; i < puddles.size(); i++) {
        board[puddles[i][0]][puddles[i][1]] = 1;
    }

    dp[1][1] = 1;
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (board[i - 1][j] != 1) dp[i][j] += dp[i - 1][j];
            dp[i][j] %= 1000000007;

            if (board[i][j - 1] != 1) dp[i][j] += dp[i][j - 1];
            dp[i][j] %= 1000000007;
        }
    }
    return dp[m][n];
}