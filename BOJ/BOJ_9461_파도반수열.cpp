#include <iostream>
// https://www.acmicpc.net/problem/9461

/*
<파도반 수열>
주요: 규칙을 찾자.
1. 수열 문제이기 때문에 혹시 점화식을 구할 수 있나 확인한다. (표를 만들어 처음부터 하나씩 대입해본다.)
2. 규칙성을 찾아 보니 P(N) = P(N-5) + P(N-1) (단, N >= 6) 이라는 점화식을 세울 수 있다.
3. 1~5 항까지는 정해진 값을 배열에 넣고 나머지는 점화식을 이용해 배열에 저장한다.
4. 편의를 위해 배열 idx와 n값 같게 한다.
5. 79번째 항부터 int 범위를 넘어서므로 long long 선언

*/

int main() {

  int T, n;
  long long padovan[102] = {0, 1, 1, 1, 2, 2,};

  for (int i = 6; i < 101; i++) {
    padovan[i] = padovan[i-5] + padovan[i-1];
  }

  scanf("%d", &T);
  for (int i = 0; i < T; i++) {
    scanf("%d", &n);
    printf("%lli\n", padovan[n]);

  }

  return 0;
}
