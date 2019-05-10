#include <stdio.h>
// https://www.acmicpc.net/problem/1004

/*
<어린 왕자>
주요: 두 점이 어떤 위치에 있는지를 파악한다.
1. 두 점과 원의 위치관계에 따라 횟수를 증가해 나간다.
2. 두 점이 둘 다 원 안/밖에 있을 때 : 진입/이탈 X
3. 두 점이 원을 경계로 안/밖에 있을 때 : 진입/이탈 O
4. 원의 개수만큼 조사 후 횟수를 출력한다.

*/

int main() {

  int T, x1, y1, x2, y2, d1, d2, cx, cy, r, n, count;

  scanf("%d", &T);

  for (int i = 0; i < T; i++) {
    count = 0;
    scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
    scanf("%d", &n);

    for (int j = 0; j < n; j++) {
      scanf("%d %d %d", &cx, &cy, &r);
      d1 = (x1-cx)*(x1-cx) + (y1-cy)*(y1-cy);
      d2 = (x2-cx)*(x2-cx) + (y2-cy)*(y2-cy);
      if(!((d1 < r*r) && (d2 < r*r) || (d1 > r*r) && (d2 > r*r))){
        count++;
      }
    }
    printf("%d\n",count);
  }

  return 0;
}
