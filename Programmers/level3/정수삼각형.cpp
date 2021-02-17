#include <bits/stdc++.h>
using namespace std;
//https://programmers.co.kr/learn/courses/30/lessons/43105

/*
<정수 삼각형>
주요: DP
1. DP[x][y] = (x,y)까지 도달 했을 때의 최대값
2. 각 idx에 맞게 분리해서 계산한다.
  2.0 dp[x][y] 초기값은 triangle[x][y]
  2.1 y == 0 : dp[x][y] += dp[x-1][y]
  2.2 y == size()-1 : dp[x][y] += dp[x-1][y-1]
  2.3 나머지 : dp[x][y] += max(dp[x-1][y-1], dp[x-1][y])
3. 마지막 라인에서의 최댓값을 리턴한다.

*/

int dp[510][510];
int solution(vector<vector<int>> triangle) {
    int answer = 0;

    dp[0][0] = triangle[0][0];
    for (int i = 1; i < triangle.size(); i++) {
        for (int j = 0; j < triangle[i].size(); j++) {
            dp[i][j] = triangle[i][j];
            if (j == 0) {
                dp[i][j] += dp[i - 1][j];
            } else if (j == triangle.size() - 1) {
                dp[i][j] += dp[i - 1][j - 1];
            } else {
                dp[i][j] += max(dp[i - 1][j - 1], dp[i - 1][j]);
            }
            if (i == triangle.size() - 1) answer = max(answer, dp[i][j]);
        }
    }

    return answer;
}