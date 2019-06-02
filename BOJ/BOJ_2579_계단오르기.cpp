#include <iostream>
#include <algorithm>
using namespace std;
//https://www.acmicpc.net/problem/2579

/*
<계단 오르기>
주요: DP의 성질을 이용한다.
1. 첫 번째 조건을 잘 살펴보면 계단은 1칸 이나 2칸만 이동이 가능하다.
2. 세 번째 조건에 따라 마지막 계단은 무조건 밟아야 한다.
    => 마지막 바로 이전 계단은 1칸 또는 2칸 아래 계단이어야만 한다.
3. 각 계단(N)까지의 최댓값을 dp[N], 각 계단의 점수를 stiar[N] 이라 하면 dp[N]이 될 수 있는 값은
    => 1. dp[N-1] + score[N] (1칸)
    => 2. dp[N-2] + score[N] (2칸)
4. 하지만 두 번째 조건에서 연속된 세계의 계단을 못밟는다 했으므로 1번째 dp값을 수정한다.
    => score[N]부터 거슬러 가면 한칸 아래 score[N-1]그리고 score[N-3]을 밟아야 한다.
    => score[N-3]을 밟을때 까지 최댓값은 dp[N-3]이므로 1번째 dp값을 수정한다면
    => 1. dp[N-1] + score[N] -> dp[N-3] + score[N-1] + score[N] 이 된다.
==========
* 최종
  => 1. dp[N-3] + score[N-1] +score[N], 2. dp[N-2] + score[N] 값 중 큰 값이 구하려는 점수의 최댓값이다.

*/

int main() {

  int stair, score[302] = {0,};

  cin >> stair;

  for (int i = 1; i <= stair; i++) {
    cin >> score[i];
  }

  int max_one, max_two, dp[302];

  dp[0] = score[0];
  dp[1] = score[1];
  dp[2] = score[1] + score[2];

  for (int num = 3; num <= stair; num++) {
    max_one = dp[num-3] + score[num-1] + score[num];
    max_two = dp[num-2] + score[num];

    dp[num] = max(max_one,max_two);
  }

  cout << dp[stair];

  return 0;
}
