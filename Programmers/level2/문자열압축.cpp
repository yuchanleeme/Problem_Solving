#include <vector>
#include <string>
#include <algorithm>
using namespace std;
//https://programmers.co.kr/learn/courses/30/lessons/60057

/*
<문자열 압축>
주요: 문자열, 구현
1. 문자열의 절반까지의 단위만 정한다.
2. 문자열의 처음부터 단위별로 끊는다.
  => ex) 단위: 3 => abc/def/ghi ... => abc 겹치는게 없으면 def를 조사하는것
3. 문자열의 처음과 끝까지 각 단위에 맞게 조사한다.
  =>
===========
* 문제 이해를 잘못해서 계속 틀렸던 문제이다.
* 예제 5번을 자세히 보고서야 깨달았다. 문제를 잘 읽는 습관을 들이자.

*/

int solution(string s) {
  int answer = 1100;
  for (int i = 1; i <= s.length()/2; i++) {
    int st = 0, next = st+i; // 비교할 단위의 시작과 끝
    string temp = "";
    int count = 1;

    // 마지막 단어 이전까지 문자열을 만들어본다.
    while(next < s.length()){
      if(s.substr(st, i) == s.substr(next, i)){
        count++;
        next += i;
      }
      else{
        if(count >= 2)
          temp += to_string(count);
        temp += s.substr(st,i);
        st = next;
        next += i;
        count = 1;
      }
    }

    // 남은 문자열을 출력한다.
    if(count >= 2){
      temp += to_string(count);
    }
    temp += s.substr(st,i);

    // 길이 비교를 한다.
    answer = min(answer, (int)temp.length());
  }

  // 1개 짜리는 위의 while문을 진입 못하기에 예외처리한다.
  if(answer == 1100) return 1;
  return answer;
}
