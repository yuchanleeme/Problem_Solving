#include <iostream>
using namespace std;
//https://www.acmicpc.net/problem/1743

/*
<음식물 피하기>
주요: DFS
1. DFS를 이용해 쓰레기의 위치를 탐색한다.
2. 쓰레기를 찾으면 값을 0으로 초기화 시키고 인접한 쓰레기를 찾는다.
3. dfs 함수를 호출 할때마다 카운트 되게 하고 최댓값을 구한다.

*/

int N, M, K, cnt;
int cal_x[4] = {-1, 0, 0 , 1}, cal_y[4] = {0, -1, 1, 0};
int trash[101][101];

void dfs(int x, int y){

  int temp_x, temp_y;
  trash[x][y] = 0;
  cnt++;

  for (int i = 0; i < 4; i++) {
    temp_x = cal_x[i] + x;
    temp_y = cal_y[i] + y;

    if(temp_x >= 0 && temp_y >= 0){
      if(trash[temp_x][temp_y] == 1){
        dfs(temp_x, temp_y);
      }
    }
  }
}

int main() {

  int a, b, ans = 0;
  cin >> N >> M >> K;

  for (int i = 0; i < K; i++) {
    cin >> a >> b;
    trash[a][b] = 1;
  }

  for (int i = 0; i <= N; i++) {
    for (int j = 0; j <= M; j++) {
      if(trash[i][j] == 1){
        cnt = 0;
        dfs(i, j);
        ans = max(ans, cnt);
      }
    }
  }

  cout << ans;

  return 0;
}
