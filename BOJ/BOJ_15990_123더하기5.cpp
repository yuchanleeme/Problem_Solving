#include <iostream>
using namespace std;
// https://www.acmicpc.net/problem/15990

/*
<1,2,3 더하기 5>
주요 : DP
1. 1,2,3 까지의 값은 미리 만든다. (초기항)
2. DP[x][y] = X를 만들었을 때 마지막 숫자가 y인 개수 단(y = 1,2,3)
  => 연속 된 숫자가 나오지 않게 dp값을 더해서 갱신한다.
4. 입력받은 결과를 출력한다.
*/

int N;
int dp[101010][4];
const int R = 1000000009;
int main() {
  dp[1][1] = 1;
  dp[2][2] = 1;
  dp[3][1] = 1;
  dp[3][2] = 1;
  dp[3][3] = 1;

  for (int i = 4; i <= 100001; i++) {
    dp[i][3] = (dp[i-3][1] + dp[i-3][2])%R;
    dp[i][2] = (dp[i-2][1] + dp[i-2][3])%R;
    dp[i][1] = (dp[i-1][2] + dp[i-1][3])%R;
  }

  cin >> N;
  for (int i = 0; i < N; i++) {
    int input;
    cin >> input;
    cout << (((dp[input][1] + dp[input][2]) %R) + dp[input][3])%R << "\n";
  }

  return 0;
}
