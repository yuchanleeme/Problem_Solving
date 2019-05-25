#include <iostream>
#include <queue>
using namespace std;
//https://www.acmicpc.net/problem/1966

/*
<프린터 큐>
주요: 큐를 이용하여 풀자.
1. 구조체를 이용해 중요도와 처음 위치를 저장한다.
2. 현재 큐에서 가장 중요도가 높은 값을 구한다.
3. 그 값을 찾을때까지 큐의 front 값을 큐에 push 하고 찾으면 pop한다.
4.  2,3번을 큐가 빌 때까지 하고 한번 pop할때마다 res 값을 올려준다.
5. 마지막에 res를 출력하여 값을 도출한다.

*/

// 1번
typedef struct Print {
  int impt;
  int first_location;
} Print;

int main() {

  int T, N, M, res, highest_impt;
  bool end_trigger;

  scanf("%d", &T);

  for (int i = 0; i < T; i++) {

    scanf("%d %d", &N, &M);

    // 값 초기화
    Print prt[N];
    queue <Print> que;
    end_trigger = true;
    res = 0;
    highest_impt = 0;

    // q에 처음 위치, 중요도 push하기
    for (int j = 0; j < N; j++) {
      scanf("%d", &prt[j].impt);
      prt[j].first_location = j;
      que.push(prt[j]);
    }

    while (end_trigger) {
      // 2번
      for (int k = 0; k < que.size(); k++) {
        if(highest_impt < que.front().impt){
          highest_impt = que.front().impt;
        }
        que.push(que.front());
        que.pop();
      }

      // 3,4번
      while (!que.empty()) {
        if(que.front().impt == highest_impt){
          if (que.front().first_location == M) {
            end_trigger = false;
          }
          que.pop();
          res += 1;
          highest_impt = 0;
          break;
        }
        que.push(que.front());
        que.pop();
      }
    }

    // 5번
    printf("%d\n",res);
  }
  return 0;
}
