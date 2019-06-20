#include <iostream>
#include <queue>
using namespace std;
//https://www.acmicpc.net/problem/7576

/*
<토마토>
주요: BFS
1. 배열에 입력을 받을때 익은토마토(1)는 큐에 push해주고 토마토가 없는 곳의 개수(no_placed)를 세준다.
2. 큐가 빌 때까지 토마토를 익게 하는 함수를 호출한다.
3. 토마토 익게 하는 함수
  => 토마토 전후좌우에 접근이 가능 하다면 그 토마토 배열값을 1로 만들고 위치를 큐에 push
  => 이 토마토의 위치를 방문했음을 표시한다.
4. 큐가 비면 조건에 맞게 count값을 출력한다.

*/

int tomato[1010][1010];
int is_visited[1010][1010];
int M, N, no_placed = 0;
queue<pair<int,int>> que;

// 3번
void ripe_tomato(pair<int,int> val){
  int x[4] = {-1, 0, 0, 1}, y[4] = {0, -1, 1, 0};
  int val_x, val_y;

  for (int i = 0; i < 4; i++) {
    val_x = val.first - x[i];
    val_y = val.second - y[i];

    if((val_x >= 0 && val_x < N) && (val_y >= 0 && val_y < M)){
      if(tomato[val_x][val_y] == 0){
        tomato[val_x][val_y] = 1;
        que.push(pair<int,int>(val_x,val_y));
        is_visited[val_x][val_y] = 1;
      }
    }
  }
}

void bfs(){

  int num, count = 0;

  // 2번
  while(!que.empty()){
    num = que.size();
    for (int i = 0; i < num; i++) {
      ripe_tomato(que.front());
      que.pop();
    }
    count++;
  }

  // no_placed--의 계산결과 0이 된다면 -1인 부분을 제외하고 모든부분이 1로 채워졌다는 의미가 된다.
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      if(is_visited[i][j] != 1){
        no_placed--;
      }
    }
  }

  // 4번
  if(no_placed == 0){
    cout << count - 1;
  }
  else{
    cout << "-1";
  }

}

int main() {

  cin >> M >> N;

  // 1번
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      cin >> tomato[i][j];
      if(tomato[i][j] == 1){
        que.push(pair<int,int>(i,j));
        is_visited[i][j] = 1;
      }
      else if(tomato[i][j] == -1){
        no_placed++;
      }
    }
  }

  bfs();

  return 0;
}
