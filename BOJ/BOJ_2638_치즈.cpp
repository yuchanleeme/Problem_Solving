#include <bits/stdc++.h>
using namespace std;
//https://www.acmicpc.net/problem/2638

/*
<치즈>
주요: BFS
1. 외부공기를 기준으로 BFS 탐색을 한다고 생각한다.
2. 현재 남은 치즈의 수를 remain으로 설정해 이 개수를 통해 치즈가 다 녹았는지 판단한다.
3. 다음과 같이 BFS 탐색을 한다.
  3-1. 다음 탐색할 위치(nx,ny)가 치즈이면 해당 위치의 isMelt[nx][ny] 값을 +1 해준다.
  3-2. isMelt[nx][ny] 가 2가 되면 녹는 치즈이므로 해당 위치를 melt 벡터에 넣어준다.
  3-3. BFS 1싸이클이 끝나면 melt 벡터에 있는 원소들의 치즈들을 다 0으로 해준다.
  3-4. 남은 치즈의 수를 remain -= melt.size()를 통해 갱신해준다.
4. remain이 0이면 다 녹았으므로 그 때의 time(싸이클)을 출력한다.

*/

int N, M, remain;
int cheeze[110][110];
int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};

void bfs(){
  int cheezeVisit[110][110] = {0, };
  int isMelt[110][110] = {0, };
  queue<pair<int, int> > que;
  vector<pair<int, int> > melt;
  que.push({0, 0});
  cheezeVisit[0][0] = 1;

  while (!que.empty()) {
    int temp_size = que.size();
    for (size_t i = 0; i < temp_size; i++) {
      for (size_t j = 0; j < 4; j++) {
        int nx = que.front().first + dx[j];
        int ny = que.front().second + dy[j];

        if(nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
        if(cheezeVisit[nx][ny] == 1) continue;

        if(cheeze[nx][ny] == 1){
          isMelt[nx][ny]++; // 3-1번
          if(isMelt[nx][ny] == 2) melt.push_back({nx, ny}); // 3-2번
        }
        else{
          cheezeVisit[nx][ny] = 1;
          que.push({nx, ny});
        }
      }
      que.pop();
    }
  }

  // 3-3번
  for (int i = 0; i < melt.size(); i++) {
    cheeze[melt[i].first][melt[i].second] = 0;
  }
  remain -= melt.size(); // 3-4번
}

int main(int argc, char const *argv[]) {
  cin >> N >> M;

  for (size_t i = 0; i < N; i++) {
    for (size_t j = 0; j < M; j++) {
      cin >> cheeze[i][j];
      if(cheeze[i][j] == 1) remain++; // 2번
    }
  }

  if(remain == 0) return !printf("0"); // 처음부터 다 녹았을 때

  int time = 0;
  while (remain != 0) {
    time++; // 싸이클 증가
    bfs();
  }

  // 4번
  cout << time;

  return 0;
}
