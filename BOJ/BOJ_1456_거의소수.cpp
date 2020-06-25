#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
//https://www.acmicpc.net/problem/1456

/*
<거의 소수>
주요: 에라토스테네스의 체, 오버플로우
1. 에라토스테네스의 체를 이용해 10^7 까지의 소수를 구한다.
  => 코드 잘 기억하기
2. 이제 구한 소수를 이용해 거의 소수를 구한다.
3. 오버플로우 방지를 위해 장치를 해놓는다.
  * temp > B/i
    temp*i > B
  => 위 두 식은 같으므로, 위처럼 해놓으면 오버플로우가 생기기 전에 미리 while문을 벗어난다.
===========
* j 가 int 범위를 넘어 갈 수 있으므로 long long을 이용한다.
* 오버플로우에 대해 유의한다.

*/

const long long MAX_SIZE = 1e7+1;
int check[MAX_SIZE] = {1, 1, }; // 0이면 소수
int main() {

  long long A, B;
  int prime = 0;

  cin >> A >> B;
  // 1번
  for (long long i = 2; i<= MAX_SIZE; i++) {
    if(check[i] == 0){
      for (long long j = 2*i; j <= MAX_SIZE; j+=i) {
        if(check[i] == 1)
           continue;
        if(j % i == 0)
          check[j] = 1;
      }
    }
  }

  // 2번
  for (long long i = 2; i <= MAX_SIZE; i++) {
    if(check[i] == 0){
      long long temp = i*i;
      while(temp <= B){
        if(temp >= A){
          prime++;
        }
        // 3번
        if(temp > B/i){
          break;
        }
        temp *= i;
      }
    }
  }
  cout << prime;

  return 0;
}
