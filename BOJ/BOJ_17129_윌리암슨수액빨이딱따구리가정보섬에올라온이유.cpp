#include <iostream>
#include <queue>
#include <vector>
using namespace std;
//https://www.acmicpc.net/problem/17129

/*
<윌리암슨수액빨이딱따구리가 정보섬에 올라온 이유>
주요: BFS
1. BFS 탐색으로 구현하면 되는 문제다.
2. 입력 속도가 문제가 있었다.
  => scanf도 느리게 처리했다.
  => 문자열로 처리해서 받았더니 AC
==========
*scnaf도 느릴때가 있다는걸 유의

*/

queue<pair<int,int> > que;
int N, M;
int map[3030][3030];
int visit[3030][3030];
int dx[4] = {-1,0,1,0}, dy[4] = {0,1,0,-1};

int main(int argc, char const *argv[]) {
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  cin >> N >> M;
  for (int i = 0; i < N; i++) {
    string temp;
    cin >> temp;
    for (int j = 0; j < temp.size(); j++) {
      if(temp[j] == '2'){
        que.push({i,j});
        visit[i][j] = 1;
      }
      else if(temp[j] == '1'){
        visit[i][j] = 1;
      }
      else if(temp[j] == '3' || temp[j] == '4' || temp[j] == '5'){
        map[i][j] = 3;
      }
    }
  }

  int ans = 0;
  while(!que.empty()){
    int temp_size = que.size();
    ans++;
    for (int i = 0; i < temp_size; i++) {
      for (int j = 0; j < 4; j++) {
        int nx = que.front().first + dx[j];
        int ny = que.front().second + dy[j];

        if(nx < 0 || nx > N || ny < 0 || ny > M || visit[nx][ny] == 1)
         continue;
        if(map[nx][ny] > 1){
          cout << "TAK\n" << ans;
          return 0;
        }
        visit[nx][ny] = 1;
        que.push({nx, ny});
      }
      que.pop();
    }
  }
  cout << "NIE";

  return 0;
}
