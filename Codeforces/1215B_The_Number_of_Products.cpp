#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
//http://codeforces.com/problemset/problem/1215/B

long long seq[2000005];
long long dp[2][2000005];
int main() {

  long long N;
  cin >> N;

  seq[0] = 0;
  for (int i = 1; i <= N; i++) {
    cin >> seq[i];
  }

  dp[0][0] = 0;
  dp[0][0] = 0;
  for (int i = 1; i <= N; i++) {
    if(seq[i] > 0){
      //positive +
      dp[0][i] = dp[0][i-1] + 1;
      dp[1][i] = dp[1][i-1];
    }
    else{
      //negative -
      dp[0][i] = dp[1][i-1];
      dp[1][i] = dp[0][i-1] + 1;
    }
  }

  long long pos = 0, neg = 0;
  for (int i = 0; i <= N; i++) {
    pos += dp[0][i];
  }
  for (int i = 0; i <= N; i++) {
    neg += dp[1][i];
  }

  cout << neg << " " << pos;

  return 0;
}
