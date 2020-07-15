#include <iostream>
using namespace std;
//https://www.acmicpc.net/problem/11058

/*
<크리보드>
주요: DP
1. DP[N] = 크리보드 N 번 입력할 시 최댓값이다.
2. 한번 클립보드에 복사하는것을 진행했으면 이후에 계속 붙여넣기를 하는것이 최대를 갖게한다.
3. 규칙을 찾아본다.  EX) N이 7일때 DP[7] 후보는
  2-1) DP[6]+1 : DP[6] + A
  2-2) DP[4] + CA + CC + CV
  2-3) DP[3] + CA + CC + CV + CV
  2-4) DP[2] + CA + CC + CV + CV + CV
  .
  .
4. 위와 같은 규칙을 찾고 그대로 구현하여 최대값을 찾아 출력한다.
==========
* 나중에 찾아보니까 모든 항을 조사할 필요는 없었다.
  => 시간복잡도가 O(N)이고, N이 100밖에 안 돼서 이렇게 짰다.
  => 최적화 방법을 좀 더 고민해 보는 습관을 들이자.
*/

int N;
long long dp[110] = {0, 1, 2, 3,};
int main() {

  cin >> N;

  for (int i = 4; i <= N; i++) {
    int idx = i-2; // 최대 idx (CV 횟수)
    for (int j = 1; j <= N-3; j++) {
      dp[i] = max(dp[i], dp[j] * idx--);
    }
    dp[i] = max(dp[i-1]+1, dp[i]);
  }
  cout << dp[N];

  return 0;
}
