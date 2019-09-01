#include <iostream>
#include <queue>
#include <vector>
using namespace std;
//https://www.acmicpc.net/problem/10026

/*
<적록색약>
주요: BFS, DFS
1. 정상인이 보이는 그림과 적록색약인 사람이 보이는 그림을 구분해서 만든다.
2. 각각의 판에 대해서 BFS, DFS로 탐색한다.
3. 분리된 구역의 개수를 차례대로 출력한다.

*/

// 그림의 좌표및 색깔
typedef struct info{

  int x;
  int y;
  char color;

}Info;

int N, ans_A, ans_B;
int t_x[4] = {-1, 0, 1, 0}, t_y[4] = {0, -1, 0, 1};
vector<vector<char> > picture_a; // 정상인 그림
vector<vector<char> > picture_b; // 적록색약 그림
vector<vector<int> > visit; // 방문
queue<Info> que;

// 2번
void cal(vector<vector<char> > &picture){

  while(!que.empty()){
    for (int i = 0; i < 4; i++) {
      int _x = que.front().x + t_x[i];
      int _y = que.front().y + t_y[i];

      if(_x >= 0 && _x < N && _y >= 0 && _y < N){
        if(visit[_x][_y] == 0){
          if(que.front().color == picture[_x][_y]){
            visit[_x][_y] = 1;
            Info info_t = {_x, _y, picture[_x][_y]};
            que.push(info_t);
          }
        }
      }
    }
    que.pop();
  }
}

int main() {

  cin >> N;

  picture_a = vector<vector<char> >(N, vector<char>(N,0));
  picture_b = vector<vector<char> >(N, vector<char>(N,0));
  visit = vector<vector<int> >(N, vector<int>(N,0));

  // 1번
  char temp_color;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cin >> temp_color;
      if(temp_color == 'G'){
        picture_b[i][j] = 'R';
      }
      else{
        picture_b[i][j] = temp_color;
      }
      picture_a[i][j] = temp_color;
    }
  }

  // 정상인 그림
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if(visit[i][j] == 0){
        Info info_t = {i,j,picture_a[i][j]};
        que.push(info_t);
        visit[i][j] = 1;
        cal(picture_a);
        ans_A++;
      }
    }
  }

  // 적록색약 그림
  visit = vector<vector<int> >(N, vector<int>(N,0)); // 방문벡터 초기화
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if(visit[i][j] == 0){
        Info info_t = {i,j,picture_b[i][j]};
        que.push(info_t);
        visit[i][j] = 1;
        cal(picture_b);
        ans_B++;
      }
    }
  }

  // 3번
  cout << ans_A << " " << ans_B;

  return 0;
}
