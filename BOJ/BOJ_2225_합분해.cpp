#include <iostream>
#include <vector>
using namespace std;
//https://www.acmicpc.net/problem/2225

/*
<합분해>
주요: DP
1. DP[i][j] : 정수 i개를 이용하여 j의 값을 만드는 경우의 수
2. 초기항을 1로 다 초기화 한다.
3. DP[i][j] = sum(dp[i-1][j](0<= j <= N))
4. dp에 저장될 때 나머지 계산을 해준다.
*/

const int R = 1e9;
int dp[210][210] = {0, };

int main() {

  int N, K;
  cin >> N >> K;

  for(int i = 0; i <= N; i++)
    dp[1][i] = 1;

  for (int i = 2; i <= K; i++) {
    long long sum_val = 0;
    for (int j = 0; j <= N; j++) {
      sum_val += dp[i-1][j];
      dp[i][j] = sum_val % R;
    }
  }

  cout << dp[K][N];
  return 0;
}
