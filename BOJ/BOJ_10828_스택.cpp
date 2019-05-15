#include <iostream>
using namespace std;
//https://www.acmicpc.net/problem/10828

/*
<스택>
주요: 직접 스택 자료구조를 만들어본다.
1. push X: 정수 X를 스택에 넣는 연산이다.
2. pop: 스택에서 가장 위에 있는 정수를 빼고, 그 수를 출력한다. 만약 스택에 들어있는 정수가 없는 경우에는 -1을 출력한다.
3. size: 스택에 들어있는 정수의 개수를 출력한다.
4. empty: 스택이 비어있으면 1, 아니면 0을 출력한다.
5. top: 스택의 가장 위에 있는 정수를 출력한다. 만약 스택에 들어있는 정수가 없는 경우에는 -1을 출력한다.
======
- 스택배열 첫번째 idx값을 1로 생각하고 푼다.
- 스택 라이브러리는 이용하지 않고 풀었다.

*/

int main() {

  int N, x, data[10001], idx = 0;
  string str;
  cin >> N;

  for (int i = 0; i < N; i++) {

    cin >> str;

    if (str == "push"){
      cin >> x;
      data[++idx] = x; // 스택의 첫번째 idx값 1 설정
    }
    else if(str == "pop"){
      if(idx == 0){
        cout << "-1" << endl;
      }
      else{
        cout << data[idx] << endl;
        data[idx--] = 0;
      }
    }
    else if(str == "size"){
      cout << idx << endl;
    }
    else if(str == "empty"){
      if (idx == 0) {
        cout << "1" << endl;
      }
      else{
        cout << "0" << endl;
      }
    }
    else if(str == "top"){
      if(idx == 0){
        cout << "-1" << endl;
      }
      else{
        cout << data[idx] << endl;
      }
    }

  }
  return 0;
}
