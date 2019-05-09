#include <iostream>
using namespace std;
// https://www.acmicpc.net/problem/2312

/*
<수 복원하기>
주요: 2부터 자기 자신까지 하나씩 나눠 저장한다.
1. 배열을 하나 만들어 제수, 제수의 횟수를 순차적으로 저장한다.
2. 2부터 나누어지면 제수에 저장하고 나머지가 생길때까지 나누고 횟수를 증가시킨다.
3. 배열을 2개씩 출력한다.

*/

int main() {

  int T, N, temp;

  scanf("%d", &T);

  for (int a = 0; a < T; a++) {
    // 배열 및 temp값 초기화
    temp = 0;
    int res[14] = {};

    scanf("%d", &N);

    // 2번 조건
    for (int i = 2; i <= N; i++) {
      if ((N % i) == 0) {
        res[temp] = i;
        temp++;

        while (N % i == 0) {
          res[temp] += 1;
          N /= i;
        }
        temp++;
      }
    }

    // 출력 2개씩 증가시켜 출력한다.
    for (int j = 0; j < temp; j+=2) {
      printf("%d %d \n",res[j],res[j+1]);
    }
  }

  return 0;
}
