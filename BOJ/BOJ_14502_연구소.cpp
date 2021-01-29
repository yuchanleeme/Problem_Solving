#include <bits/stdc++.h>
using namespace std;
//https://www.acmicpc.net/problem/14502

/*
<연구소>
주요: BFS, DFS
1. 벽을 놓을 위치 3개를 백트래킹을 통해 찾는다.
2. 벽을 놓고 Test를 진행하는데 이때 바이러스의 위치를 큐에 모두 넣고 방문처리한다.
3. BFS 탐색을 통해 바이러스를 퍼뜨리고 안전영역의 개수를 센다.
4. 그 중 최댓값을 출력한다.

*/

int N, M, ans;
int lab[9][9];
int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
vector<pair<int, int> > seq;

void virusTest(){

  int testLab[9][9] = {0, };
  int labVisit[9][9] = {0, };
  queue<pair<int, int> > virus;

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      testLab[i][j] = lab[i][j];
      if(testLab[i][j] == 1) labVisit[i][j] = 1;
      else if(testLab[i][j] == 2){
        virus.push({i, j});
        labVisit[i][j] = 1;
      }
    }
  }

  for (int i = 0; i < seq.size(); i++) {
    testLab[seq[i].first][seq[i].second] = 1;
    labVisit[seq[i].first][seq[i].second] = 1;
  }

  while (!virus.empty()) {
    int temp_size = virus.size();
    for (int i = 0; i < temp_size; i++) {
      for (int j = 0; j < 4; j++) {
        int nx = virus.front().first + dx[j];
        int ny = virus.front().second + dy[j];

        if(nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
        if(labVisit[nx][ny] == 1) continue;
        if(testLab[nx][ny] == 0){
          labVisit[nx][ny] = 1;
          testLab[nx][ny] = 2;
          virus.push({nx, ny});
        }
      }
      virus.pop();
    }
  }

  int cnt = 0;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      if(testLab[i][j] == 0) cnt++;
    }
  }
  ans = max(ans, cnt);
}

void dfs(int x, int y, int level){

  if(level == 3){
    virusTest();
    return;
  }

  for (int j = y; j < M; j++) {
    if(lab[x][j] == 0){
      seq.push_back({x, j});
      dfs(x,j+1,level+1);
      seq.pop_back();
    }
  }

  for (int i = x+1; i < N; i++) {
    for (int j = 0; j < M; j++) {
      if(lab[i][j] == 0){
        seq.push_back({i, j});
        dfs(i,j+1,level+1);
        seq.pop_back();
      }
    }
  }
}

int main(int argc, char const *argv[]) {
  cin >> N >> M;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      cin >> lab[i][j];
    }
  }
  dfs(0, 0, 0);
  cout << ans;
  return 0;
}
