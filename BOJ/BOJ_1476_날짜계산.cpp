#include <bits/stdc++.h>
using namespace std;
//https://www.acmicpc.net/problem/1476

/*
<날짜 계산>
주요: 나머지, 브루트 포스
1. 각 지구, 태양, 달의 숫자의 나머지를 이용해 계산한다.
2. 기껏해야 15*28*19개의 경우의 수이므로 다 계산해서 결과를 찾는다.

*/

int a, b, c;
int main(int argc, char const *argv[]) {
  cin >> a >> b >> c;
  for (int i = 1; i <= 15*28*19; i++) {
    int x, y, z;
    x = (i-1) % 15 + 1;
    y = (i-1) % 28 + 1;
    z = (i-1) % 19 + 1;
    if(a == x && b == y && c == z) return !printf("%d",i);
  }
  return 0;
}
