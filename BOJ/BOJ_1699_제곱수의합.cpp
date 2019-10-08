#include <iostream>
#include <cmath>
using namespace std;
//https://www.acmicpc.net/problem/1699

/*
<제곱수의 합>
주요: 4중 for문
1. 2^15 이내의 수이므로 4중 for문을 돌려도 시간초과가 나지 않는다.
2. 입력받은 N의 구성요소가 될 수 있는 최대 제곱수 값을 구한다. => (int)sqrt(N)
3. 이 값을 최대로 각 경우의수를 따지면서 차례대로 개수를 비교해서 출력한다.
==========
* BOJ(3933) - 랑그릿사의 네 제곱수의 정리 응용

*/

int main() {

  int N;
  cin >> N;
  int ans = 5;
  for (int a = (int)sqrt(N); a > 0 ; a--) {
    int tempV = N;

    if(tempV == a*a){ ans = min(ans, 1); continue;}
    else if(tempV - (a*a) > 0){ tempV -= a*a;}

    for (int b = a; b > 0; b--) {
      if(tempV == b*b){ ans = min(ans, 2); continue;}
      else if(tempV - (b*b) > 0){ tempV -= b*b;}
      else{ continue;}

      for (int c = b; c > 0; c--) {
        if(tempV == c*c){ ans = min(ans, 3); continue;}
        else if(tempV - (c*c) > 0){ tempV -= c*c;}
        else{ continue;}

        for (int d = c; d > 0; d--) {
          if(tempV == d*d){ ans = min(ans, 4); continue;}
          else{ continue;}
        }
        tempV += c*c;
      }
      tempV += b*b;
    }
  }
  cout << ans << "\n";

  return 0;
}
