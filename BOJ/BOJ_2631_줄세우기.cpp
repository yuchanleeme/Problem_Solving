#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
//https://www.acmicpc.net/problem/2631

/*
<줄 세우기>
주요: DP, LIS
1. 일단 제대로 줄 선 아이들만 추려내고 나머지 아이들을 하나씩 넣는 경우로 생각한다.
2. dp[i] : i번째 아이가 마지막으로 선택된 LIS
3. 답은 전체 아이의 수 - dp[i] 중 최댓값(가장 정렬 잘 된 수)

*/

int child[201];
int dp[201];

int main() {

  int N;
  cin >> N;

  for (int i = 0; i < N; i++) {
    cin >> child[i];
  }

  int res = 0;
  for (int i = 0; i < N; i++) {
    dp[i] = 1;

    for (int j = 0; j < i; j++) {
      if(child[j] < child[i]){
        dp[i] = max(dp[i], dp[j]+1);
      }
    }
    res = max(res, dp[i]);
  }
  cout << N - res;

  return 0;
}
