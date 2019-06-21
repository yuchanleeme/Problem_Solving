#include <iostream>
#include <algorithm>
using namespace std;
//https://www.acmicpc.net/problem/2667

/*
<단지 번호 붙이기>
주요: DFS
1. 모든 배열울 탐색하면서 아직 방문하지 않았고 집이 있으면 탐색한다. (배열 값 1인 곳)
2. 해당 값에서 갈 수 있는 모든 방향을 탐색하고 조건에 해당하는 집이 있으면 complex 배열값을 올려 주고 그 집에대해 다시 탐색한다.(DFS-재귀)
3. 더이상 갈 수 있는 집이 없으면 단지의 idx값을 올리고 1번 과정으로 돌아간다.
4. 1~3번 과정을 반복하고 저장된 단지 배열(complex)을 오름차순 정렬하여 출력한다.

*/

int apartment[30][30], is_visited[30][30], complex[600] = {0, };
int N, idx = 0;
int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, -1, 1, 0};

// 2번
void dfs(int x, int y){

  int val_x, val_y;
  is_visited[x][y] = 1;
  complex[idx]++;

  for (int i = 0; i < 4; i++) {
    val_x = x + dx[i];
    val_y = y + dy[i];

    if((0 <= val_x && val_x <N) && (0 <= val_y && val_y <N)){
      if(!is_visited[val_x][val_y] && apartment[val_x][val_y] == 1){
        dfs(val_x, val_y);
      }
    }
  }
}

int main() {

  scanf("%d", &N);
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      scanf("%1d", &apartment[i][j]);
    }
  }

  // 1,3번
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if(!is_visited[i][j] && apartment[i][j] == 1){
        dfs(i,j);
        idx++;
      }
    }
  }

  // 4번
  sort(complex, complex + idx);
  printf("%d\n", idx);
  for (int i = 0; i < idx; i++) {
    printf("%d\n", complex[i]);
  }

  return 0;
}
