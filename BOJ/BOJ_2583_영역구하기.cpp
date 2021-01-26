#include <bits/stdc++.h>
using namespace std;
//https://www.acmicpc.net/problem/2583

/*
<영역 구하기>
주요: BFS, 구현
1. 좌표로 주어진 값들을 배열화 하기 편하게 바꿔준다.
  1.1 x좌표 값들은 배열의 열 값으로 바꾼다. x1, x2 -> c
  1.3 x 좌표값은 변동 없이 그대로 c값으로 가면 된다.
  1.2 y좌표 값들은 배열의 행 값으로 바꾼다. y1, y2 -> r
  1.4 y 좌표값들은 순서가 바뀌므로 유의한다. ex) (M-1) - y1 -> r
  1.5 오른쪽 위 꼭짓점은 입력값에 1씩 빼줘서 계산해준다. ex) (4,5) -> (3,4)
2. 좌표를 구할때마다 area 배열을 for문을 이용해 1로 영역표시한다.
3. 이제 BFS 돌면서 각 영역의 크기를 구해 sort한 뒤 출력한다.

*/

int M, N, K;
vector<int> ans;
int area[110][110];
int areaVisit[110][110];
int dx[4]= {1, 0, -1, 0}, dy[4]= {0, 1, 0, -1};

void bfs(int x, int y){
  int cnt = 0;
  areaVisit[x][y] = 1;
  queue<pair<int, int> > que;
  que.push({x, y});
  while (!que.empty()) {
    int temp_size = que.size();
    cnt += temp_size;
    for (size_t i = 0; i < temp_size; i++) {
      for (size_t j = 0; j < 4; j++) {
        int nx = que.front().first + dx[j];
        int ny = que.front().second + dy[j];

        if(nx < 0 || ny < 0 || nx >= M || ny >= N) continue;
        if(areaVisit[nx][ny] == 0 && area[nx][ny] == 0){
          que.push({nx, ny});
          areaVisit[nx][ny] = 1;
        }
      }
      que.pop();
    }
  }
  ans.push_back(cnt);
}

int main(int argc, char const *argv[]) {
  cin >> M >> N >> K;

  // 1번
  for (int i = 0; i < K; i++) {
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    int dx1 = (M-1)-y1, dx2 = (M-1)-(y2-1);
    int dy1 = x1, dy2 = x2-1;
    for (int r = dx2; r <= dx1; r++) {
      for (int c = dy1; c <= dy2; c++) {
        area[r][c] = 1;
      }
    }
  }

  // 2번
  for (int i = 0; i < M; i++) {
    for (size_t j = 0; j < N; j++) {
      if(area[i][j] == 0 && areaVisit[i][j] == 0){
        bfs(i, j);
      }
    }
  }

  // 3번
  sort(ans.begin(), ans.end());
  cout << ans.size() << "\n";
  for (size_t i = 0; i < ans.size(); i++) {
    cout << ans[i] << " ";
  }

  return 0;
}
