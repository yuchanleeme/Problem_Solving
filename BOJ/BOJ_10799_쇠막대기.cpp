#include <iostream>
#include <stack>
using namespace std;
// https://www.acmicpc.net/problem/10799

/*
<쇠막대기>
주요: 레이저를 기준으로 조각이 어떻게 나는지에 주목한다.
1. 레이저를 기준으로 그 이전에 나왔던 '('의 개수만큼 스택에 push하고 그 스택의 size만큼 sum에 더해준다.
2. ')'의 개수 만큼 "다음 턴" 레이저를 만났을때 스택을 pop해준다.
3. 마지막 레이저를 만난 뒤 부터 ')'의 개수만큼 sum에 더해준다.

*/

int main() {

  int temp = 0, sum = 0;
  char data[100001];
  stack <char> stk;

  cin >> data;

  for (int i = 0; i < 1000001; i++) {

    // 1,2,3 번
    if (data[i] == '(') {
      stk.push(data[i]);
    }
    else if (data[i] == ')'){
      if(data[i-1] == '('){  // 레이저  ex : "()"
        stk.pop(); // 레이저 스택 제거
        sum += stk.size();
        for (int j = 0; j < temp; j++) {
          stk.pop();
        }
        temp = 0;
      }
      else{ //  ex : "))"
        temp += 1;
      }
    }
    else{
      sum += temp;
      break;
    }
  }

  cout << sum;

  return 0;
}
