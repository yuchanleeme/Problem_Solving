#include <iostream>
// https://www.acmicpc.net/problem/2748

/*
<피보나치 수 2>
주요: 피보나치 수를 이해한다.
1. 주어진 점화식을 구현한다.
2. 필수항인 1,2번째 항을 넣어 초기화한다. (n은 90보다 작거나 같다 했으므로 넉넉하게 100)
3. 47번째 피보나치 수 부터 int 범위를 넘어서기에 자료형을 바꿔준다. - 100번째까지 고려 (long long)

*/

int main() {

  int n;
  unsigned long long fibo[150] = {0, 1,};

  for (int i = 0; i < 145; i++) {
    fibo[i+2] = fibo[i] + fibo[i+1];
  }

  scanf("%d", &n);
  printf("%llu\n",fibo[n]);

  return 0;
}
