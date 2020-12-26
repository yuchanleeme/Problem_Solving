#include <bits/stdc++.h>
using namespace std;
// https://www.acmicpc.net/problem/4539

/*
<반올림>
주요: 구현
1. 자리수별로 계산을 해 반올림을 구현한다.
2. 0의 개수도 세서 0을 자리수 만큼 출력시킨다.

*/

int N;
int main(){
  cin >> N;

  while (N--) {
    int num, cnt = 0;
    cin >> num;
    int prevNum = num;
    while (num > 10) {
      prevNum = num % 10;
      num /= 10;
      if(prevNum >= 5) num += 1; // 반올림 조건
      cnt++;
    }
    printf("%d", num);
    while (cnt--) {
      printf("0");
    }
    printf("\n");
  }

  return 0;
}
