#include <bits/stdc++.h>
using namespace std;
//https://www.acmicpc.net/problem/2616

/*
<소형기관차>
주요: DP
1. DP[X][N] = X개의 기관차를 이용해 1~N번째의 객차까지 끌었을 때의 최댓값
  ex) DP[2][6] : 2개의 기관차를 이용해 1~6번까지의 객차를 끌었을 때 최댓값
2. sum[N] = 기관차가 N번부터 객차를 연결해 운송할 때 운송할 수 있는 최대 손님의 수
3. 점화식
  3.1 DP[1][N] = max(DP[1][N-1], sum[N])
  3.2 DP[2][N] = max(DP[2][N-1], DP[1][N-maxTrain] + sum[N])
  3.3 DP[3][N] = max(DP[3][N-1], DP[2][N-maxTrain] + sum[N])
4. DP[3][N] 을 출력한다. (3개의 기관차로 1~N번까지의 객체를 끌었을 때 최댓값)

*/

int N, maxTrain;
int train[50101];
int sum[50101];
int dp[5][50101];

int main(int argc, char const *argv[]) {

  cin >> N;
  for (int i = 1; i <= N; i++) {
    cin >> train[i];
  }
  cin >> maxTrain;

  // 초기항 설정
  int temp = 0;
  for (int i = 1; i <= maxTrain; i++) {
    temp += train[i];
  }
  dp[1][1] = temp;

  // 기관차 1개로 객차를 끌 때, sum 배열 초기화
  for (int i = 2; i <= N; i++) {
    temp -= train[i-1];
    if(i + maxTrain-1 <= N) temp += train[i+maxTrain-1];
    sum[i] = temp;
    dp[1][i] = max(dp[1][i-1], sum[i]);
  }

  // 기관차 2개로 객차를 끌 때
  for (int y = 1+maxTrain; y <= N; y++) {
    dp[2][y] = max(dp[2][y-1], dp[1][y-maxTrain] + sum[y]);
  }

  // 기관차 3개로 객차를 끌 때
  for (int y = 1+maxTrain*2; y <= N; y++) {
    dp[3][y] = max(dp[3][y-1], dp[2][y-maxTrain] + sum[y]);
  }

  // 기관차 3개로 N개의 객차를 끌 때의 최댓값
  cout << dp[3][N];

  return 0;
}
