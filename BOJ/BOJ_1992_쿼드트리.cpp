#include <iostream>
using namespace std;
//https://www.acmicpc.net/problem/1992

/*
<쿼드트리>
주요: 분할 정복(Divide-and-conquer)
1. 가장 간단한 경우로 기본 단계를 찾는다.
  => 비교 배열의 크기가 2x2가 될 때까지 분할 한다.
  => 2,1,3,4분면순(Z모양)으로 다 같은 값인지 확인한다.
  => 같은 값이면 그 값을 출력하고 아닐경우 () 안에 각각 값들을 출력해준다.
  => size가 1 일때(1칸짜리) 그대로 출력해준다.
2. 재귀 함수를 호출 할 때마다 비교할 배열의 크기를 줄여준다.
  => 2의 제곱수로 구성되므로 2씩 나눠준다.

*/

int screen[64][64];

void quard_tree(int size, int col, int row){

  int now = screen[col][row];
  int std_size = size/2;
  bool same = true;

  if(size == 1){
    printf("%d", now);
    return;
  }

  for (int i = col; i < col+size; i++) {
    for (int j = row; j < row+size; j++) {
      if(now != screen[i][j]){
        same = false;
      }
    }
  }

  if(same){
    printf("%d", now);
  }
  else{
    printf("(");
    quard_tree(std_size, col, row); // 2사분면
    quard_tree(std_size, col, row+std_size); // 1사분면
    quard_tree(std_size, col+std_size, row); // 3사분면
    quard_tree(std_size, col+std_size, row+std_size); // 4사분면
    printf(")");
  }
}

int main() {

  int N;

  scanf("%d", &N);

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      scanf("%1d", &screen[i][j]); // 1개씩 입력받기
    }
  }

  quard_tree(N,0,0);

  return 0;
}
