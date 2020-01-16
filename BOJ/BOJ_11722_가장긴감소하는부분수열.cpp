#include <iostream>
#include <vector>
using namespace std;
//https://www.acmicpc.net/problem/11722

/*
<가장 긴 감소하는 부분 수열>
주요: DP
1. 아래 DP의 조건에 맞게 문제를 푼다.
2. 최대값을 각 i 마다 갱신해준다.
3. LIS와는 개념적으로 반대되는 경우
===========
* dp[i] : i번째 원소가 마지막인 감소 부분수열 중 최장거리
* dp[i] = max(dp[j]) + 1
(if arr[j] > arr[i], j < i)

*/

int dp[1001];
int arr[1001];

int main() {

  int N;
  cin >> N;

  for (int i = 0; i < N; i++) {
    cin >> arr[i];
  }

  int res = 0;
  for (int i = 0; i < N; i++) {
    dp[i] = 1;

    for (int j = 0; j < i; j++) {
      if(arr[j] > arr[i]){
        dp[i] = max(dp[i], dp[j]+1);
      }
    }
    res = max(res, dp[i]);
  }
  cout << res;

  return 0;
}
