#include <string>
#include <vector>
//https://programmers.co.kr/learn/courses/30/lessons/12954

/*
<핸드폰 번호 가리기>
주요: 구현
1. x, 2x, 3x, 4x, 5x .... 를 구현하면된다.
2. 결과값을 만들어 리턴한다.

*/

using namespace std;

vector<long long> solution(int x, int n) {
  vector<long long> answer;
  for(int i = 1; i <= n; i++){
    answer.push_back(x*i);
  }
  return answer;
}
