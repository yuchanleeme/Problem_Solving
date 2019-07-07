#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
//https://www.acmicpc.net/problem/2156

/*
<포도주 시식>
주요: DP
1. 마지막 순서의 포도주를 먹었을때와 먹지 않았을때의 최댓값을 비교한다.
2-1. 마지막 포도주를 먹었을때 -> 2칸전의 포도주를 먹은 값과 2칸전에 포도주를 안먹고 1칸전에 먹었을 때 값 비교
2-2. 마지막 포도주를 먹지 않았을때 -> 1칸 전의 최댓값
3. 2-1,2-2의 최댓값을 구한다.

*/

int main() {

  int N, M;
  cin >> N;

  vector<vector<int> > dp(N+1, vector<int>(2,0)); // dp[N][0] 먹고, dp[N][1] 안먹고
  vector<int> grape;

  for (int i = 0; i < N; i++) {
    cin >> M;
    grape.push_back(M);
  }
  dp[0][0] = grape[0];

  dp[1][0] = grape[0] + grape[1];
  dp[1][1] = dp[0][0];

  // 2번
  for (int i = 2; i < N; i++) {
    dp[i][0] = max(dp[i-2][0], dp[i-2][1] + grape[i-1]) + grape[i];
    dp[i][1] = max(dp[i-1][0], dp[i-1][1]);
  }

  // 3번
  cout << max(dp[N-1][0], dp[N-1][1]) << endl;

  return 0;
}
