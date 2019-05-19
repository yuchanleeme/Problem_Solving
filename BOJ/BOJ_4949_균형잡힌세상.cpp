#include <iostream>
#include <stack>
using namespace std;
// https://www.acmicpc.net/problem/4949

/*
<균형 잡힌 세상>
주요: 각 ( , ) , [ , ] 의 상황에 따라 구분한다.
1. ( : 스택에 push
2. ) : 스택이 비거나 이전 스택값이 '(' 가 아닐경우 no  // 이외의 경우 pop
3. [ : 스택에 push
4. ] : 스택이 비거나 이전 스택값이 ']' 가 아닐경우 no  // 이외의 경우 pop
5. . : 모든 과정을 수행했을 때 스택이 비었으면 yes // 아니면 no

*/

int main() {

  char data[101];

  // 공백 포함 문자열을 받아들인다, '.' 만 입력받으면 그만 입력받는다.
  while (cin.getline(data,101) && data[0] != '.') {

    stack <char> stk;

    for (int i = 0; i < 101; i++) {
      if(data[i] == '('){ stk.push(data[i]);}
      else if(data[i] == ')'){
        if(stk.empty() || stk.top() != '('){
          cout << "no" << endl;
          break;
        }
        else{
          stk.pop();
        }
      }
      else if(data[i] == '['){ stk.push(data[i]);}
      else if(data[i] == ']'){
        if(stk.empty() || stk.top() != '['){
          cout << "no" << endl;
          break;
        }
        else{
          stk.pop();
        }
      }
      else if(data[i] == '.'){
        if(stk.empty()){
          cout << "yes" << endl;
        }
        else{
          cout << "no" << endl;
        }
        break;
      }
    }
  }
  return 0;
}
