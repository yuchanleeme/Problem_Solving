#include <bits/stdc++.h>
using namespace std;
// https://www.acmicpc.net/problem/14430

/*
<자원 캐기>
주요: DP
1. DP[x][y] = (x,y)에 도착했을 때 가장 많이 캔 자원의 수
2. 위(x-1, y)에서 (x,y)에 도착했을 때와 왼쪽(x, y-1)에서 (x,y)에 도착했을 때를 분리해서 계산한다.
3. 최종 (N-1,M-1) 지점의 값이 가장 많이 캘 수 있는 자원의 개수이다.

*/

int N, M;
int dp[310][310];

int main(){
  cin >> N >> M;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      cin >> dp[i][j];
    }
  }

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      if(i == 0 && j == 0) continue; // (0,0) 제외
      if(i == 0){
        dp[i][j] += dp[i][j-1]; // 행이 0 일 때 (왼쪽에서만 왔을 때)
      }
      else if(j == 0){
        dp[i][j] += dp[i-1][j]; // 열이 0일 때 (위에서만 왔을 때)
      }
      else{
        dp[i][j] += max(dp[i-1][j], dp[i][j-1]);
      }
    }
  }

  cout << dp[N-1][M-1];

  return 0;
}
