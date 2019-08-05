#include <iostream>
#include <queue>
using namespace std;
//https://www.acmicpc.net/problem/2206

/*
<벽 부수고 이동하기>
주요: BFS
1. 미로탐색(2178)과 비슷한 문제이다.
2. BFS로 탐색하되 각 지점마다 벽을 뚫고 도착했는지, 그냥 도착했는지를 큐에 넣어 전달해준다.
  (x , y : 현재 위치 , (0 or 1) : 벽을 부순지 여부) => 이 값을 큐에 넣어 전달
  => 벽을 부시지 않고 왔다
    a. 방문하지 않았고 벽이면 부순다. (x, y, 1)
    b. 방문하지 않았고 벽이 없으면 계속 진행한다. (x, y, 0)
    c. 방문했다 (continue)
  => 벽을 부시고 왔다.
    a. 방문하지 않았고 벽이 아니다 (x, y, 1)
    b. 방문하지 않았지만 벽이다 (continue)
    c. 방문했다. (continue)
3. 2번 조건에 맞게 BFS로 탐색하고 한번 움직일때마다 cnt값을 더해준다.
4. 탐색결과값을 출력한다.
  => 탐색 도중 해당 좌표를 찾으면 cnt 출력
  => 큐가 빌때까지 탐색했지만 좌표에 도착하지 못하면 -1 출력

==========
* 벽을 하나씩 부시고 모든 경우를 계산하는 방법(브루트 포스, BFS)으로 풀었더니 당연히 시간초과가 났다.
 -> 그때 그때 벽을 부셨는지 판단하는 변수를 넣어서 계산했다.

*/

typedef struct Loc{

  int x;
  int y;
  int broken;

}loc;

int N, M;
int cal_x[4] = {-1, 0 ,1 , 0}, cal_y[4] = {0, -1, 0, 1};
int wall[1001][1001] = {0, }, visit[1001][1001][2] = {0, };
queue<loc> que;

void bfs(int x, int y, int broken){

  int temp_x, temp_y;

  for (int i = 0; i < 4; i++) {
    temp_x = x + cal_x[i];
    temp_y = y + cal_y[i];

    if(temp_x >= 0 && temp_x < N && temp_y >= 0 && temp_y < M){

      // 2번
      if(broken == 0){
        // 안부시고 왔을 때
        if(visit[temp_x][temp_y][0] == 1){
          // 방문 했을 때
          continue;
        }
        else{
          //방문 안 했을 때
          if(wall[temp_x][temp_y] == 0){
            // 벽 안 부수고 진행
            loc temp = {temp_x, temp_y, 0};
            que.push(temp);
            visit[temp_x][temp_y][0] = 1;
          }
          else{
            // 벽을 부수고 진행
            loc temp = {temp_x, temp_y, 1};
            que.push(temp);
            visit[temp_x][temp_y][1] = 1;
          }
        }
      }
      else{
        // 부시고 온거
        if(visit[temp_x][temp_y][1] == 1){
          // 방문했을 때
          continue;
        }
        else{
          //방문 안 했을 때
          if(wall[temp_x][temp_y] == 0){
            // 그대로 진행
            loc temp = {temp_x, temp_y, 1};
            que.push(temp);
            visit[temp_x][temp_y][1] = 1;
          }
        }
      }
    }
  }
}

int main() {

  scanf("%d %d", &N, &M);

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      scanf("%1d", &wall[i][j]);
    }
  }

  loc l = {0, 0, 0};
  que.push(l);
  visit[0][0][0] = 1;

  int temp_size, cnt = 0;
  bool end_game = false;

  while (!que.empty()) {
    int temp_size = que.size();
    for (int i = 0; i < temp_size; i++) {
      bfs(que.front().x, que.front().y, que.front().broken);
      if(que.front().x == (N-1) && que.front().y == (M-1)){ end_game = true;} // N, M까지 갔을 때
      que.pop();
    }
    cnt++;
    if(end_game) { break;}
  }

  // 4번 (게임이 정상적으로 끝났으면 출력)
  if(end_game){
    printf("%d\n", cnt);
  }
  else{
    printf("-1\n");
  }

  return 0;

}
