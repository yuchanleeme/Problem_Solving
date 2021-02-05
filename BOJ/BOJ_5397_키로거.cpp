#include <bits/stdc++.h>
using namespace std;
// https://www.acmicpc.net/problem/5397

/*
<키로거>
주요: 스택
1. password의 back()값이 현재 커서의 위치라고 생각한다.
2. stack의 값은 커서의 위치에 따른 password의 일부분이라고 생각하면 된다.
3. 즉, 전체 비밀번호는 password + stack 이렇게 두 덩어리로 분류된다고 보면 된다.
4. 따라서, 커서의 위치를 옮길때 마다 password의 back()값과 stack의 top()값을 번갈아가면서 이동시킨다.
5. 모든 command가 끝나면 stack에 남은 값들을 password에 붙이고 그 값을 출력한다.

*/

int T;
int main(){
  cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);
  cin >> T;

  for (int tc = 0; tc < T; tc++) {
    string str; cin >> str;
    stack<char> stk;
    string password = "";

    for (int i = 0; i < str.length(); i++) {
      if(str[i] == '<'){
        if(password == "") continue;
        stk.push(password.back());
        password.pop_back();

      }else if(str[i] == '>'){
        if(stk.empty()) continue;
        password += stk.top();
        stk.pop();

      }else if(str[i] == '-'){
        if(password == "") continue;
        password.pop_back();
      }
      else{
        password += str[i];
      }
    }

    // 5번
    while (!stk.empty()) {
      password += stk.top();
      stk.pop();
    }
    cout << password << "\n";
  }
}
