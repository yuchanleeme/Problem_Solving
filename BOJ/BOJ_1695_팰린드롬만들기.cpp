#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
//https://www.acmicpc.net/problem/1695

/*
<팰린드롬 만들기>
주요: DP, LCS
1. 앞에서 보나 뒤에서 보나 값이 같은 수열을 팰린드롬이라고 한다.
2. 따라서 기존 수열과 뒤에서 입력된 reverse 수열의 LCS를 구하면 해당 부분의 수열을 구할 수 있다.
3. 기존의 수열의 길이에서 구한 LCS의 수열의 크기를 뺀 개수 만큼만 끼워넣으면 전체적으로 팰린드롬이 완성된다.
  => N - dp[N][N]

*/

vector<vector<int> > dp;
int main() {

  int N;
  vector<int> seq;
  vector<int> r_seq;
  cin >> N;
  for (int i = 0; i < N; i++) {
    int input;
    cin >> input;
    seq.push_back(input);
    r_seq.push_back(input);
  }

  reverse(r_seq.begin(),r_seq.end());
  dp = vector<vector<int> >(N+1, vector<int>(N+1, 0));

  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= N; j++) {
      if(seq[i-1] == r_seq[j-1]){
        dp[i][j] = dp[i-1][j-1] + 1;
      }
      else{
        dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
      }
    }
  }

  cout << N - dp[N][N];

  return 0;
}
