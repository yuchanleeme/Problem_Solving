#include <bits/stdc++.h>
using namespace std;
//https://www.acmicpc.net/problem/2011

/*
<암호코드>
주요: dp
1. dp[x] = x번째 자리까지 가능한 암호의 경우의 수
2. 0일때 유의사항
  2-1. 맨 앞자리가 0이면 무조건 0을 출력한다.
  2-2. 앞 2자리가 27~29 일때 dp[1] = 1
  2-3. 앞 2자리가 0으로 끝날때, 10,20 : dp[1] = 1, 나머지(30,40..): dp[1] = 0
  2-4. 이외의 경우 dp[1] = 2
3. 0이 아니라면 dp += dp[i-1]
4. 바로 이전 글자와 알파벳을 만들 수 있다면 dp[i] += dp[i-2]
5. 최종 dp[str.length()-1] 을 출력한다.
==========
* dfs로 풀었더니 시간초과가 떴다.
* 앞자리 0 주의
* stoi 앞자리 0 주의
* 나머지 처리 하는거 주의

*/

int answer;
string str;
int dp[5010];

int main(int argc, char const *argv[]) {
  cin >> str;

  if(str[0] == '0'){
    return !printf("0");
  }
  else dp[0] = 1;

  if(str[0] == '2' && str[1] >= '7'){ dp[1] = 1;}
  else if(str[0] >= '3' && str[1] == '0') dp[1] = 0;
  else if(str[1] == '0') dp[1] = 1;
  else if(str[0] >= '3' && str[1] != '0'){
    dp[1] = 1;
  }else{
    dp[1] = 2;
  }

  for (int i = 2; i < str.length(); i++) {
    if(str[i] != '0') dp[i] += dp[i-1];

    if(str[i-1] == '1'){
      dp[i] += dp[i-2];
    }
    else if(str[i-1] == '2' && str[i] >= '0' && str[i] <= '6'){
      dp[i] += dp[i-2];
    }
    dp[i] %= 1000000;
  }

  cout << dp[str.length()-1];

  return 0;
}
