#include <iostream>
using namespace std;
//https://www.acmicpc.net/problem/10845

/*
<큐>
주요: 직접 큐 자료구조를 만들어 본다.
1. push X: 정수 X를 큐에 넣는 연산이다.
2. pop: 큐에서 가장 앞에 있는 정수를 빼고, 그 수를 출력한다. 만약 큐에 들어있는 정수가 없는 경우에는 -1을 출력한다.
3. size: 큐에 들어있는 정수의 개수를 출력한다.
4. empty: 큐가 비어있으면 1, 아니면 0을 출력한다.
5. front: 큐의 가장 앞에 있는 정수를 출력한다. 만약 큐에 들어있는 정수가 없는 경우에는 -1을 출력한다.
6. back: 큐의 가장 뒤에 있는 정수를 출력한다. 만약 큐에 들어있는 정수가 없는 경우에는 -1을 출력한다.

*/

int main() {

  int N, x, data[10001], idx_in = 0 , idx_out = 0;
  string str;
  cin >> N;

  for (int i = 0; i < N; i++) {

    cin >> str;

    if (str == "push"){
      cin >> x;
      data[idx_in++] = x;
    }
    else if(str == "pop"){
      if(idx_in == idx_out){
        cout << "-1" << endl;
      }
      else{
        cout << data[idx_out] << endl;
        data[idx_out++] = 0;
      }
    }
    else if(str == "size"){
      cout << idx_in - idx_out << endl;
    }
    else if(str == "empty"){
      if (idx_in == idx_out) {
        cout << "1" << endl;
      }
      else{
        cout << "0" << endl;
      }
    }
    else if(str == "front"){
      if(idx_in == idx_out){
        cout << "-1" << endl;
      }
      else{
        cout << data[idx_out] << endl;
      }
    }
    else if(str == "back"){
      if(idx_in == idx_out){
        cout << "-1" << endl;
      }
      else{
        cout << data[idx_in - 1] << endl;
      }
    }
  }
  return 0;
}
