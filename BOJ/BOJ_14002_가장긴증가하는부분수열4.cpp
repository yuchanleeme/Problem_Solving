#include <iostream>
#include <vector>
#include <stack>
using namespace std;
//https://www.acmicpc.net/problem/14002

/*
<가장 긴 증가하는 부분 수열 4>
주요: LIS, 역추적
1. 기존 LIS 알고리즘을 이용하되 되추적을 위해 prv배열을 이용한다.
2. res_idx : 계산된 LIS의 마지막 idx 위치
3. 스택을 이용해 계산된 LIS 크기와 그 수열을 출력한다.

*/

int seq[1001];
int dp[1001];
int prv[1001];

int main() {

  int N;
  cin >> N;

  fill(prv, prv+N ,-1);
  for (int i = 0; i < N; i++) {
    cin >> seq[i];
  }

  int res_idx, res = 0;
  for (int i = 0; i < N; i++) {
    dp[i] = 1;
    for (int j = 0; j < i; j++) {
      if(seq[i] > seq[j]){
        if(dp[i] < dp[j] + 1){
          prv[i] = j;
          dp[i] = dp[j] + 1;
        }
      }
    }
    if(res < dp[i]){
      res = dp[i];
      res_idx = i;
    }
  }

  cout << res << '\n';

  stack<int> stk;
  while (prv[res_idx] != -1) {
    stk.push(seq[res_idx]);
    res_idx = prv[res_idx];
  }

  cout << seq[res_idx] << " ";
  while (!stk.empty()) {
    cout << stk.top() << " ";
    stk.pop();
  }

  return 0;
}
