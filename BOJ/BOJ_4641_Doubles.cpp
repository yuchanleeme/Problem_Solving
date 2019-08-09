#include <iostream>
#include <vector>
using namespace std;
//https://www.acmicpc.net/problem/4641

/*
<Doubles>
주요: 구현
1. 200칸의 배열을 미리 0으로 초기화 해놓는다.
2. input을 받으면서 num[input] 의 값을 더한다.
3. 모든 input이 끝나면 vector안에 있는 값을 비교하면서 num배열이 0인지 아닌지 조사한다.
4. 0이 아니면 count해주고 다 센 뒤 그 값을 출력한다.

*/

int main() {

  bool end_game = false;

  while (true) {

    vector<int> v;
    int num[220] = {0, };
    int input, count = 0;

    while (cin >> input) {
      if(input == 0){ break;}
      else if(input == -1){
        end_game = true;
        break;
      }
      v.push_back(input);
      num[input]++;
    }

    if (end_game) {
      break;
    }

    for (int i = 0; i < v.size(); i++) {
      if(num[v[i]*2] != 0){
        count++;
      }
    }

    cout << count << endl;
  }

  return 0;
}
