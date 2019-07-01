#include <iostream>
#include <vector>
using namespace std;
//https://www.acmicpc.net/problem/10844

/*
<쉬운 계단 수>
주요: DP, mod
1. 이전 자리 숫자가 무엇인지에 따라 다음에 올 값이 자동으로 정해진다.
  1-1) 0 일때 : 다음 숫자는 무조건 1
  1-2) 9 일때 : 다음 숫자는 무조건 8
  1-3) 나머지 : +- 1씩 해당하는 숫자
2. (A + B) % R = (A % R) + (B % R)

*/

const int R = 1000000000;

int main() {

  int N, sum = 0;
  vector<vector<int> > dp(110, vector<int>(10, 0));

  // 초기값
  for (int first = 1; first <= 9; first++) {
    dp[1][first] = 1;
  }

  cin >> N;

  // 1번
  for (int line = 2; line <= N; line++) {
    for (int num = 0; num <= 9; num++) {
      if(num == 0){
        dp[line][num] = dp[line-1][1] % R;
      }
      else if(num == 9){
        dp[line][num] = dp[line-1][8] % R;
      }
      else{
        dp[line][num] = (dp[line-1][num-1] + dp[line-1][num+1]) % R;
      }
    }
  }

  // 2번
  for (int i = 0; i < 10; i++) {
    sum += dp[N][i];
    sum %= R;
  }
  cout << sum;

  return 0;
}
