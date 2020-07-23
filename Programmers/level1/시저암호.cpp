#include <algorithm>
#include <vector>
using namespace std;
//https://programmers.co.kr/learn/courses/30/lessons/12926

/*
<시저 암호>
주요: 문자열
1. 아스키 코드 번호가 움직인다고 생각하면 된다.
2. 각 알파벳의 z,Z가 넘었을 시 알파벳 총 개수인 26을 빼주면 된다.
3. 공백일때는 공백을 넣어준다.
4. 최종 결과값을 리턴한다.

*/

string solution(string s, int n) {
  string answer = "";
  for (int i = 0; i < s.length(); i++) {
    if(s[i] >= 'A' && s[i] <='Z'){
      if(s[i]+n > 'Z') answer += (s[i]+n -26);
      else answer += (s[i]+n);
    }
    else if(s[i] >= 'a' && s[i] <='z'){
      if(s[i]+n > 'z') answer += (s[i]+n -26);
      else answer += (s[i]+n);
    }
    else{
      answer += " ";
    }
  }
  return answer;
}
