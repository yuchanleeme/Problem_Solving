#include <iostream>
#include <queue>
using namespace std;
//https://www.acmicpc.net/problem/1927

/*
<최소 힙>
주요: 힙
1. 우선순위 큐를 이용해 구현한다. (greater)
2. 0 일때 각자의 조건에 맞게 구현한다.
  => 큐가 비어있다면 0 출력, 큐가 비어있지 않다면 최솟값 출력
3. 0이 아닌 경우에는 큐에 삽입한다.

*/

int main() {

  priority_queue<int, vector<int>, greater<int> > que;
  int N, input;

  scanf("%d", &N);

  for (int i = 0; i < N; i++) {

    scanf("%d", &input);

    if(input == 0){
      if(que.empty()){
        printf("0\n");
      }
      else{
        printf("%d\n", que.top());
        que.pop();
      }
    }
    else{
      que.push(input);
    }
  }
  return 0;
}
