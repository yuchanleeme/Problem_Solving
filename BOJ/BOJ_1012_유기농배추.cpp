#include <iostream>
#include <vector>
#include <queue>
using namespace std;
//https://www.acmicpc.net/problem/1012

/*
<유기농 배추>
주요: DFS
1. DFS로 탐색하며 뭉텅이들을 찾는다.
2. 찾을 때마다 ans 값을 올려준다.
3. 모두 찾으면 ans값을 출력해 필요한 배추흰지렁이의 수를 출력한다.

*/

typedef struct loc{
  int x;
  int y;
}Loc;

int M, N, K;
int t_x[4] = {-1, 0, 1, 0}, t_y[4] = {0, -1, 0, 1};
vector<vector<int> > field;
queue<Loc> que;

void dfs(){
  while(!que.empty()){
    for (int i = 0; i < 4; i++) {
      int _x = que.front().x + t_x[i];
      int _y = que.front().y + t_y[i];

      if(_x >= 0 && _x < M && _y >= 0 && _y < N){
        if(field[_x][_y] == 1){
          Loc loc_t = {_x, _y};
          que.push(loc_t);
          field[_x][_y] = 0;
        }
      }
    }
    que.pop();
  }
}

int main() {

  int T;

  cin >> T;

  for (int testcase = 0; testcase < T; testcase++) {
    int x, y, ans = 0;
    cin >> M >> N >> K;

    field = vector<vector<int> >(M, vector<int>(N,0));

    for (int loc = 0; loc < K; loc++) {
      cin >> x >> y;
      field[x][y] = 1;
    }

    for (int i = 0; i < M; i++) {
      for (int j = 0; j < N; j++) {
        if(field[i][j] == 1){
          field[i][j] = 0;
          Loc loc_t = {i, j};
          que.push(loc_t);
          dfs();
          ans++;
        }
      }
    }
    cout << ans << endl;
  }

  return 0;
}
