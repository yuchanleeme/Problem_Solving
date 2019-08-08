#include <iostream>
#include <queue>
#include <cmath>
using namespace std;
//https://www.acmicpc.net/problem/11286

/*
<절댓값 힙>
주요: 힙
1. 우선순위 큐를 활용한다.
2. 우선순위 큐에서 pair를 넣으면 첫번째값, 두번째값 순으로 비교한다는것을 이용한다.
  2-1 첫번째 값 : 절댓값이 작은 순이기 때문에 첫번째 값으로 -1 과 절댓값 input을 곱해준다.
  2-2 두번째 값 : 절댓값이 같다면 음수부터 출력해야 하기 때문에 -1과 절댓값 input을 곱해준다.
3. 출력할 때 second 값에 -1을 곱해주어 처음 input값으로 만들어 준다.

*/

int main() {

  int N, input;
  priority_queue<pair<int, int> > que;

  scanf("%d", &N);

  for (int i = 0; i < N; i++) {

    scanf("%d", &input);

    if(input == 0){
      if(que.empty()){
        printf("0\n");
      }
      else{
        printf("%d\n", -1 * que.top().second);
        que.pop();
      }
    }
    else{
      que.push(-1 * make_pair(abs(input), -1 * input));
    }
  }

  return 0;
}
