#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
//https://www.acmicpc.net/problem/5502

/*
<팰린드롬>
주요: DP, LCS
1. 앞에서 보나 뒤에서 보나 값이 같은 수열을 팰린드롬이라고 한다.
2. 따라서 기존 문자열과 뒤에서 입력된 reverse 문자열의 LCS를 구하면 해당 부분의 팰린드롬 문자열을 구할 수 있다.
3. 기존의 문자열의 길이에서 구한 LCS의 문자열의 길이를 뺀 개수 만큼만 끼워넣으면 전체적으로 팰린드롬이 완성된다.
  => N - dp[N][N]

*/

vector<vector<int> > dp;
int main() {

  int N;
  string s_1;
  cin >> N;
  cin >> s_1;

  string s_2 = s_1;
  reverse(s_2.begin(),s_2.end());

  dp = vector<vector<int> >(N+1, vector<int>(N+1, 0));
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= N; j++) {
      if(s_1[i-1] == s_2[j-1]){
        dp[i][j] = dp[i-1][j-1] + 1;
      }
      else{
        dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
      }
    }
  }

  cout << N - dp[N][N];

  return 0;
}
