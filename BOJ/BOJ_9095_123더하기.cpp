#include <iostream>
using namespace std;
// https://www.acmicpc.net/problem/9095

/*
<1,2,3 더하기>
주요 : DP
1. 1,2,3 까지의 값은 미리 만든다. (초기항)
2. 자기보다 1,2,3 만큼 작은 dp값을 가져와 다 더해준다.
*/

int dp[15] = {0, 1, 2, 4, };
int main() {

  for (int i = 4; i <= 11; i++)
    dp[i] = dp[i-1] + dp[i-2] + dp[i-3];

  int N, T;
  cin >> T;
  for (int testcase = 0; testcase < T; testcase++) {
    cin >> N;
    cout << dp[N] << "\n";
  }
  return 0;
}
