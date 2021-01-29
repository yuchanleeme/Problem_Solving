#include <bits/stdc++.h>
using namespace std;
//https://www.acmicpc.net/problem/1600

/*
<말이 되고픈 원숭이>
주요: BFS, 아이디어
1. BFS 탐색을 통해 원숭이가 도착점에 도달하는지 판단한다.
2. 이를 위해 방문 배열을 설정한다.
  2.1 boardVisit[x][y][move] : (x,y) 지점에 move만큼 이동횟수가 남은 채로 온 적이 있다.
3. 12가지 경우의 수를 이용해 원숭이의 다음 위치를 계산해 큐에 넣는다.
  3.1 (0~3 : 상하좌우, 4~11 말처럼 이동)
  3.2 남은 이동 횟수가 0이라면 말처럼 이동하지 않는다.
  3.3 만약에 방문한 곳이 해당 이동 횟수를 통해 이미 방문한 곳이 아닐때만 큐에 넣어준다.
4. 도착점에 도달하면 현재 이동한 횟수를 출력한다.
5. 큐가 빌 동안 도달하지 못한다면 -1을 출력한다.
==========
* 방문 배열 처리 때문에 애먹었던 문제

*/

typedef struct info{
  int x;
  int y;
  int move;
}Info;

int K, W, H;
int board[210][210];
int boardVisit[210][210][35];
int dx[12] = {1,0,-1,0,-1,-2,-2,-1,1,2,2,1};
int dy[12] = {0,1,0,-1,-2,-1,1,2,-2,-1,1,2};

int main(int argc, char const *argv[]) {

  scanf("%d %d %d", &K, &W, &H);
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      scanf("%d ", &board[i][j]);
    }
  }

  if(W == 1 && H == 1) return !printf("0");
  int move = 0;
  queue<Info> que;
  que.push({0,0,K});
  boardVisit[0][0][K] = 1;

  while (!que.empty()) {
    int temp_size = que.size();
    move++;
    for (int i = 0; i < temp_size; i++) {
      for (int j = 0; j < 12; j++) {
        int nx = que.front().x + dx[j];
        int ny = que.front().y + dy[j];
        int remain = que.front().move;

        if(nx == H-1 && ny == W-1) return !printf("%d", move);

        if(remain == 0 && j >= 4) break;
        if(nx < 0 || ny < 0 || nx >= H || ny >= W) continue;
        if(board[nx][ny] == 1) continue;

        if(j < 4 && boardVisit[nx][ny][remain] == 0){
          boardVisit[nx][ny][remain] = 1;
          que.push({nx, ny, remain});
        }
        else if(j >= 4 && boardVisit[nx][ny][remain-1] == 0){
          boardVisit[nx][ny][remain-1] = 1;
          que.push({nx, ny, remain-1});
        }

      }
      que.pop();
    }
  }

  printf("-1");

  return 0;
}
