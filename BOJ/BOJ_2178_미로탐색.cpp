#include <iostream>
#include <vector>
#include <queue>
using namespace std;
//https://www.acmicpc.net/problem/2178

/*
<미로탐색>
주요: BFS
1. 최단거리를 구하는 것이기 때문에 BFS로 탐색한다.
2. 이미 방문한 곳은 방문하지 않고 계속 나아간다.
3. 탐색할때마다 count해준다.
4. count 값을 출력한다.
5. 전체 경우를 보는게 아니라 N, M 까지만 찾는다는것을 생각하자.
==========
* BFS 메모리초과 원인 : 큐에 삽입할 때 방문처리를 해야 중복 방지

*/

int N, M, cnt = 0;
int cal_x[4] = {-1, 0 ,1 , 0}, cal_y[4] = {0, -1, 0, 1};
int maze[101][101] = {0, }, visit[101][101] = {0, };
queue<pair<int, int> > que;

void bfs(int x, int y){

  int temp_x, temp_y;

  for (int i = 0; i < 4; i++) {
    temp_x = x + cal_x[i];
    temp_y = y + cal_y[i];

    if(temp_x >= 0 && temp_x < N && temp_y >= 0 && temp_y < M){
      if(visit[temp_x][temp_y] == 0 && maze[temp_x][temp_y] == 1){
        que.push(make_pair(temp_x, temp_y));
        visit[temp_x][temp_y] = 1;
      }
    }
  }
}

int main() {

  scanf("%d %d", &N, &M);

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      scanf("%1d", &maze[i][j]);
      if(maze[i][j] == 0){
        visit[i][j] = 1;
      }
    }
  }

  int temp_size;
  bool end_game = false;
  que.push(make_pair(0,0));
  visit[0][0] = 1;
  while (!que.empty()) {
    temp_size = que.size();
    for (int i = 0; i < temp_size; i++) {
      bfs(que.front().first, que.front().second);
      if(que.front().first + que.front().second == N + M - 2){ end_game = true;} // N, M까지 갔을 때
      que.pop();
    }
    cnt++;
    if(end_game) { break;}
  }

  printf("%d\n", cnt);
  return 0;
}
