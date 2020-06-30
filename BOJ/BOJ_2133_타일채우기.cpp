#include <iostream>
using namespace std;
//https://www.acmicpc.net/problem/2133

/*
<타일 채우기>
주요: DP
1. 우선 N이 홀수이면 다 채우는 경우는 불가능하다.
2. 타일 채우는 방법은 두가지가 있다.
  2-1. 두 칸당 3가지 경우의 수를 이용해 채운다.
  2-2. 3xN칸을 한 번에 채우는 2가지 경우의 수
3. 위를 이용해 점화식을 세우면
  3-1. DP[2n] = 3xDP[2(n-1)] + 2x(DP[0] + DP[2] + ... DP[2(n-2)]
  3-2. 누적 덧셈으로 구현한다.
4. 계산된 결과를 입력값에 의거해 출력한다.

*/

int N;
int dp[35];

int main() {

  cin >> N;
  dp[0] = 1, dp[2] = 3; // 편의상 초기항 설정
  if(N % 2 == 0){
    int sum_val = 0;
    for (int i = 4; i <= N; i+=2) {
      sum_val += dp[i-4]; // 누적 덧셈(시그마)
      dp[i] = 3*dp[i-2] + 2*sum_val;
    }
    cout << dp[N] << endl;
  }
  else{
    cout << 0;
  }

  return 0;
}
