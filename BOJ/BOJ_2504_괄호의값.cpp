#include <bits/stdc++.h>
using namespace std;
// https://www.acmicpc.net/problem/2504

/*
<괄호의 값>
주요: 스택, 재귀
1. calculate()의 리턴값은 하위 괄호 그룹의 괄호값이다.
2. 하위 괄호값을 리턴할 때 sum값이 0이면 1을 리턴한다.(곱셈을 위해)
3. 스택에 '(', '['를 넣고 calculate()를 호출 해 하위괄호값을 넣는다.
4. ')', ']'를 만나면 스택에서 꺼내면서 이 괄호가 올바른 괄호인지 판단한다.
  => 더불어 하위괄호값을 리턴하게 한다.
5. 최종 괄호의 값을 출력한다.
==========
* 재귀에서 꼬이지 않게 idx값으로 현재 위치를 기록한다.
* 올바르지 않은 괄호면 isPossible를 false로 하고 괄호값 구하는것을 중지한다.

*/

bool isPossible = true;
int idx, ans;
string basestr;
stack<char> stk;

int calculate() {
  int sum = 0;
  while(idx < basestr.length()){
    if(!isPossible) return 0;
    if(basestr[idx] == '('){
      idx++;
      stk.push('(');
      sum += 2*calculate();
    }
    else if(basestr[idx] == ')'){
      idx++;
      if(stk.empty() || stk.top() == '['){
        isPossible = false;
        return 0;
      }
      stk.pop();
      if(sum == 0) return 1;
      else return sum;
    }
    else if(basestr[idx] == '['){
      idx++;
      stk.push('[');
      sum += 3*calculate();
    }
    else if(basestr[idx] == ']'){
      idx++;
      if(stk.empty() || stk.top() == '('){
        isPossible = false;
        return 0;
      }
      stk.pop();

      if(sum == 0) return 1;
      else return sum;
    }
  }
  return sum;
}

int main(){
  cin >> basestr;
  ans = calculate();

  if(!stk.empty()) cout << 0;
  else cout << ans;
  return 0;
}
