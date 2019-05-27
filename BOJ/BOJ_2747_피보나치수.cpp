#include <iostream>
// https://www.acmicpc.net/problem/2747

/*
<피보나치 수>
주요: 피보나치 수를 이해한다.
1. 주어진 점화식을 구현한다.
2. 필수항인 1,2번째 항을 넣어 초기화한다. (n은 45보다 작거나 같다 했으므로 넉넉하게 50)

*/

int main() {

  int n;
  int fibo[50] = {0, 1,};

  for (int i = 0; i < 47; i++) {
    fibo[i+2] = fibo[i] + fibo[i+1];
  }

  scanf("%d", &n);
  printf("%d\n",fibo[n]);

  return 0;
}
