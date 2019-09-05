#include <iostream>
using namespace std;
//https://www.acmicpc.net/problem/1010

/*
<다리 놓기>
주요: 수학, 조합, DP
1. 조합을 구현하는 문제이다.
2. M개의 사이트 중에 N개를 고르면 되는 문제이다.
  => 동쪽의 사이트를 위에서부터 차례대로 고른다고 하면 다리끼리 서로 겹쳐지지 않는다.
3. mCc 을 dp[m][n]이라 생각하고 이를 구한다고 생각하자. (파스칼의 삼각형)
  => dp[m][n] = dp[m-1][n-1] + dp[m-1][n-2] + .... + dp[m-1][1]
  => dp[m][n] = dp[m-1][n-1] + dp[m-1][n]
  => 파스칼의 삼각형을 구현하면 된다.

=========
* 조합공식 으로 구현하니 오버플로우가 났다.
* 백트래킹으로 개수만 세주었다. => 시간초과가 났다.
* 파스칼의 삼각형을 이용해 조합을 풀었다.

*/

int main() {

  int T;
  cin >> T;

  for (int testcase = 0; testcase < T; testcase++) {

    int N, M, ans = 0;
    int dp[31][31] = {0, };
    cin >> N >> M;

    for (int i = 0; i < 30; i++) {
      for (int j = 0; j < 30; j++) {
        if(j == 0 || i == j){
          dp[i][j] = 1;
        }
        else if(i > j){
          dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
        }
      }
    }
    cout << dp[M][N] << endl;
  }

  return 0;
}
