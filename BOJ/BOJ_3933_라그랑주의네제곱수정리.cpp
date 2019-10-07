#include <iostream>
#include <cmath>
using namespace std;
//https://www.acmicpc.net/problem/3933

/*
<라그랑주의 네 제곱수 정리>
주요: 4중 for문
1. 2^15 이내의 수이므로 4중 for문을 돌려도 시간초과가 나지 않는다.
2. 입력받은 N의 구성요소가 될 수 있는 최대 제곱수 값을 구한다. => (int)sqrt(N)
3. 이 값을 최대로 각 경우의수를 따지면서 차례대로 개수를 세서 출력한다.

*/

int main() {

  int N;
  while(cin >> N){
    if(N == 0){ break;}
    int res = 0;
    for (int a = (int)sqrt(N); a > 0 ; a--) {
      int tempV = N;

      if(tempV == a*a){ res++; continue;}
      else if(tempV - (a*a) > 0){ tempV -= a*a;}

      for (int b = a; b > 0; b--) {
        if(tempV == b*b){ res++; continue;}
        else if(tempV - (b*b) > 0){ tempV -= b*b;}
        else{ continue;}

        for (int c = b; c > 0; c--) {
          if(tempV == c*c){ res++; continue;}
          else if(tempV - (c*c) > 0){ tempV -= c*c;}
          else{ continue;}

          for (int d = c; d > 0; d--) {
            if(tempV == d*d){ res++; continue;}
            else{ continue;}
          }
          tempV += c*c;
        }
        tempV += b*b;
      }
    }
    cout << res << "\n";
  }

  return 0;
}
