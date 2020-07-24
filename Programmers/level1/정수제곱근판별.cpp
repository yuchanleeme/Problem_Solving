#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
//https://programmers.co.kr/learn/courses/30/lessons/12934

/*
<정수 제곱근 판별>
주요: 구현
1. sqrt(n) 은 double형으로, 소수자리까지 알려준다.
2. 따라서 제곱수이면 sqrt(n) * sqrt(n) 이 n일 거고 아니면 근사값이 될것이다.
3. 이를 이용해서 제곱수를 찾아서 해당 값을 리턴하면 된다.
===========
* pow를 쓰면 WA를 받는다.

*/

long long solution(long long n) {
  long long answer = 0;
  long long num = sqrt(n);
  if(num * num == n) return (num+1) * (num+1);
  else return -1;
}
