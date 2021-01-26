#include <bits/stdc++.h>
using namespace std;
//https://www.acmicpc.net/problem/6593

/*
<상범 빌딩>
주요: BFS
1. 각 층에 대한 정보를 각 테스트 케이스마다 입력을 받는다.
2. 6방향 BFS를 돌려서 최단거리를 구해 출력한다.
3. 큐가 빌 때까지 찾지 못했으면 Trapped를 출력한다.

*/

typedef struct info{
  int l;
  int r;
  int c;
}Info;

int L, R, C;

// 상하, 4방향
int dl[6] = {1, -1, 0, 0, 0, 0}, dr[6] = {0, 0, 1, -1, 0, 0}, dc[6] = {0, 0, 0, 0, 1, -1};

void bfs(int L, int R, int C) {

  vector<vector<string> > building;
  Info st, ed;

  for (int i = 0; i < L; i++) {
    vector<string> floor;
    for (int j = 0; j < R; j++) {
      string line; cin >> line;
      for (int k = 0; k < C; k++) {
        if(line[k] == 'S') st = {i,j,k};
        if(line[k] == 'E') ed = {i,j,k};
      }
      floor.push_back(line);
    }
    building.push_back(floor);
  }

  int mapVisit[55][55][55] = {0, };
  int cnt = 0;
  queue<Info> que;

  que.push(st);
  mapVisit[st.l][st.r][st.c] = 1;
  while (!que.empty()) {
    int temp_size = que.size();
    cnt++;
    for (size_t i = 0; i < temp_size; i++) {
      for (size_t j = 0; j < 6; j++) {
        int nl = que.front().l + dl[j];
        int nr = que.front().r + dr[j];
        int nc = que.front().c + dc[j];

        if(nl < 0 || nr < 0 || nc < 0 || nl >= L || nr >= R || nc >= C) continue;
        if(mapVisit[nl][nr][nc] == 0){
          if(building[nl][nr][nc] == '.'){
            mapVisit[nl][nr][nc] = 1;
            que.push({nl, nr, nc});
          }
          else if(building[nl][nr][nc] == 'E'){
            cout << "Escaped in " << cnt <<" minute(s).\n";
            return;
          }
        }
      }
      que.pop();
    }
  }
  cout << "Trapped!" << "\n";
}

int main(int argc, char const *argv[]) {
  cin.tie(NULL); ios::sync_with_stdio(false);

  while(true){
    cin >> L >> R >> C;
    if(!L && !R && !C) break;
    bfs(L, R, C);
  }
  return 0;
}
