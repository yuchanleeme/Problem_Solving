#include <bits/stdc++.h>
using namespace std;
//https://www.acmicpc.net/problem/2573

/*
<빙산>
주요: BFS, 그래프
1. 배열 두 개를 사용해 빙산의 정보를 갱신한다.
2. 현재 상태가 두 덩이 이상인지, 다 녹았는지 먼저 판단한다.
  => 두 덩이 이상이면 현재 흐른 시간을 출력하고, 다 녹았다면 0을 출력한다.
3. 상태 확인이 끝나면 Sink를 통해 얼음을 녹인다.
4. 얼음이 녹으면 age를 1 증가시킨다.
5. 위의 2,3,4 과정을 반복하면서 답을 출력한다.

*/

int N, M, age, check_island;
int prev_ice[330][330];
int next_ice[330][330];
int ice_visit[330][330];
int dx[4] = {-1, 1, 0, 0}, dy[4] = {0, 0, 1, -1};

void bfs(int x, int y){

  queue<pair<int, int> > que;
  ice_visit[x][y] = 1;
  que.push({x, y});

  while (!que.empty()) {
    int temp_size = que.size();
    for (int i = 0; i < temp_size; i++) {
      for (int j = 0; j < 4; j++) {
        int nx = que.front().first + dx[j];
        int ny = que.front().second + dy[j];
        if(nx < 0 || ny < 0|| nx >= N || ny >= M) continue;
        if(next_ice[nx][ny] != 0 && ice_visit[nx][ny] == 0){
          ice_visit[nx][ny] = 1;
          que.push({nx, ny});
        }
      }
      que.pop();
    }
  }

}

void sink(int x, int y){

  int cnt = 0;
  for (size_t i = 0; i < 4; i++) {
    int nx = x + dx[i];
    int ny = y + dy[i];

    if(nx < 0 || ny < 0|| nx >= N || ny >= M) continue;
    if(prev_ice[nx][ny] == 0) cnt++;
  }
  if(prev_ice[x][y] - cnt < 0) next_ice[x][y] = 0;
  else next_ice[x][y] = prev_ice[x][y] - cnt;

}

int main(int argc, char const *argv[]) {
  scanf("%d %d", &N, &M);

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      scanf("%d", &next_ice[i][j]);
    }
  }

  while (true) {
    check_island = 0;
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < M; j++) {
        if(next_ice[i][j] != 0 && ice_visit[i][j] == 0){
          check_island++;
          bfs(i, j);
        }
      }
    }

    if(check_island >= 2) return !printf("%d", age);
    int end_check = 0;
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < M; j++) {
        if(next_ice[i][j] == 0) end_check++;
        ice_visit[i][j] = 0;
        prev_ice[i][j] = next_ice[i][j];
      }
    }
    if(end_check == N*M) return !printf("0");

    for (int i = 0; i < N; i++) {
      for (int j = 0; j < M; j++) {
        if(prev_ice[i][j] != 0){
          sink(i,j);
        }
      }
    }
    age++;
  }

  return 0;
}
