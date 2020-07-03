#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
//https://www.acmicpc.net/problem/16194

/*
<카드 구매하기 2>
주요:
1. dp[x] = X개를 구매 했을 때의 최솟 값 (초기항 dp[i] = card[i])
2. dp[i] = min(dp[1] + dp[i-1], dp[2]+ dp[i-3], ... dp[i/2] + dp[i-i/2], card[i])
3. 하나씩 뺀 값과 비교해보면서 dp 값 갱신

*/

int N;
int card[1010];
int dp[1010];

int main() {

  cin >> N;
  for (int i = 1; i <= N; i++) {
    cin >> card[i];
    dp[i] = card[i];
  }

  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= i/2; j++) {
      dp[i] = min(dp[i], dp[j] + dp[i-j]);
    }
  }
  cout << dp[N];
  return 0;
}
