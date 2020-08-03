#include <algorithm>
#include <string>
#include <vector>
using namespace std;
//https://programmers.co.kr/learn/courses/30/lessons/42746

/*
<가장 큰 수>
주요: 정렬
1. comp 함수를 쓸 때는 비교적 간단한 알고리즘을 생각하자.
  1.1 전혀 어려운 조건이 아니었다.
  1.2 단순 비교로 두개가 연속적일때의 값을 비교했다. (a+b (<,=,>) b+a)
2. string으로 변화 시켜서 계산하는 과정을 생각하면 좋다.
3. a+b 와  b+a 의 string 값을 비교한다.
===========
* comp 함수 만드는데 오래 걸렸다.
  => 아무리 여러 조건을 세워도 AC를 못 받아서 관점을 새로 세웠다.
* 자리수 인데 int 비교가 힘들면 string 비교를 생각하자.

*/

bool comp(const int &A, const int &B){
  string a = to_string(A), b = to_string(B);
  return a+b > b+a;
}

string solution(vector<int> numbers) {
  string answer = "";

  sort(numbers.begin(),numbers.end(),comp);
  if(numbers[0] == 0) return "0";
  for (int i = 0; i <numbers.size(); i++){
    answer += to_string(numbers[i]);
  }
  return answer;
}
