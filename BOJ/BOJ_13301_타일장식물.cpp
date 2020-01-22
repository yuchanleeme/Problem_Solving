#include <iostream>
#include <vector>
using namespace std;
//https://www.acmicpc.net/problem/13301

/*
<타일 장식물>
주요: DP, 피보나치
1. 정사각형의 가로,세로 길이는 피보나치 함수를 따라 증가한다.
2. 전체 도형의 둘레의 길이는 이전 도형의 둘레 길이에서 (다음 정사각형의 변의 길이) x 2 를 한 값이다.
3. 최종 dp[N-1]값을 출력한다.

*/

long long dp[81] = {4, 6, };
long long seq[81] = {1, 1, };

int main() {

  int N;
  cin >> N;

  for (int i = 2; i < N; i++) {
    seq[i] = seq[i-2] + seq[i-1];
    dp[i] = dp[i-1] + seq[i]*2;
  }

  cout << dp[N-1];

  return 0;
}
