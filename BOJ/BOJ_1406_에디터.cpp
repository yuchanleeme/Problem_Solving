#include <bits/stdc++.h>
using namespace std;
// https://www.acmicpc.net/problem/1406

/*
<에디터>
주요: 스택
1. word의 back()값이 현재 커서의 위치라고 생각한다.
2. stack의 값은 커서의 위치에 따른 word 일부분이라고 생각하면 된다.
3. 즉, 전체 비밀번호는 word + stack 이렇게 두 덩어리로 분류된다고 보면 된다.
4. 따라서, 커서의 위치를 옮길때 마다 word의 back()값과 stack의 top()값을 번갈아가면서 이동시킨다.
5. 모든 command가 끝나면 stack에 남은 값들을 word에 붙이고 그 값을 출력한다.

*/

int M;
string word;
stack<char> stk;
int main(){
  ios::sync_with_stdio(false); cin.tie(NULL);

  cin >> word >> M;

  for (int i = 0; i < M; i++) {
    char command;  cin >> command;
    if(command == 'P'){
      char w; cin >> w;
      word += w;
    }
    else if(command == 'L'){
      if(word.length() == 0) continue;
      stk.push(word.back());
      word.pop_back();
    }
    else if(command == 'D'){
      if(stk.size() == 0) continue;
      word += stk.top();
      stk.pop();
    }
    else if(command == 'B'){
      if(word.length() == 0) continue;
      word.pop_back();
    }
  }

  while (!stk.empty()) {
    word += stk.top();
    stk.pop();
  }

  cout << word;

  return 0;
}
