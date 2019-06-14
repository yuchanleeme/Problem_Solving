#include <iostream>
#include <algorithm>
using namespace std;
//https://www.acmicpc.net/problem/1932

/*
<정수 삼각형>
주요: dp를 활용하자.
1. 마지막으로 선택하는 값이 무엇인지 생각하는 것이 좋다.
2. 마지막으로 선택한 값 바로 이전 값이 될 수 있는 값은 최대 2개밖에 없다.
3. 그 이전값들 중 큰 값과 자신의 값을 더해준것이 그 값을 선택했을때 최댓값인 것이다.
  => dp[i][j] = max(dp[i-1][j-1], dp[i-1][j]) + tri[i][j];
4. 단, 삼각형에서 한 줄의 첫번째 값과 마지막값은 경로가 정해져있으므로 따로 처리해 준다.
5. 저장된 dp[n-1][?] 값들 중에 최댓값을 출력하면 된다.

*/

int tri[510][510], dp[510][510];
int main() {

  int n, res = 0;
  cin >> n;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j <= i; j++) {
      cin >> tri[i][j];
    }
  }

  // 2번
  dp[0][0] = tri[0][0];
  for (int i = 1; i < n; i++) {
    for (int j = 0; j <= i; j++) {
      if(j == 0) { dp[i][0] = dp[i-1][0] + tri[i][0];} // 4번
      else if(j == i) { dp[i][j] = dp[i-1][j-1] + tri[i][j];} // 4번
      else { dp[i][j] = max(dp[i-1][j-1], dp[i-1][j]) + tri[i][j];} // 3번
    }
  }

  // 5번
  for (int k = 0; k < n; k++) {
    res = max(res, dp[n-1][k]);
  }

  cout << res;

  return 0;

}
