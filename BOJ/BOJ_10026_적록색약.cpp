#include <iostream>
#include <queue>
#include <vector>
using namespace std;
//https://www.acmicpc.net/problem/10026

/*
<적록색약>
주요: BFS, DFS

*/
typedef struct info{

  int x;
  int y;
  char color;
}Info;

int N, ans_A, ans_B;
int t_x[4] = {-1, 0, 1, 0}, t_y[4] = {0, -1, 0, 1};
vector<vector<char> > picture;
vector<vector<int> > visit_a; // 정상인
queue<Info> que_a;
vector<vector<int> > visit_b; // 적록색약
queue<Info> que_b;

void bfs(){

  while(!que_a.empty() && !que_b.empty()){

    for (int i = 0; i < 4; i++) {
      int a_x = que_a.front().x + t_x[i];
      int a_y = que_a.front().y + t_y[i];

      if(a_x >= 0 && a_x < N && a_y >= 0 && a_y < N){
        if(visit_a[a_x][a_y] == 0){
          if(que_a.front().color == picture[a_x][a_y]){
            visit_a[a_x][a_y] = 0;
            Info info_t = {a_x, a_y, picture[a_x][a_y]};
            que_a.push(info_t);
          }
        }
      }
    }
    printf("que.front() %d %d %c\n",que_a.front().x,que_a.front().y,que_a.front().color );
    que_a.pop();
  }


}

int main() {
  freopen("1aa.txt", "r", stdin);
  cin >> N;

  picture = vector<vector<char> >(N, vector<char>(N,0));
  visit_a = vector<vector<int> >(N, vector<int>(N,0));
  visit_b = vector<vector<int> >(N, vector<int>(N,0));

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cin >> picture[i][j];
    }
  }
  Info info_f = {0,0,picture[0][0]};
  que_a.push(info_f);
  visit_a[0][0] = 1;
  que_b.push(info_f);
  visit_b[0][0] = 1;
  bfs();

  return 0;
}
