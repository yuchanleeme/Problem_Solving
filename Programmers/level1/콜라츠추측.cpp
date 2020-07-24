#include <vector>
#include <algorithm>
using namespace std;
//https://programmers.co.kr/learn/courses/30/lessons/12943

/*
<콜라츠 추측>
주요: 구현
1. 값이 커지는 것을 고려해 res를 long long으로 선언했다.
2. 문제가 원하는 대로 구현하고, answer을 1씩 추가한다.
3. 500 번을 넘어가면 for문이 끝난 후 -1을 리턴한다.
==========
* dp로 푸는 법도 있지만 500번 제한이기도 해서 그냥 그대로 구현으로 풀었다.

*/

int solution(int num) {
  int answer = 0;
  long long res = num;
  for(int i = 1; i <= 500; i++){
    if(res == 1) return answer;
    if(res % 2 == 0) res /= 2;
    else res = 3*res + 1;
    answer++;
  }
  return -1;
}
