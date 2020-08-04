#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;
//https://programmers.co.kr/learn/courses/30/lessons/60058

/*
<괄호 변환>
주요: 구현, 시뮬레이션
1. 문제 조건을 꼼꼼하게 읽어보고 그대로 구현하면 된다.
2. 편의를 위해 균형잡힌 괄호, 올바른 괄호 문자열에 대한 확인을 함수 2개로 나눠 진행했다.
3. 나머지느 주어진 조건에 맞게 진행하면 된다.
==========
* 정말 대놓고 구현을 요구하는 문제이다. (잘 알아채지 못했다.)
* 재귀, 조건 등 하라는 대로 순수하게 적용하면 된다.
* 처음엔 혼자만의 해석을 하던, 다른 풀이방향을 잡던, 거부감이 들 수 있다.
* 괄호는 스택을 이용해야한다는 생각을 항상 갖자.
*** 그냥 문제 조건에 충실하게 구현하면 잘 풀 수 있다.
*/

// 균형잡힌 괄호인지 확인
bool isBalance(string s){
  int left = 0, right = 0;
  for(int i = 0; i < s.length(); i++){
    if(s[i] == '(') left++;
    else if(s[i] == ')') right++;
  }
  return left == right;
}

// 올바른 괄호 문자열인지 확인
bool isBalance2(string s){
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

// 조건에 맞게 진행
string solution(string p) {
  string answer = "";
  string u ="", v = "";
  if(p == "") return answer;
  if(isBalance2(p)) return p;
  else{
    for (size_t i = 2; i <= p.length(); i+=2) {
      if(isBalance(p.substr(0,i))){
        u = p.substr(0,i);
        v = p.substr(i);

        if(isBalance2(u) == false){
          v = solution(v);
          answer = "(" + v + ")";
          for (size_t j = 1; j < u.length()-1; j++) {
            if(u[j] == '(') answer +=")";
            else answer += "(";
          }
          return answer;
        }
        else{
          v = solution(v);
          return answer = u +v;
        }
      }
    }
    return answer;
  }
}
