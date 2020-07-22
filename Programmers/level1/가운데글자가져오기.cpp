#include <string>
#include <vector>
using namespace std;
//https://programmers.co.kr/learn/courses/30/lessons/12903

/*
<가운데 글자 가져오기>
주요: 구현
1. 길이가 1이면 그 문자 하나만 리턴한다.
2. 길이가 홀수면 길이의 반 idx 문자 하나만 리턴한다.
3. 길이가 짝수면 길이의 반에서 두개의 idx 문자를 리턴한다.
*/

string solution(string s) {
    string answer = "";
    if(s.size() == 1)
      answer += s[0];
    else if(s.size() % 2 == 1)
      answer += s[s.size()/2];
    else if(s.size() % 2 == 0){
      answer += s[(s.size()-1)/2];
      answer += s[(s.size()-1)/2 + 1];
    }
    return answer;
}
int main(int argc, char const *argv[]) {
  /* code */
  return 0;
}
