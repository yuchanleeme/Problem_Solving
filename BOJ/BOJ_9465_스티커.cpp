#include <iostream>
#include <algorithm>
using namespace std;
//https://www.acmicpc.net/problem/9465

/*
<스티커>
주요: DP를 활용하자.
1. 문제풀이의 가장 중요한 포인트는 마지막줄의 스티커 둘중 하나는 무조건 고른다는 것이다.
2. 이를 이용해 i번째까지 최대 점수를 모았을 때 그때 마지막 스티커가 위인지 아래인지 구분해 배열로 저장한다.
  => dp[i][0] : 위  | dp[i][1] : 아래
3. 즉 dp[i][0] 는 2열전 아래칸에서 위 스티커에 오던지(dp[i-2][1]), 1열전 아래칸에서 위 스티커에 오던지(dp[i-1][1]) 둘중 최댓값이 되는 것이다.
4. 마찬가지로 dp[i][1]도 3과 같은 방식으로 한다.
5. 이렇게 계산된 dp[n][0]과 dp[n][1]중 max 값을 출력하면 된다.

*/

int main() {

  int T, n;
  int sticker[100002][2] = {0, 0, };
  int dp[100002][2] = {0, 0, };
  cin >> T;

  for (int tc = 0; tc < T; tc++) {

    cin >> n;

    for (int i = 1; i <= n; i++) {
      cin >> sticker[i][0]; // 첫째 행
    }
    for (int i = 1; i <= n; i++) {
      cin >> sticker[i][1]; // 둘째 행
    }

    // 첫째 열 초기화
    dp[1][0] = sticker[1][0];
    dp[1][1] = sticker[1][1];

    // 3,4번
    for (int i = 2; i <= n; i++) {
      dp[i][0] = max(dp[i-1][1], dp[i-2][1]) + sticker[i][0];
      dp[i][1] = max(dp[i-1][0], dp[i-2][0]) + sticker[i][1];
    }

    //5번
    cout << max(dp[n][0], dp[n][1]) << endl;

  }

  return 0;
}
