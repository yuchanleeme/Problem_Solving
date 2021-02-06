#include <bits/stdc++.h>
using namespace std;
// https://www.acmicpc.net/problem/9184

/*
<신나는 함수 실행>
주요: DP
1. DP의 메모제이션을 활용한다.
2. 나머지는 주어진 조건처럼 구현한다.
3. -1 -1 -1 입력이 주어질 때까지 입력받는다.

*/

int dp[52][52][52];

int w(int a, int b, int c){
  if(a <= 0 || b <= 0 || c <= 0) return 1;
  if(a > 20 || b > 20 || c > 20) return w(20,20,20);
  if(dp[a][b][c]) return dp[a][b][c];

  if(a < b && b < c){
    return dp[a][b][c] = w(a, b, c-1) + w(a, b-1, c-1) - w(a, b-1, c);
  }
  else{
    return dp[a][b][c] = w(a-1, b, c) + w(a-1, b-1, c) + w(a-1, b, c-1) - w(a-1, b-1, c-1);
  }
}

int main(){
  int a, b, c;
  while (true) {
    scanf("%d %d %d", &a, &b, &c);
    if(a == -1 && b == -1 && c== -1) break;
    printf("w(%d, %d, %d) = %d\n", a, b, c, w(a,b,c));
  }
  return 0;
}
