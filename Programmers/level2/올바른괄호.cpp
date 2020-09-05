#include<string>
#include <iostream>
#include <stack>
using namespace std;
//https://programmers.co.kr/learn/courses/30/lessons/12909

/*
<올바른 괄호>
주요: 스택
1. '(' 일때만 스택에 넣고 ')'이면 pop을 해준다.
2. 비었을 때도 pop을 하면 false를 리턴한다.
3. 모든 문자열을 돌았을 때 스택이 비었으면 true, 아니면 false를 리턴한다.

*/

bool solution(string s){
  stack<char> stk;
  for(int i = 0; i < s.size(); i++){
    if(s[i] == '(') stk.push('(');
    else{
      if(stk.empty()) return false;
      else stk.pop();
    }
  }
  if(stk.empty()) return true;
  else return false;
}
