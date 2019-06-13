#include <iostream>
#include <queue>
using namespace std;
//https://www.acmicpc.net/problem/11866

/*
<조세퍼스 문제 0>
주요: 원형큐를 이용하여 풀어보자.
1. 맨 앞 숫자를 pop 해서 front를 큐의 끝에 push하여 원형큐를 구현한다.
2. K번 pop,push를 하고 마지막 K번째에서는 pop만하고 반복한다.

*/

int main() {

  int N, K;
  queue<int> que;

  cin >> N >> K;

  for (int i = 1; i <= N; i++) {
    que.push(i);
  }

  cout << "<";
  while (que.size() != 0) {
    for (int j = 1; j < K; j++) {
      que.push(que.front());
      que.pop();
    }
    if (que.size() == 1) {
      cout << que.front();
      break;
    }
    cout << que.front() << ", ";
    que.pop();
  }
  cout << ">";

  return 0;
}
