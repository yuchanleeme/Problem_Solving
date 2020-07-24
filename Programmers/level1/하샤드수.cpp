#include <vector>
#include <algorithm>
using namespace std;
//https://programmers.co.kr/learn/courses/30/lessons/12947

/*
<하샤드 수>
주요: 구현
1. 자릿수의 합을 다 구한다. (temp)
2. x 를 temp로 나누었을때 나머지가 0인지 판단해서 리턴한다.

*/

bool solution(int x) {
  int n = x;
  int temp = 0;
  while(n != 0){
    temp += n % 10;
    n /= 10;
  }
  return x % temp == 0;
}
