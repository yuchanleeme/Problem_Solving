#include <iostream>
using namespace std;
//https://www.acmicpc.net/problem/14501

/*
<퇴사>
주요: DP
1. DP[x] : x번째날 상담을 했을때 까지의 최대한 많이 받은 상담 수익
2. 초기항은 입력을 받으면서 진행한다. (상담 기간이 퇴사한 후까지면 제외)
3. 퇴사하기 전까지 가능한 상담을 기준으로 dp 값을 갱신한다.
4. dp[i] = dp[i], day[i][1] + max(dp[0], dp[1], dp[2] ... dp[i])
==========
* 조건을 빼먹지 말고 코딩할 것
* 중복되는 부분은 함수로 구현해도 좋을 것 같다.

*/
int N;
int day[20][2];
int dp[20];

int main() {
  cin >> N;
  for (int i = 1; i <= N; i++) {
    cin >> day[i][0] >> day[i][1];
    int out = N-i+1;
    if(out >= day[i][0]) dp[i] = day[i][1];
  }

  int res = dp[1];
  for (int i = 2; i <= N; i++) {
    for (int j = 1; j <= i; j++) {
      int gap = i-j;
      int out = N-i+1;
      if(gap >= day[j][0] && out >= day[i][0]){
        dp[i] = max(dp[i], dp[j]+day[i][1]);
      }
    }
    res = max(res, dp[i]);
  }
  cout << res;
  return 0;
}
