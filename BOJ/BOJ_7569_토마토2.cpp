#include <iostream>
#include <queue>
using namespace std;
//https://www.acmicpc.net/problem/7569

/*
<토마토 2>
주요: BFS
1. 토마토 1과 같은 풀이지만 2차원에서 3차원으로 바뀌었다.
2. 구조체를 만들어 각 x,y,z 좌표를 큐에 집어 넣는다.
3. -1, 1 일때 count 해주고 탐색이 끝났을 때 그 값이 N*M*H가 아니면 다 익지 않고 끝난것이므로 -1을 출력한다.
4. 나머지 경우에는 count 값을 출력한다.
====================
* <7576_토마토>와 비슷하므로 참고

*/
typedef struct info{
  int x;
  int y;
  int z;
}Info;

int M, N, H, count_end = 0;
int tomato[102][102][102];
int t_x[6] = {0, -1, 1, 0, 0, 0}, t_y[6] = {-1, 0, 0, 1, 0, 0}, t_z[6] = {0, 0, 0, 0, 1, -1};
queue<Info> que;

void bfs(Info loc){

  int b_x , b_y, b_z;
  Info temp_info;
  for (int i = 0; i < 6; i++) {
    b_x = loc.x + t_x[i];
    b_y = loc.y + t_y[i];
    b_z = loc.z + t_z[i];

    if(0 <= b_x && b_x < N && 0 <= b_y && b_y < M && 0 <= b_z && b_z < H){
      if(tomato[b_x][b_y][b_z] == 0){
        tomato[b_x][b_y][b_z] = 1;
        temp_info = {b_x, b_y, b_z};
        que.push(temp_info);
        count_end++;
      }
    }
  }
  que.pop();
  
}

int main() {

  int temp_size, ans = 0;
  Info loc;
  cin >> M >> N >> H;

  for (int k = 0; k < H; k++) {
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < M; j++) {
        cin >> tomato[i][j][k];
        if(tomato[i][j][k] == 1){
          loc = {i ,j ,k};
          que.push(loc);
          count_end++;
        }
        else if(tomato[i][j][k] == -1){
          count_end++;
        }
      }
    }
  }

  while(!que.empty()){
    temp_size = que.size();
    ans++;
    for (int i = 0; i < temp_size; i++) {
      bfs(que.front());
    }
  }

  if(count_end == M*N*H){
    cout << ans - 1;
  }
  else{
    cout << "-1";
  }

  return 0;
}
