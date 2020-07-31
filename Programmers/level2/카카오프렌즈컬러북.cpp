#include <iostream>
#include <vector>
using namespace std;
//https://programmers.co.kr/learn/courses/30/lessons/1829

/*
<카카오 프렌즈 컬러북>
주요: DFS
1. DFS 탐색을 해서 개수와 넓이를 구한다.
2. 정상적인 idx를 찹조해야하고, 방문하지 않은 정점이고 색깔이 같아야한다.
3. 개수와 최대 넓이를 구하면 된다.

*/

int M, N;
int area, area_size;
int visit[110][110];
int dx[4] = {1, -1, 0, 0}, dy[4] = {0, 0, 1, -1};

void dfs(int x, int y, int color){
  for (int i = 0; i < 4; i++) {
    int nx = x + dx[i];
    int ny = y + dy[i];

    if(nx < 0 || nx >= M || ny < 0 || ny >= N || visit[nx][ny] != color) continue;
    visit[nx][ny] = 0;
    area_size++;
    dfs(nx, ny, color);
  }
}

vector<int> solution(int m, int n, vector<vector<int>> picture) {
  vector<int> answer(2, 0);
  M = m, N = n;
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      if(picture[i][j] != 0) visit[i][j] = picture[i][j];
    }
  }

  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      if(visit[i][j] != 0){
        visit[i][j] = 0;
        answer[0]++;
        dfs(i, j, picture[i][j]);
        answer[1] = max(answer[1], area_size+1);
        area_size = 0;
      }
    }
  }
  return answer;
}
