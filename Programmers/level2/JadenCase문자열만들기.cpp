#include <bits/stdc++.h>
using namespace std;
//https://programmers.co.kr/learn/courses/30/lessons/12951

/*
<JadenCase 문자열 만들기>
주요: toUpper, toLower
1. 만약 이전 위치의 문자가 공백이면 단어의 시작이므로 대문자로 만든다.
2. 그게 아니라면 소문자로 만든다.
3. 첫문자도 대문자로 만든다.

*/

`string solution(string s) {
  string answer = "";
  for (int i = 0; i < s.length(); i++) {
    if(i == 0 || s[i-1] == ' ')
      s[i] = toupper(s[i]);
    else
      s[i] = tolower(s[i]);
  }
  return s;
}
