#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
//https://www.acmicpc.net/problem/9251

/*
<LCS>
주요: DP, LCS
1. DP[X][Y] = s_1의 X번째까지의 문자열과 s_2의 Y번째까지의 문자열중의 최장 공통 부분 문자열
2. 만약 문자열이 같다면 이전 대각선에서 값을 받아와 1을 더해준다.
3. 만약 문자열이 다르다면 위,왼쪽 dp테이블에서 최대값을 가져온다.
4. 위의 과정 때문에 dp 테이블의 idx는 0부터 시작, 문자열의 idx는 1부터 시작한다.

*/

vector<vector<int> > dp;

int main() {

  string s, t;
  cin >> s >> t;
  int ss = s.size();
  int tt = t.size();
  dp = vector<vector<int> >(ss+1, vector<int>(tt+1, 0));
  for (int i = 1; i <= ss; i++) {
    for (int j = 1; j <= tt; j++) {
      if(s[i-1] == t[j-1]){
        dp[i][j] = dp[i-1][j-1] + 1;
      }
      else{
        dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
      }
    }
  }

  cout << dp[ss][tt];
  
  return 0;
}
