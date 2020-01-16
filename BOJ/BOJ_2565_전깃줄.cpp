#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
//https://www.acmicpc.net/problem/11722

/*
<전깃줄>
주요: DP
1. A 전깃줄의 번호 순대로 연결된 B 전깃줄의 번호를 나열한다.
2. 이 수들을 가지고 DP를 이용해 문제를 푼다.
3. LIS임을 인지 한다.
===========
* dp[i] : i번째 전깃줄이 마지막으로 선택된 증가 부분수열 중 최장거리

*/

int line[501];
int dp[501];

int main() {

  int N;
  cin >> N;

  for (int i = 0; i < N; i++) {
    int inputX, inputY;
    cin >> inputX >> inputY;
    line[inputX] = inputY;
  }

  vector<int> seq;
  for (int i = 1; i < 501; i++) {
    if(line[i] != 0){ seq.push_back(line[i]);}
  }

  int res = 0;
  for (int i = 0; i < N; i++) {
    dp[i] = 1;

    for (int j = 0; j < i; j++) {
      if(seq[j] < seq[i]){
        dp[i] = max(dp[i], dp[j]+1);
      }
    }
    res = max(res, dp[i]);
  }
  cout << N - res;

  return 0;
}
