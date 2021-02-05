#include <bits/stdc++.h>
using namespace std;
// https://www.acmicpc.net/problem/2812

/*
<크게 만들기>
주요: 스택
1. 앞의 자리수가 클 수록 큰 값이다.
2. 따라서, 앞에서 부터 값을 찾아 지우면서 제일 큰 수만 남겨놓는다.
3. 지운횟수가 K를 넘어가면 지우는것을 중지하고 모든 값을 스택에 넣는다.
4. 지운횟수가 남았다면 그 횟수만큼 stack을 pop해준다.
5. stack을 비우면서 string값을 만든다.
6. 마지막으로 reverse 함수를 써서 정답을 출력한다.

*/

int N, K, check;
stack<char> stk;
int main(){

  scanf("%d %d ", &N, &K);

  for (int i = 0; i < N; i++) {
    char num;
    scanf("%1c ", &num);

    while (true) {
      if(stk.empty() || check == K){
        stk.push(num);
        break;
      }
      if(stk.top() < num){
        stk.pop();
        check++;
      }
      else{
        stk.push(num);
        break;
      }
    }
  }

  while(check != K){
    stk.pop();
    check++;
  }

  string str = "";
  while (!stk.empty()) {
    str += stk.top();
    stk.pop();
  }

  reverse(str.begin(),str.end());
  printf("%s", str.c_str());

  return 0;
}
