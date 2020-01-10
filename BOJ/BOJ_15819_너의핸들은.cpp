#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
//https://www.acmicpc.net/problem/15819

/*
<너의 핸들은>
주요: sort 정렬
1. handle을 입력받아 sort함수로 정렬 시킨다.
2. 정렬시킨 벡터에서 타켓 M-1 번째 값을 출력시킨다.

==========
* 처음에 양 끝값을 핸들 값으로 놓는줄 알았다.
  => 그냥 입력 그대로 base값이 habdle 값이다.

*/

int main() {

  int N, M;
  cin >> N >> M;

  vector<string> handles;

  for (int i = 0; i < N; i++) {
    string input;
    cin >> input;
    handles.push_back(input);
  }

  sort(handles.begin() ,handles.end());

  cout << handles[M-1];

  return 0;
}
