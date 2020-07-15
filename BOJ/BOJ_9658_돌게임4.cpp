#include <iostream>
using namespace std;
//https://www.acmicpc.net/problem/9658

/*
<돌 게임 4>
주요: DP
1. DP[x] = 돌 X개 있을 때 이기는 사람의 번호
2. 초기항을 계산한다. (1~4 까지 이기는 사람 찾기)
  => 단, 시작하는 사람이 이기면 1, 두번째 사람이 이기면 2로 한다.
3. ex) 8 개의 돌이 있는 상황이라면,
  => SK 1개 집으면 나머지 7개 ... 7개 남았을 때 두번째 사람이 이겼었다면 SK가 이긴다.
  => SK 3개 집으면 나머지 5개 ... DP[5] = 2 이면 SK가 이긴다.
  => SK 4개도 마찬가지
4. 위와 같은 방식으로 DP값을 갱신한다.
5. DP[N]이 2면 CY, 1이면 SK를 출력한다.
===========
* 베스킨라빈스31 돌멩이 버전
* 돌 게임 3과 비슷한 알고리즘이지만 초기항이 다르다.

*/

int N;
int dp[1010] = {0, 2, 1, 2, 1, };
int main() {

  for (int i = 5; i < 1005; i++) {
    if(dp[i-1] == 2 || dp[i-3] == 2 || dp[i-4] == 2) dp[i] = 1;
    else dp[i] = 2;
  }

  cin >> N;
  if(dp[N] == 2) cout << "CY";
  else cout << "SK";

  return 0;
}
