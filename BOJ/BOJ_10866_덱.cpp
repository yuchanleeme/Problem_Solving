#include <iostream>
using namespace std;
//https://www.acmicpc.net/problem/10866

/*
<덱 >
주요: 직접 덱 자료구조를 만들어 본다.
1. push_front X: 정수 X를 덱의 앞에 넣는다.
2. push_back X: 정수 X를 덱의 뒤에 넣는다.
3. pop_front: 덱의 가장 앞에 있는 수를 빼고, 그 수를 출력한다. 만약, 덱에 들어있는 정수가 없는 경우에는 -1을 출력한다.
4. pop_back: 덱의 가장 뒤에 있는 수를 빼고, 그 수를 출력한다. 만약, 덱에 들어있는 정수가 없는 경우에는 -1을 출력한다.
5. size: 덱에 들어있는 정수의 개수를 출력한다.
6. empty: 덱이 비어있으면 1을, 아니면 0을 출력한다.
7. front: 덱의 가장 앞에 있는 정수를 출력한다. 만약 덱에 들어있는 정수가 없는 경우에는 -1을 출력한다.
8. back: 덱의 가장 뒤에 있는 정수를 출력한다. 만약 덱에 들어있는 정수가 없는 경우에는 -1을 출력한다.

*/

int main() {

  int N, x, data[10001], size = 0;
  string str;
  cin >> N;

  for (int i = 0; i < N; i++) {

    cin >> str;

    if (str == "push_front"){
      cin >> x;
      for (int j = size; j > 0; j--) {
        data[j] = data[j-1];
      }
      data[0] = x;
      size += 1;
    }
    else if(str == "push_back"){
      cin >> x;
      data[size] = x;
      size += 1;
    }
    else if(str == "pop_front"){
      if(size == 0){
        cout << "-1" << endl;
      }
      else{
        cout << data[0] << endl;
        size -= 1;
        for (int j = 0; j < size; j++) {
          data[j] = data[j+1];
        }
      }
    }
    else if(str == "pop_back"){
      if(size == 0){
        cout << "-1" << endl;
      }
      else{
        cout << data[size-1] << endl;
        data [size-1] = 0;
        size -= 1;
      }
    }
    else if(str == "size"){
      cout << size << endl;
    }
    else if(str == "empty"){
      if (size == 0) {
        cout << "1" << endl;
      }
      else{
        cout << "0" << endl;
      }
    }
    else if(str == "front"){
      if(size == 0){
        cout << "-1" << endl;
      }
      else{
        cout << data[0] << endl;
      }
    }
    else if(str == "back"){
      if(size == 0){
        cout << "-1" << endl;
      }
      else{
        cout << data[size-1] << endl;
      }
    }
  }
  return 0;
}
