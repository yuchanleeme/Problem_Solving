#include <iostream>
#include <vector>
using namespace std;
//https://www.acmicpc.net/problem/1912

/*
<연속합>
주요: DP
1. DP[i] = i번째 수열까지 합쳤을때의 최대 연속합
  => dp[i] = max(seq[i], dp[i-1] + seq[i])
  => 이전합과 수열을 더한값과 그냥 이 수열 자체의 값만 비교해 큰 값을 저장
2. dp 초기변수는 0번째 idx는 0, 나머지는 -10^9로 여유있게 선언했다.
3. dp값 중 최대값을 찾아서 출력

*/

int N;
const int INF = -1e9;
vector<int> seq;
vector<int> dp;
int main() {

  cin >> N;
  dp = vector<int>(N+1, INF);
  seq.push_back(0);
  for (int i = 0; i < N; i++) {
    int temp;
    cin >> temp;
    seq.push_back(temp);
  }

  int res = INF;
  for (int i = 1; i <= N; i++) {
    dp[i] = max(seq[i], dp[i-1] + seq[i]);  // 1,2번
    res = max(res, dp[i]);
  }

  // 3번
  cout << res;
  
  return 0;
}
