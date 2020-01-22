#include <iostream>
#include <vector>
using namespace std;
//https://www.acmicpc.net/problem/12852

/*
<1로만들기 2>
주요: DP, 역추적
1. 기존 1로만들기의 알고리즘은 그대로 이용한다. (BOJ_1463_1로만들기)
2. 값을 갱신하면서 이전 idx위치의 값을 prv에 저장한다.
3. 입력받은 N부터 1이 될때까지 prv 배열을 이용해 값을 출력한다.

*/

const int INF = 1e6 + 1;
int dp[INF];
int prv[INF];

int main() {

  int N;
  cin >> N;
  fill(dp, dp+INF, INF);
  dp[1] = 0;

  int cnt = 2;
  while(cnt < N+1){
    int a = INF, b = INF, c= INF;

    if(cnt % 3 == 0){
      a = dp[cnt/3];
    }

    if(cnt % 2 == 0){
      b = dp[cnt/2];
    }

    c = dp[cnt-1];

    if(a < b){
      if(c < a){
        dp[cnt] = c + 1;
        prv[cnt] = cnt-1;
      }
      else{
        dp[cnt] = a + 1;
        prv[cnt] = cnt/3;
      }
    }
    else{
      if(c < b){
        dp[cnt] = c + 1;
        prv[cnt] = cnt-1;
      }
      else{
        dp[cnt] = b + 1;
        prv[cnt] = cnt/2;
      }
    }
    cnt++;
  }

  cout << dp[N] << '\n';
  int idx = N;
  while (idx >= 1) {
    cout << idx << " ";
    idx = prv[idx];
  }

  return 0;
}
