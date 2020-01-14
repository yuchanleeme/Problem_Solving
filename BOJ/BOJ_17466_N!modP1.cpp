#include <iostream>
#include <vector>
using namespace std;
//https://www.acmicpc.net/problem/17466

/*
<N! mod P (1)>
주요: mod
1. (A x B) mod N = {(A mod N) x (B mod N)} mod N 임을 이용한다.
2. 차례대로 N부터 1까지 1씩 빼주면서 계산해준다.

*/

int main() {

  long long N, P;
  cin >> N >> P;

  long long ans = N % P;
  for (int i = N-1; i >= 1; i--) {
    ans *= i%P;
    ans %= P;
  }

  cout << ans;

  return 0;
}
