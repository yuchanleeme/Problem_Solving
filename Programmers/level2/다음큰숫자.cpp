#include <bits/stdc++.h>
using namespace std;
//https://programmers.co.kr/learn/courses/30/lessons/64065

/*
<다음 큰 숫자>
주요: 구현
1. 먼저, 입력받은 n의 1의 개수를 센다.
2. 그 다음 n 부터 하나씩 증가시키면서 1의 개수를 센다.
  => 생각보다 많은 수를 할 필요가 없기에 시간초과가 날 일이 없다.
3. 다음 큰 숫자가 나오면 그 수를 리턴한다.
==========
* 처음에는 전체 숫자의 1의 개수를 다 세는 알고리즘을 생각했는데 시간초과가 떴다.
  => 생각보다 적은 수의 while문을 돈다는것을 깨닫고 다시 알고리즘을 짰다.

*/

int solution(int n){
  int temp = n;
  int num = 0;

  // n 찾기
  while(temp != 0){
    if(temp % 2 == 1) num++;
    temp/=2;
  }

  // 다음 큰 수 찾기
  while (true) {
    n++;
    int num2 = 0;
    int temp = n;
    while (temp!= 0) {
      if(temp % 2 == 1) num2++;
      temp/=2;
    }
    if(num2 == num) return n;
  }
}
