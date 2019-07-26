#include <iostream>
#include <cmath>
using namespace std;
//https://www.acmicpc.net/problem/3053

/*
<택시 기하학>
주요: 수학
1. 유클리드 기하학과 택시 기하학의 차이점을 파악한다.
  -> 유클리드 : 현재 우리가 사용하는 기하학
  -> 택시 : 같은 좌표평면상에서 택시처럼 구불구불 이동하는 경우
2. 유클리드 기하학에서의 원 : 우리가 현재 쓰는 원과 같다.
3. 택시 기하학에서의 원 : 정사각형 모양(마름모로 계산)

*/

int main() {

  int R;

  scanf("%d", &R);

  printf("%.6f\n", R * R * M_PI);
  printf("%.6f\n", R * R * 2.0);
  
  return 0;

}
