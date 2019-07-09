#include <iostream>
using namespace std;
//https://www.acmicpc.net/problem/1904

/*
<01타일>
주요: DP, mod
1. 1칸 적은 타일들에 '1' 을 붙이는 것과 2칸 적은 타일들에 '00'을 붙이는 방법이 있다.
  = > 두가지 경우를 더하면 된다.
2. mod는 덧셈에 대한 결합법칙이 성립한다.

*/
int tile[1000010] = {0,1,2, };
const int R = 15746;

int main() {

  int N;

  cin >> N;

  // 1,2번
  for (int i = 3; i <= N; i++) {
    tile[i] = (tile[i-2] + tile[i-1]) % R;
  }

  cout << tile[N];

  return 0;
}
