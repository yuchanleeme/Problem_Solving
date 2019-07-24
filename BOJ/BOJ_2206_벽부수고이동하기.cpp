#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
//https://www.acmicpc.net/problem/2206

/*
<벽 부수고 이동하기>
주요: BFS , 브루트포스
1.

*/


int N, M, cnt = 0;
int cal_x[4] = {-1, 0 ,1 , 0}, cal_y[4] = {0, -1, 0, 1};
int wall[1001][1001] = {0, }, base_visit[1001][1001] = {0, }, visit[1001][1001] = {0, };
queue<pair<int, int> > que;

void bfs(int x, int y){

  int temp_x, temp_y;

  for (int i = 0; i < 4; i++) {
    temp_x = x + cal_x[i];
    temp_y = y + cal_y[i];

    if(temp_x >= 0 && temp_x < N && temp_y >= 0 && temp_y < M){
      if(visit[temp_x][temp_y] == 0 && wall[temp_x][temp_y] == 0){
        printf("%d %d\n",temp_x,temp_y);
        que.push(make_pair(temp_x, temp_y));
        visit[temp_x][temp_y] = 1;
      }
    }
  }
}

int main() {

  vector<pair<int, int> > broken;

  freopen("1aa.txt", "r", stdin);

  scanf("%d %d", &N, &M);
  int ans = N*M;

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      scanf("%1d", &wall[i][j]);
      if(wall[i][j] == 1){
        base_visit[i][j] = 1;
        broken.push_back(make_pair(i,j));
      }
      else if(wall[i][j] == 0){
        base_visit[i][j] = 0;
      }
    }
  }

  //wall이 다 0 일때를 고려
  if(broken.size() == 0){
    broken.push_back(make_pair(0,0));
  }

  for (int b = 0; b < broken.size(); b++) {

    int temp_size;
    bool end_game = false;
    cnt = 0;
    while(!que.empty()){ que.pop();}

    // visit 복사
    for (int p = 0; p < N; p++) {
      for (int q = 0; q < M; q++) {
        visit[p][q] = base_visit[p][q];
      }
    }

    // 벽 하나씩 부시는 경우
    int temp_p = broken[b].first, temp_q = broken[b].second;
    wall[temp_p][temp_q] = 0;
    visit[temp_p][temp_q] = 0;

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

    if(end_game){
      ans = min(ans, cnt);
    }
    // 부신 벽 복구
    wall[temp_p][temp_q] = 1;
    visit[temp_p][temp_q] = 0;
    printf("============================\n");
  }

  if(ans == N*M){
    printf("-1\n");
  }
  else{
    printf("%d\n", ans);
  }
  return 0;

}
