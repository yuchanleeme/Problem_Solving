#include <bits/stdc++.h>
using namespace std;
//https://programmers.co.kr/learn/courses/30/lessons/17684

/*
<압축>
주요: 구현
1. A~Z까지 먼저 map에 저장한다.
2. 문제 조건에 맞게 answer에 값을 넣는다.

*/
int idx;
unordered_map <string, int> mp;

vector<int> solution(string msg) {
  vector<int> answer;

  // 1번
  for (int i = 65; i < 91; i++) {
    string temp = ""; temp += (char)i;
    mp[temp] = ++idx;
  }

  // 2번
  for (int i = 0; i < msg.length(); i++) {
    string temp = "";
    for (int j = i; j < msg.length(); j++) {
      temp += msg[j];
      if(mp[temp] == 0){
        mp[temp] = ++idx;
        temp.pop_back();
        answer.push_back(mp[temp]);
        i += temp.length()-1;
        break;
      }
      if(j == msg.length()-1){
        answer.push_back(mp[temp]);
        i += temp.length()-1;
      }
    }
  }

  return answer;
}
