#include <iostream>
#include <algorithm>
#include <set>
using namespace std;
//https://www.acmicpc.net/problem/16500

/*
<문자열 판별>
주요: DP
1. DP[X] : 문자열의 X번째까지 완성시킬 수 있는지 판단
2. set을 활용하여 A에대한 자료구조를 만든다.
3. 문자열을 철자 단위로 탐색한다.
  => 현재위치(i) 이전까지 완성이 가능하다면(dp[i-1]) 나머지 문자열이 가능한지 찾기
  => 가능하지 않다면 break
  => 찾으면 dp[i+j-1] 값 1로 변경
4. 최종적으로 dp[S.length()-1]에 완성이 가능한지 결과가 저장되어 있다.

*/

int N;
string S;
set<string> A;
int dp[110];

int main() {

  cin >> S >> N;
  for (int i = 0; i < N; i++) {
    string input;
    cin >> input;
    A.insert(input);
  }

  for (int i = 0; i < S.length(); i++) {
    for (int j = 1; j <= S.length()-i; j++) {
      string comp_s = S.substr(i,j);
      if(i != 0 && dp[i-1] == 0) break;
      if(A.find(comp_s) != A.end())
        dp[i+j-1] = 1;
    }
  }
  cout << dp[S.length()-1] << endl;

  return 0;
}
