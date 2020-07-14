#include <iostream>
using namespace std;
// https://www.acmicpc.net/problem/15989

/*
<1,2,3 더하기 4>
주요 : DP
1. 1,2,3 까지의 값은 미리 만든다. (초기항)
2. DP[x][y] = X를 만들었을 때 마지막 숫자가 y인 r개수 단(y = 1,2,3)
  => 감소하는 순서의 조합으로 만들게 한다. 32, 311, 221, 2111 ... 이런식으로
  => 이렇게 하면 중복을 피할 수 있다.
3. 입력받은 결과를 출력한다.

*/

int N;
int dp[10101][4];
int main() {
  dp[1][1] = 1;
  dp[2][1] = 1;
  dp[2][2] = 1;
  dp[3][1] = 2;
  dp[3][3] = 1;

  for (int i = 4; i <= 10101; i++) {
    dp[i][3] = dp[i-3][3];
    dp[i][2] = dp[i-2][2] + dp[i-2][3];
    dp[i][1] = dp[i-1][1] + dp[i-1][2] + dp[i-1][3];
  }

  cin >> N;
  for (int i = 0; i < N; i++) {
    int input;
    cin >> input;
    cout << dp[input][1] + dp[input][2]+ dp[input][3] << "\n";
  }

  return 0;
}
