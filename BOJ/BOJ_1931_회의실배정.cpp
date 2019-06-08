#include <iostream>
#include <queue>
using namespace std;
//https://www.acmicpc.net/problem/11047

/*
<회의실 배정 >
주요: 그리디 알고리즘을 활용한다.
1. 끝나는 시간이 가장 빠른 회의를 고른다.
2. 그 다음 들어갈 수 있는 회의 중에 끝나는 시간이 가장 빠른 회의를 고른다.
3. 위의 과정을 반복 해서 더이상 조건에 해당하는 회의가 없을 때까지 고른다.
4. 회의를 고를 때마다 count값을 더해서 출력한다.

*/
typedef struct Conf{
  int start;
  int end;
}Conf;

int main() {

  int N, compare_value, temp, count = 0;
  Conf conf;
  queue<Conf> que;
  bool is_exist_trigger;

  cin >> N;

  for (int i = 0; i < N; i++) {
    cin >> conf.start >> conf.end;
    que.push(conf);
  }
  //큐가 빌 때까지
  while(!que.empty()){
    is_exist_trigger = false;
    compare_value = que.front().end;
    printf("compare_value : %d \n",compare_value);
    printf("count : %d\n",count);

    // 1번 조건
    for (int i = 0; i < que.size(); i++) {
      if (compare_value > que.front().end) {
        compare_value = que.front().end;
        printf("===== compare_value : %d\n",compare_value);
      }
      que.push(que.front());
      que.pop();
    }

    temp = que.size();
    for (int i = 0; i < temp; i++) {
      if (compare_value > que.front().start) {
        que.pop();
        if(compare_value == que.front().end){
          is_exist_trigger = true;
        }
      }
      else if(compare_value == que.front().start){
        if(compare_value == que.front().end){
          que.pop();
          count++;
          printf("what %d\n",que.front().end);
        }
      }
      else{
        que.push(que.front());
        que.pop();
      }
    }
    printf("<2>count : %d\n",count);
    if (is_exist_trigger) {
      count++;
    }
    printf("===================================\n");
  }

  cout << count;

  // for (int i = 0; i < N; i++) {
  //   cin << conf[i][0] << conf[i][1]; // 0 : 시작 , 1: 끝
  // }
  //
  // compare_value = conf[j][1];
  // while(true){
  //   for (int j = 0; j < N; j++) {
  //     if(conf[j][1] < compare_value){
  //       compare_value = conf[j][1];
  //     }
  //   }
  // }
  //
  //
  // cout << "aaaaa"<< endl;
  return 0;
}
