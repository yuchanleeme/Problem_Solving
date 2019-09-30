#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
//https://www.acmicpc.net/problem/11651

/*
<좌표 정렬하기2>
주요: pair, sort
1. pair로 x, y의 값들을 반대로 벡터에 넣는다.
2. 위쪽으로 향하는 방향으로 출력해야 한다.
  => y를 기준으로 먼저 정렬해야 한다.
2. sort함수로 정렬한 후 출력한다.

*/

int main() {

  vector<pair<int, int> > dot;

  int N;

  cin >> N;

  for (int i = 0; i < N; i++) {
    int x, y;
    cin >> x >> y;
    dot.push_back({y,x});
  }
  sort(dot.begin(),dot.end());

  for (int i = 0; i < N; i++) {
    cout << dot[i].second << " " << dot[i].first << "\n";
  }
  return 0;
}
