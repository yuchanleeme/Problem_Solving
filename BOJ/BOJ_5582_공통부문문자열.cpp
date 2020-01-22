#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
//https://www.acmicpc.net/problem/5582

/*
<공통 부문 문자열>
주요: DP
1. 연속된 문자열중 공통 길이를 보는것이므로 바로 이전 값에만 주목을 한다.
2. 이전 대각선 위치에 있는 값은 여기까지 연속된 공통문자열의 길이다.
3. 따라서 문자열이 같다면 그 이전 대각선 값에서 1만 더해주면 계속 길이가 갱신되는것이다.
4. dp 테이블을 만들면서 가장 큰 값을 출력한다.

*/

vector<vector<int> > dp;
int main() {

  string t, s;
  cin >> t >> s;
  int tt = t.size();
  int ss = s.size();
  dp = vector<vector<int> > (tt+1, vector<int>(ss+1, 0));

  int ans = 0;
  for (int i = 1; i <= tt; i++) {
    for (int j = 1; j <= ss; j++) {
        if(t[i-1] == s[j-1]){
          dp[i][j] = dp[i-1][j-1] + 1;
        }
        ans = max(dp[i][j], ans);
    }
  }

  cout << ans;

  return 0;
}
