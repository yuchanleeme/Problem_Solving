#include <iostream>
#include <stack>
using namespace std;
// https://www.acmicpc.net/problem/9012

/*
<괄호>
주요: '(' 가 나오면 반드시 같은 수의 ')'가 있어야 한다.
1. VPS(Valid PS)가 어떻게 구성되어야 하는지 바르게 이해한다.
2. '(' 가 나오면 반드시 같은 수의 ')'가 있어야 한다.
3. 문자열 구성은 반드시 '('로 시작해야 하고 ')'로 끝나야 한다.
4. 따라서 '('를 스택의 Push , ')'를 스택의 Pop 개념으로 생각하면 된다.
  - push와 pop 이 같은 수가 되어 스택안이 텅 비게 되면 VPS가 되는 것이다.

* 경우의 수(분기점)
  1. '(' 라면 push
  2-1. ')' 이고 스택이 비어있으면 "NO"
  2-2. ')' 이고 스택이 비지 않았다면 pop
  3-1. 문자열이 끝났을 때 스택이 비었다면 "YES"
  3-2. 문자열이 끝났을 때 스택이 안비었다면 "NO"

*/

int main() {

  int T;
  char data[51];

  cin >> T;

  for (int i = 0; i < T; i++) {
    stack <char> stk;
    cin >> data;

    for (int j = 0; j <= 50; j++) {

      // 경우의 수
      if (data[j] == '('){
        stk.push(data[j]);
      } // 1번
      else if(data[j] == ')'){
        if (stk.empty()) {
          cout << "NO" << endl;
          break;
        } // 2-1번
        else{
          stk.pop();
        } // 2-2번
      }
      else{
        if (stk.empty()){
          cout << "YES" << endl;
          break;
        } // 3-1번
        else{
          cout << "NO" << endl;
          break;
        } // 3-2 번
      }
    }
  }

  return 0;
}
