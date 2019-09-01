#include <iostream>
#include <vector>
using namespace std;
//https://www.acmicpc.net/problem/1010

/*
<다리 놓기>
주요: 수학, 조합
1.

=========
* 조합으로 구현하니 오버플로우가 났다.

*/

int main() {

  int T;
  cin >> T;

  for (int testcase = 0; testcase < T; testcase++) {
    unsigned long long N, M, ans, a = 1, b = 1;

    cin >> N >> M;

    for (int i = 0; i < N; i++) {
      a *= M--;
      b *= (i+1);
    }

    cout << a / b << endl;

  }

  return 0;
}
