#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
//https://www.acmicpc.net/problem/1965

/*
<줄 세우기>
주요: DP, LIS
1. 상자의 크기가 큰 방향으로 선택이 가능하다.
  => 즉, LIS 와 같은 문제
2. dp[i] : i번째 크기의 상자가 마지막으로 선택된 LIS
3. 최대의 상자의 개수를 출력한다.

*/

int box[1001];
int dp[1001];

int main() {

  int N;
  cin >> N;

  for (int i = 0; i < N; i++) {
    cin >> box[i];
  }

  int res = 0;
  for (int i = 0; i < N; i++) {
    dp[i] = 1;

    for (int j = 0; j < i; j++) {
      if(box[j] < box[i]){
        dp[i] = max(dp[i], dp[j]+1);
      }
    }
    res = max(res, dp[i]);
  }
  cout << res;

  return 0;
}
