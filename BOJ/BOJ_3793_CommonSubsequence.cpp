#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
//https://www.acmicpc.net/problem/3793

/*
<Common Subsequence>
주요: LCS, 입출력
1. LCS 알고리즘을 이용하여 푼다.
2. cin.eof()를 이용해 파일의 입력의 끝나면 알고리즘을 종료한다.

*/

vector<vector<int> > dp;

int main() {

  while (true) {
    string s, t;
    cin >> s >> t;

    if(cin.eof() == true){ break;}

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

    cout << dp[ss][tt] << '\n';

  }
  return 0;
}
