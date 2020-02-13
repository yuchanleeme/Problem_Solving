#include <iostream>
#include <vector>
using namespace std;
//https://www.acmicpc.net/problem/1629

/*
<곱셈>
주요: 분할정복
1. 이진법의 형태로 분할정복 한다.
2. 거듭제곱을 계산해주면 된다.
  => n이 홀수 이면 제곱승 1을 빼고 리턴한다. ex) 2^11 = 2^10 * 2^1
  => n이 짝수 이면 제곱승을 2로 나누고 리턴한다. ex) 2^12 = 2^6 * 2^6
3. 각각 함수값을 리턴할떼 나머지를 해줘서 리턴한다.

*/

long long A, B, C;

// a의 N제곱을 리턴
long long pw(long long a, long long n){

  if(n == 0) return 1; // 어떤수의 0승은 1이다.
  if(n%2) return pw(a,n-1) * a % C; // n이 홀수
  long long tmp = pw(a, n/2); // n이 짝수
  return tmp * tmp % C;
}

int main() {

  scanf("%lld %lld %lld", &A, &B, &C);
  printf("%lld", pw(A,B));

  return 0;
}
