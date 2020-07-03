#include <iostream>
#include <cmath>
using namespace std;
// https://www.acmicpc.net/problem/6588

/*
<골드바흐의 추측>
주요: 수학
1. 소수 문제 시간복잡도의 최적화를 요구하는 문제이다.
2. 시간복잡도 최적화 방법
  2.1 입력 테스트케이스가 여러개 => 소수 찾기는 시작할 때 한번만 실행
  2.2 N까지의 소수 구할때 sqrt(N) 까지만 찾는다.
  2.3 소수 찾을 때 짝수를 제외하기 위해 j+=2 한다.
  2.4 소수 찾을 때 자신의 제곱 부터 에라토스테네스의 체를 돌린다.
  =====
  2.5 두 소수를 찾을 때 하나가 X면 다른 하나는 input-X라는 것을 이용한다.
    => 따라서 범위의 반만 찾는다.
  2.6 b-a가 큰값이 나올때까지 하는게 아니라 하나만 찾아도 break한다.
    => 어차피 뒤로갈수록 찾더라도 b-a값은 줄어든다.
3. 계산한 결과를 출력한다.
==========
* 하나만 찾아도 되는 방법을 생각 못했다.
* 반례를 여러개 넣어서 확인한다. (6 = 3+3 등)
*/

const int INF = 1000010;
int prime[INF];
int main() {

  for (int i = 2; i <= sqrt(INF); i++) {
    if(prime[i] == 1) continue;
    for (int j = i*i; j < INF; j+=2) {
      if(prime[j] == 1) continue;
      if(j % i == 0) prime[j] = 1;
    }
  }
  int input;
  while (scanf("%d",&input)) {
    if(input == 0) break;
    int a = 0, b = 0;
    for (int i = 3; i <= input/2; i++) {
      if(prime[i] == 0 && prime[input-i] == 0){
        a = i;
        b = input - i;
        break;
      }
    }

    if(a*b != 0)
      printf("%d = %d + %d\n",input, a, b);
    else
      printf("Goldbach's conjecture is wrong.\n");
  }

  return 0;
}
