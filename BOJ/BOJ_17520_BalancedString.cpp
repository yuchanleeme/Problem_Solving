#include <iostream>
using namespace std;
//https://www.acmicpc.net/problem/17520

/*
<Balanced String>
주요: DP
1. dp로 2차원 배열을 만든다.
  => idx(0) : 0이 한개 더 많은 값
  => idx(1) : 1이 한개 더 많은 값
  => idx(2) : 위의 두개를 합합 값
2. 홀수,짝수를 구분하여 위에 조건에 맞게 구한다.
3. 마지막에 dp[N][2]를 출력한다.

*/

const int divNum = 16769023;

int main() {

  int N;
  cin >> N;

  int dp[N+1][3] = {0, };

  dp[1][0] = 1; // 0
  dp[1][1] = 1; // 1
  dp[1][2] = 2; // 합

  for (int i = 2; i <=N; i++) {
    if(i % 2 != 0){
      dp[i][0] = (dp[i-1][2]);
      dp[i][1] = (dp[i-1][2]);
      dp[i][2] = (dp[i][0] + dp[i][1]) % divNum;
    }
    else{
      dp[i][2] = (dp[i-1][2]);
    }
  }
  cout << dp[N][2];

  return 0;
}
