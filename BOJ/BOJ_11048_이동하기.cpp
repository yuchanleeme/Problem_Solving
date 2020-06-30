#include <iostream>
#include <vector>
using namespace std;
// https://www.acmicpc.net/problem/11048

/*
<이동하기>
주요: DP
1. dp[i][j] : (i,j) 위치까지 도착했을 때 가질 수 있는 사탕의 최대 개수
2. 전체 map을 순회하면서 max값의 dp를 갱신한다.
3. 마지막 도달 점(N-1, M-1)의 dp값을 출력한다.

*/
int N, M;
int map[1010][1010];
int dp[1010][1010];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> N >> M;
  for (int i = 0; i < N; i++){
    for (int j = 0; j < M; j++){
      cin >> map[i][j];
    }
  }

  dp[0][0] = map[0][0];
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      dp[i+1][j] = max(dp[i+1][j], dp[i][j] + map[i+1][j]);
      dp[i][j+1] = max(dp[i][j+1], dp[i][j] + map[i][j+1]);
      dp[i+1][j+1] = max(dp[i+1][j+1], dp[i][j] + map[i+1][j+1]);
    }
  }

  cout << dp[N-1][M-1];

	return 0;
}
