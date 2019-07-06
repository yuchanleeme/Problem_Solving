/*
////////////////////////////////
main : stack
1. 여는 괄호는 계속 스택에 들어올수 있다.
2. 닫는 괄호는 현재 스택의 top이 자신과 맞는 짝이어야지만 그 여는 괄호를 pop할 수 있다.
  => 닫는 괄호가 위의 조건에 맞지 않는다면 조건에 부합하므로 false를 리턴한다.
3. 모든 string 값을 조사 했을 때 stack이 비었다면 true, 아니면 false를 리턴한다.
   
////////////////////////////////
*/

class Solution {
public:
  bool isValid(string s){

    stack<char> stk;

    for (int i = 0; i < s.size(); i++) {
        if(s[i] == '('){
        stk.push(s[i]);
      }
      else if(s[i] == ')'){
        if(stk.size() != 0 && stk.top() == '('){ stk.pop();}
        else{ return false;}
      }
      else if(s[i] == '{'){
        stk.push(s[i]);
      }
      else if(s[i] == '}'){
        if(stk.size() != 0 && stk.top() == '{'){ stk.pop();}
        else{ return false;}
      }
      else if(s[i] == '['){
        stk.push(s[i]);
      }
      else if(s[i] == ']'){
        if(stk.size() != 0 && stk.top() == '['){ stk.pop();}
        else{ return false;}
      }
    }

    if(stk.size() == 0){ return true;}
    else{ return false;}
  }
};
