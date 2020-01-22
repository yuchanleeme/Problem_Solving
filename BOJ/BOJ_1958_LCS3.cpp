#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
//https://www.acmicpc.net/problem/1958

/*
<LCS 3>
주요: DP, LCS
1. 기존 2개의 LCS구하는 과정과 유사하다.
2. 기존 2개 LCS과 다르게 3개의 문자열을 비교해야하기 때문에 3차원 배열을 이용한다.
3. 나머지 과정은 기존 LCS와 유사한 알고리즘을 이용한다.

*/

int dp[101][101][101];

int main() {

  string s, t,u;
  cin >> s >> t >> u;
  int ss = s.size();
  int tt = t.size();
  int uu = u.size();
  for (int i = 1; i <= ss; i++) {
    for (int j = 1; j <= tt; j++) {
      for (int k = 1; k <= uu; k++) {
        if(s[i-1] == t[j-1] && s[i-1] == u[k-1]){
          dp[i][j][k] = dp[i-1][j-1][k-1] + 1;
        }
        else{
          int temp = max(dp[i-1][j][k], dp[i][j-1][k]);
          temp = max(temp, dp[i][j][k-1]);
          dp[i][j][k] = temp;
        }
      }
    }
  }

  cout << dp[ss][tt][uu];
  
  return 0;
}
