#include <iostream>
using namespace std;
// https://www.acmicpc.net/problem/2965

/*
<캥거루 세마리>
주요: 수학
1. 가장 간격이 큰 두 캥거루 말고 다른 캥거루가 처음 점프한다.
2. 제일 가까운 캥거루 바로 옆으로 점프한다.
3. 그렇게 두 가까운 캥거루가 1칸씩 계속 점프하는게 최댓값이다.

*/

int main() {

  int A, B, C, ans;

  cin >> A >> B >> C;
  ans = max(C-B, B-A);
  cout << ans - 1;

  return 0;
}
