#include <iostream>
using namespace std;
//https://www.acmicpc.net/problem/6679

/*
<싱기한 네자리 숫자>
주요: 브루트 포스
1. 진수와 숫자를 입력받으면 각 자리수의 합을 리턴해주는 함수를 만든다.
2. 문제에서 2992가 첫 숫자라 했으므로 2992부터 9999까지만 조사한다.
3. 조사 결과 셋 다 같은경우에만 출력해준다.

*/
int trans(int div, int num){

  int sum = 0;
  while(num != 0){
    sum += num % div;
    num /= div;
  }

  return sum;

}

int main() {

  int temp;

  for (int i = 2992; i < 10000; i++) {
    temp = trans(10, i);
    if(temp != trans(12,i)){
      continue;
    }
    else if(temp != trans(16,i)){
      continue;
    }
    else{
      cout << i << endl;
    }
  }

  return 0;
}
