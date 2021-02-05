#include <bits/stdc++.h>
using namespace std;
// https://www.acmicpc.net/problem/2493

/*
<탑>
주요: 스택
1. 스택에 내림차순으로 {탑의 길이, 탑의 번호}를 넣는다.
2. 스택이 비었으면 전송할 탑이 없는것이므로 현재 위치의 탑의 정보를 넣는다.
3. 스택이 비지 않았다면 전송할 수 있는 탑을 찾는다.
  3-1 stack을 pop 하면서 현재보다 큰 길이의 탑을 찾는다.
  3-2 자신보다 큰 길이의 탑이 나타난다면 그 탑의 번호를 출력하고 현재 탑의 정보를 스택에 넣는다.
4. 위 과정을 탑의 끝 번호까지 실행하며 결과를 출력한다.

*/

stack<pair<int, int> > stk;

int main(){

  int N; scanf("%d", &N);
  for (int i = 1; i <= N; i++) {
    int temp; scanf("%d", &temp);
    if(stk.empty()){
      stk.push({temp, i});
      printf("0 ");
    }
    else{
      while (!stk.empty() && stk.top().first < temp) {
        stk.pop();
      }
      if(stk.empty()){
        stk.push({temp, i});
        printf("0 ");
      }
      else{
        printf("%d ",stk.top().second);
        stk.push({temp, i});
      }
    }
  }

  return 0;
}
