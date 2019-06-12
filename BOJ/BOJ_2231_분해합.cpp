#include <iostream>
using namespace std;
//https://www.acmicpc.net/problem/2231

/*
<분해합>
주요: 가장 작은 생성자를 출력한다.
1. 문제 조건에 맞게 생성자를 찾을 때까지 for문을 돌리고 찾으면 i를 출력하고 break 한다.(촤솟값)
2. i가 N-1까지 for문을 돌았을 때까지 생성자가 발견 되지 않았다면 생성자가 없는 것이므로 0을 출력한다.
=========
* 문제를 풀고 안것이지만 for문을 N-55까지만 돌려도 된다.
  => 제일 큰 자리수합 : 55 (999,999)

*/

int main() {

  int N, sum, temp;

  cin >> N;

  for (int i = 0; i < N; i++) {

    sum = i;
    temp = i;
    while (temp != 0) {
      sum += temp % 10;
      temp /= 10;
    }

    if(sum == N){
      printf("%d\n",i);
      break;
    }
    else if(i == N-1){
      printf("0\n");
      break;
    }
  }

  return 0;
}
