#include <iostream>
#include <deque>
using namespace std;
//https://www.acmicpc.net/problem/1021

/*
<회전하는 큐 >
주요: 2,3번을 모두 비교해서 그 중 최솟값을 더해준다.
1. 1부터 N까지 큐값을 저장시킨다.
2. 왼쪽, 오른쪽 연산을 각각 수행한다.
3. 그 수행한 연산값 중 최솟값이 나오는 연산을 수행한다.
4. 최솟값을 모두 더한 값을 출력한다.

*/

// 왼쪽 이동 연산값 리턴
int left_move(deque<int> dq, int data) {

  int res = 0;

  for (int i = 0; i < dq.size(); i++) {
    if (dq.front() == data) {
      break;
    }
    else{
      res += 1;
      dq.push_back(dq.front());
      dq.pop_front();
    }
  }
  return res;
}

// 오른쪽 이동 연산값 리턴
int right_move(deque<int> dq, int data){

  int res = 0;

  for (int i = 0; i < dq.size(); i++) {
    if (dq.front() == data) {
      break;
    }
    else{
      res += 1;
      dq.push_front(dq.back());
      dq.pop_back();
    }
  }
  return res;
}

int main() {

  int N, M, val_left, val_right;
  int sum = 0;
  deque <int> dq;
  scanf("%d %d", &N, &M);

  int data[M];
  for (int i = 0; i < M; i++) {
    scanf("%d", &data[i]);
  }

  // 1번
  for (int i = 1; i <= N; i++) {
    dq.push_back(i);
  }

  for (int i = 0; i < M; i++) {
    // 2번
    val_right = right_move(dq,data[i]);
    val_left = left_move(dq,data[i]);

    // 3,4번
    if (val_right < val_left) {
      sum += val_right;

      for (int j = 0; j < val_right; j++) {
        dq.push_front(dq.back());
        dq.pop_back();
      }
      dq.pop_front();
    }
    else{
      sum += val_left;

      for (int j = 0; j < val_left; j++){
        dq.push_back(dq.front());
        dq.pop_front();
      }
      dq.pop_front();
    }
  }

  printf("%d", sum);

  return 0;

}
