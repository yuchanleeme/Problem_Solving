#include <algorithm>
#include <vector>
using namespace std;
//https://programmers.co.kr/learn/courses/30/lessons/12918

/*
<문자열 다루기 기본>
주요: 문자열
1. 길이가 4, 6이 아니면 false 리턴한다.
2. 숫자가 아니라면 false 리턴한다.
3. 나머지는 true 리턴한다.
==========
* isdigit(x) : x가 숫자가 아니면 0을 리턴한다. 숫자면 0이 아닌수

*/

bool solution(string s) {
  if(s.length() != 4 && s.length() != 6) return false;
  for(int i = 0; i < s.size(); i++){
    if(!isdigit(s[i])) return false;
  }
  return true;
}
