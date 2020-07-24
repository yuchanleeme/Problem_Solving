#include <vector>
#include <algorithm>
using namespace std;
//https://programmers.co.kr/learn/courses/30/lessons/12937

/*
<짝수와 홀수>
주요: 구현
1. 짝수이면 Even을 리턴
2. 홀수이면 Odd를 리턴

*/

string solution(int num) {
  if(num % 2 == 0) return "Even";
  else return "Odd";
}
