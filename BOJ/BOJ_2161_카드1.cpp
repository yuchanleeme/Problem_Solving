#include <iostream>
#include <queue>
using namespace std;
//https://www.acmicpc.net/problem/2161

/*
<카드 1>
주요: 큐를 이용하여 풀자.
1. N까지 차례대로 큐에 push한다.
2. 그다음 큐에서 ( front 출력 -> pop -> front를 push -> pop) 을 반복한다.
3. 큐가 empty 일 때까지 반복.

*/

int main() {

  int N;
  queue<int> que;

  cin >> N;

  for (int i = 1; i <= N; i++) {
    que.push(i);
  }

  while (que.size() != 0) {
    cout << que.front() <<" ";
    que.pop();
    que.push(que.front());
    que.pop();
  }

  return 0;
}
