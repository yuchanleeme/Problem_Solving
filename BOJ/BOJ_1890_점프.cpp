#include <iostream>
using namespace std;
// https://www.acmicpc.net/problem/1890

/*
<점프>
주요: DP
1. dp[i][j] : (i,j)번째 까지 도착할 수 있는 경우의수
2. 범위를 크게 정해서 out of range 에러를 방지한다.
3. 최적화를 위해 dp값이 0일때는(방문 불가) 제외하고 계산한다.
  => 오로지 오른쪽, 아래로만 이동해서 가능한 경우임
4. map의 값이 0일때는 계산을 제외한다.(도착지이므로)
5. 최종 결과값인 dp[nN-1][N-1]을 출력한다.
==========
* 2^63-1 을 넘지 않는다 했으므로 dp 배열 long long형 선언

*/

int N;
int map[120][120];
long long dp[120][120]; // 2번

int main() {

  cin >> N;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cin >> map[i][j];
    }
  }

  dp[0][0] = 1;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      int jump = map[i][j];
      // 3,4번
      if(dp[i][j] != 0 && map[i][j] != 0){
        dp[i+jump][j] += dp[i][j];
        dp[i][j+jump] += dp[i][j];
      }
    }
  }

  cout << dp[N-1][N-1];
  return 0;
}
