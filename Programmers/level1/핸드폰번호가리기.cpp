#include <string>
#include <vector>
//https://programmers.co.kr/learn/courses/30/lessons/12948

/*
<핸드폰 번호 가리기>
주요: 구현
1. 마지막 4개의 번호에서만 *표시해서 answer에 복사한다.
2. 결과값을 리턴한다.

*/
using namespace std;

string solution(string phone_number) {
  string answer = "";
  for (int i = 0; i < phone_number.length(); i++) {
    if(i < phone_number.length()-4) answer += "*";
    else answer += phone_number[i];
  }
  return answer;
}
