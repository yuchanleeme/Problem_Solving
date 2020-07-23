#include <algorithm>
#include <vector>
using namespace std;
//https://programmers.co.kr/learn/courses/30/lessons/12917

/*
<문자열 내림차순으로 배열하기>
주요: 정렬
1. 아스키코드 상 대문자가 더 작은 값임을 안다.
2. 따라서 정렬을 그대로 해주면 된다.

*/

bool comp(const char &A, const char &B){
  return A > B;
}

string solution(string s) {
  sort(s.begin(), s.end(),comp);
  return s;
}
