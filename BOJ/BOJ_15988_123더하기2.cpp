#include <iostream>
using namespace std;
// https://www.acmicpc.net/problem/15988

/*
<1,2,3 더하기 2>
주요 : DP
1. 1,2,3 까지의 값은 미리 만든다. (초기항)
2. 자기보다 1,2,3 만큼 작은 dp값을 가져와 다 더해준다.
3. 중간 중간 모듈러 계산을 해준다.
4. 입력받은 결과를 출력한다.
*/

int dp[10101010] = {0, 1, 2, 4, };
const int R = 1000000009;
int main() {
  for (int i = 4; i <= 1e7; i++){
    dp[i] = ((dp[i-1] + dp[i-2])%R + dp[i-3])%R;
  }

  int N, T;
  cin >> T;
  for (int testcase = 0; testcase < T; testcase++) {
    cin >> N;
    cout << dp[N] << "\n";
  }
  return 0;
}
