#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;
//https://programmers.co.kr/learn/courses/30/lessons/12930

/*
<이상한 문자 만들기>
주요: 구현
1. 단어의 위치를 알려주는 변수를 idx라고 하자.
2. 짝수번째는 대문자, 홀수번째는 소문자로 만든다.
3. 공백을 만나면 idx를 0으로 초기화한다.
4. 결과 값을 리턴한다.
==========
* string s가 대문자로만도 주어질 수 있다.

*/

string solution(string s) {
  string answer = "";
  int idx = 0;
  for (int i = 0; i < s.length(); i++) {
    if(s[i] == ' ')
      idx = 0;
    else{
      if(idx % 2 == 0)
        s[i] = toupper(s[i]);
      else
        s[i] = tolower(s[i]);
      idx++;
    }
    answer += s[i];
  }
  return answer;
}
