#include <iostream>
using namespace std;
//https://www.acmicpc.net/problem/10989

/*
<수 정렬하기 3>
주요: 카운팅 정렬
1. 카운팅 정렬을 이용해 푼다.
2. 입력받은 수 중에서 가장 큰 값(max_num)을 기억해 출력 할때 시간을 조금이라도 줄인다.
3. max_num까지 값을 출력한다.

*/

int main() {

  int seq[10010] = {0, };
  int N;
  scanf("%d", &N);

  int max_num = -1;
  for (int i = 0; i < N; i++) {
    int input;
    scanf("%d", &input);
    // 2번
    max_num = max(max_num, input);
    seq[input]++;
  }

  for (int i = 1; i <= max_num; i++) {
    for (int j = 0; j < seq[i]; j++) {
      printf("%d\n", i);
    }
  }

  return 0;
}
