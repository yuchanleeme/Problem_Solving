#include <bits/stdc++.h>
using namespace std;
//https://programmers.co.kr/learn/courses/30/lessons/12913

/*
<땅따먹기>
주요: DP
1. DP[x][y] = max(DP[x-1][0~3]) + land[x][y]
2. 자신 기준 이전 배열에서 제일 큰 값을 가져오면 되는것이다.
3. 이를 위해서 처음에 land 첫 줄을 DP로 초기화 시켜준다.
  => DP[0][X] = land[0][X] (X : 0~3)
4. 최종적으로 DP[land.size()-1][0~3] 중 최댓값을 리턴한다.

*/

int solution(vector<vector<int> > land){
  int dp[101010][5] = {0, };
  int answer = 0;
  for (int i = 0; i < 4; i++) {
    dp[0][i] = land[0][i];
    answer = max(answer, dp[0][i]);
  }

  for (int i = 1; i < land.size(); i++) {
    for (int j = 0; j < 4; j++) {
      int temp = 0;
      for (int k = 0; k < 4; k++) {
        if(k != j)  temp = max(temp, dp[i-1][k]);
      }
      dp[i][j] = temp + land[i][j];
    }
  }

  for (int i = 0; i < 4; i++) {
    answer = max(answer, dp[land.size()-1][i]);
  }
  return answer;
}
