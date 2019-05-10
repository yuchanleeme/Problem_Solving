#include <stdio.h>
// https://www.acmicpc.net/problem/1065

/*
<한수>
주요: 한수가 무엇인지 파악한다.
1. 1~99까지는 모든 수가 한수이다. (항이 1,2개이기 때문)
2. 100~999까지는 항 3개를 비교하면 된다. (1,2항의 등차와 2,3항의 등차가 같은지 비교)
3. 1000은 한수가 아니므로 카운팅에 제외한다.

*/

int main() {

  int number, count = 0;
  int a, b, c;

  scanf("%d", &number);

  for(int i = 1; i <= number; i++){
    if(i > 0 && i < 100){ count++;} // 1~99
    else{ // 100~999
      a = i/100;
      b = (i/10) % 10;
      c = i % 10;
      if((b-a) == (c-b)){ count++;}
    }
  }

  printf("%d", count);

  return 0;
}
