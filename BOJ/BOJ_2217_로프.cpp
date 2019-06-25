#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// https://www.acmicpc.net/problem/2217

/*
<로프>
주요: 그리디 알고리즘
1. 값을 입력받고 입력값들을 오름차순 정렬을 한다.
2. 자신보다 큰 로프들은 모두 자신의 중량만큼 들 수 있다.
  => 따라서 (자신의 중량 * 남은 로프 수) 중 가장 큰값을 비교하면 된다.
  ex) 5개 로프 -> 1번 * 5(1,2,3,4,5) , 2번 *4(2,3,4,5) ..... 5번 *1(5)

*/

int main() {

  int N, val, ans;
  vector<int> rope;

  cin >> N;

  for (int i = 0; i < N; i++) {
    cin >> val;
    rope.push_back(val);
  }

  // 1번
  sort(rope.begin(),rope.end());

  // 2번
  ans = rope[N-1];
  for (int i = 0; i < N; i++) {
    ans = max(ans, rope[i] * (N-i));
  }

  cout << ans;

  return 0;
}
