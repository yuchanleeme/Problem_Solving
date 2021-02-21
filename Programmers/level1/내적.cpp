#include <string>
#include <vector>
using namespace std;
//https://programmers.co.kr/learn/courses/30/lessons/70128

/*
<내적>
주요: 수학
1. 내적 계산을 한다.
2. 계산값을 리턴한다.

*/

int solution(vector<int> a, vector<int> b) {
  int answer = 0;
  for(int i = 0; i < a.size(); i++){
    answer += a[i]*b[i];
  }
  return answer;
}
