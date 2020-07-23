#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;
//https://programmers.co.kr/learn/courses/30/lessons/12931

/*
<자릿 수 더하기>
주요: 구현
1. 10으로 나눈 나머지를 계속 더해준다고 생각하면 된다.
2. 0이 될때까지 계속 더해준다.
3. 결과를 출력한다.

*/

int solution(int n)
{
  int answer = 0;
  while(n != 0){
    answer += n %10;
    n /= 10;
  }
  return answer;
}
