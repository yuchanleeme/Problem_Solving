#include <iostream>
#include <vector>
#include <cstring>
#include <stack>
using namespace std;
//https://www.acmicpc.net/problem/9252

/*
<LCS 2>
주요: LCS, 역추적
1. LCS 알고리즘을 그대로 이용하면서 값이 갱신 되면 그 이전 위치를 prv에 저장한다.
2. prv에는 이전 idx의 위치 값이 저장되어있다.
3. (int)s1.size()-1, (int)s2.size()-1 의 위치부터 시작하여 역추적한다.
  => 문자열이 앞에서부터 출력되어야 하므로 stack을 이용한다.

*/

int dp[1001][1001];
pair<int, int> prv[1001][1001];

int main() {

  string s1, s2;
  cin >> s1 >> s2;

  s1 = " " + s1;
  s2 = " " + s2;

  for (int i = 1; i < s1.size(); i++) {
    for (int j = 1; j < s2.size(); j++) {
      if(s1[i] == s2[j]){
        dp[i][j] = dp[i-1][j-1] + 1;
        prv[i][j] = make_pair(i-1, j-1);
      }
      else{
        if(dp[i-1][j] < dp[i][j-1]){
          dp[i][j] = dp[i][j-1];
          prv[i][j] = make_pair(i, j-1);
        }
        else{
          dp[i][j] = dp[i-1][j];
          prv[i][j] = make_pair(i-1, j);
        }
      }
    }
  }

  cout << dp[s1.size()-1][s2.size()-1] << '\n';

  stack<char> stk;

  pair<int, int> cur((int)s1.size()-1, (int)s2.size()-1);

  while (cur.first != 0 && cur.second != 0) {
    auto tmp = prv[cur.first][cur.second];

    if(tmp.first + 1 == cur.first && tmp.second + 1 == cur.second){
      stk.push(s1[cur.first]);
    }
    cur.first = tmp.first;
    cur.second = tmp.second;
  }

  while(!stk.empty()){
    cout << stk.top();
    stk.pop();
  }

  return 0;
}
