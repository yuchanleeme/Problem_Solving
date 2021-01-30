#include <bits/stdc++.h>
using namespace std;
//https://www.acmicpc.net/problem/14923

/*
<미로 탈출>
주요: BFS
1. BFS 탐색을 통해 출구를 찾는다.
2. mazeVisit[x][y][remain] : (x, y) 위치에 i 번 마법을 쓸 수 있는 상태로 왔는지 확인
  2-1. ex) mazeVisit[2][3][1] = 1 : (2,3) 위치에 1번 마법을 쓸 수 있는 상태여서 도착한적이 있음
  2-2. 방문했다면, 방문한 상황에 맞게 방문처리를 한다.
3. 3가지 경우로 나눠서 큐에 넣을지 판단한다. (아래는 모두 해당 상황에 맞게 방문한적이 없을 때를 전제로 한다.)
  3-1. 마법을 쓸 수 없을 때
  3-2. 마법을 쓸 수 있지만 마법을 쓰지 않고 방문히려고 할 때
  3-3. 마법을 쓸 수 있고, 마법을 쓰면서 방문하려고 할 때
4. 출구를 나오면 해당 time을 출력한다.

*/

typedef struct info{
  int x; int y; int magic;
}Info;

int N, M, stx, sty, edx, edy;
int maze[1010][1010];
int mazeVisit[1010][1010][3]; // 2번
int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};

int main(int argc, char const *argv[]) {
  cin >> N >> M;
  cin >> stx >> sty >> edx >> edy;

  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= M; j++) {
      cin >> maze[i][j];
    }
  }

  int time = 0;
  queue<Info> que;
  que.push({stx, sty, 1});
  mazeVisit[stx][sty][1] = 1;

  while (!que.empty()) {
    int temp_size = que.size();
    time++;
    for (size_t i = 0; i < temp_size; i++) {
      for (size_t j = 0; j < 4; j++) {
        int nx = que.front().x + dx[j];
        int ny = que.front().y + dy[j];
        int remain = que.front().magic;
        if(nx == edx && ny == edy) return !printf("%d", time);
        if(nx < 1 || ny < 1 || nx > N || ny > M) continue;

        if(remain == 0){ // 3-1번
          if(maze[nx][ny] == 1 || mazeVisit[nx][ny][0] == 1) continue;
          else{
            mazeVisit[nx][ny][0] = 1;
            que.push({nx, ny, remain});
          }
        }
        else{
          if(maze[nx][ny] == 1){ // 3-3번
            if(mazeVisit[nx][ny][0] == 1) continue;
            else{
              mazeVisit[nx][ny][0] = 1;
              que.push({nx, ny, remain-1}); // 마법을 쓰니까 remain-1 해서 큐에 넣는다.
            }
          }
          else{ // 3-2번
            if(mazeVisit[nx][ny][1] == 1) continue;
            else{
              mazeVisit[nx][ny][1] = 1;
              que.push({nx, ny, remain});
            }
          }
        }
      }
      que.pop();
    }
  }
  cout << -1 << endl;

  return 0;
}
