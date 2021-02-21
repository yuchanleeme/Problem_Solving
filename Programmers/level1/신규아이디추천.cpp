#include <bits/stdc++.h>
using namespace std;
//https://programmers.co.kr/learn/courses/30/lessons/72410

/*
<신규 아이디 추천>
주요:구현, 문자열
1. 각 단계에 맞게 구현한다.
2. 최종 answer를 리턴한다.

*/

string solution(string new_id) {
  string answer = "";

  // 1단계
  transform(new_id.begin(), new_id.end(), answer.begin(), ::tolower);

  // 2단계
  for (int i = 0; i < new_id.length(); i++) {
    if(new_id[i] >= '0' && new_id[i] <='9') answer += new_id[i];
    else if(new_id[i] >='a' && new_id[i] <= 'z') answer += new_id[i];
    else if(new_id[i] == '-' || new_id[i] == '_' || new_id[i] == '.') answer+=new_id[i];
  }

  // 3단계
  while(true){
    int temp = answer.find("..");
    if(temp == string::npos) break;
    else answer.replace(temp, 2, ".");
  }

  // 4단계
  if(answer.back() == '.') answer.pop_back();
  if(answer[0] == '.') answer = answer.substr(1);

  // 5단계
  if(answer == "") answer += "a";

  // 6단계
  if(answer.length() >= 16) answer = answer.substr(0,15);
  if(answer.back() == '.') answer.pop_back();

  // 7단계
  while (answer.length() < 3) {
    answer.push_back(answer.back());
  }
  
  return answer;
}
