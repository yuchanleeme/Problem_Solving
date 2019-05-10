#include <stdio.h>
// https://www.acmicpc.net/problem/1003

/*
<피보나치 함수>
주요: 피보나치 수열을 이해한다.
1. 재귀함수를 이용하여 카운트 해도 되지만 시간이 오래걸리기 때문에 문제를 이해해 시간을 줄인다.
2. 하나씩 써보면서 규칙을 찾아보면 결국 피보나치 수열과 비슷하다는 것을 이해할 수 있다.
3. N이 40 이하인 0또는 자연수이므로 아예 수열을 다 만들어 배열에 저정한다.
4. 해당되는 값의 배열값을 출력한다.

*/

int main() {

  int T;
  int num;
  int fibo[41] = {0, 1,};

  for (int i = 0; i < 40; i++) {
    fibo[i+2] = fibo[i] + fibo[i+1];
  }

  scanf("%d", &T);

  for (int j = 0; j < T; j++) {
      scanf("%d", &num);
      if(num == 0){ printf("1 0\n");}
      else{ printf("%d %d\n", fibo[num-1], fibo[num]);}
  }

  return 0;
}
