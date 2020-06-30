#include <iostream>
#include <vector>
using namespace std;
//https://www.acmicpc.net/problem/11057

/*
<오르막 수>
주요: DP
1. DP[i][j] = i자리 수일 때, 끝자리가 j인 것의 개수
2. 오르막 수가 되려면 이전 자리수가 자신보다 작거나 같으면 된다.
  ex) dp[4][7] = dp[3][0] + dp[3][1] ... + dp[3][7]
3. DP 배열에서 마지막 N행의 값은 다 더해준 뒤 10007로 나눠주고 그 값을 출력한다.

*/

const int R = 10007;
int dp[1010][11];

int main() {

  int N;
  cin >> N;

  dp[0][0] = 1; // 초기 변수 설정
  int res = 0;
  for (int i = 1; i <= N; i++) {
    int sum_val = 0;
    for (int j = 0; j <= 9; j++) {
      sum_val += dp[i-1][j];
      dp[i][j] = sum_val % R;
      if(i == N) res += dp[i][j];
    }
  }

  cout << res % R;

  return 0;
}
