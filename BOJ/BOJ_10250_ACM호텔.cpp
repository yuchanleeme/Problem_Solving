#include <iostream>
using namespace std;
//https://www.acmicpc.net/problem/1712

/*
<ACM 호텔>
주요: 계산
1. room번호는 나머지가 0 이면 N/H 이고 아니면 1 추가한다.
2. floor층수는  N - H*(room-1)가 0 이면 너비값 아니면 바로 그값이다.
3. 나머지가 0 일때만 주의하면 된다.

*/

int main() {
  // freopen("1aa.txt", "r", stdin);
  int T, H, W, N, floor, room;

  cin >> T;

  for (int testcase = 0; testcase < T; testcase++) {

    cin >> H >> W >> N;

    room = N % H == 0 ? (N / H) : (N / H + 1);
    floor = N - H*(room-1) == 0 ? W : N - H*(room-1);

    cout << floor * 100 + room << endl;

  }

  return 0;
}
