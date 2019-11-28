#include <iostream>
#include <vector>
#include <queue>
using namespace std;
//https://www.acmicpc.net/problem/2146

/*
<다리 만들기>
주요: DFS, BFS
1. 섬의 고유번호를 지정해 새로운 맵을 만든다. (DFS)
  1.1) 각 섬마다 고유 큐를 만들어(ex que[3], que[4]..) 그 섬의 위치 정보를 각 큐에 다 넣는다.
  1.2) 새로운 맵을 만들 때 각 섬의 번호를 매겨서 맵을 만든다.
2. 각 섬마다 최단거리를 구해서 갱신한다. (BFS)
  => 1번에서 만든 새로운 맵을 그대로 계속 이용한다.
  2.0) 섬을 확장하는 개념으로 접근한다. 각 테두리에서 한칸씩 BFS 방식으로 확장한다고 생각한다.
  2.1) 역행으로 확장을 막기 위해 같은 섬번호이면 continue한다.
  2.2) 확장을 한다면 큐에 확장된 위치의 번호를 큐에 넣고 그 위치를 섬번호로 바꾼다
  2.3) 만약 다른 팀번호를 만난다면 return 해서 그때까지 지어진 다리의 번호(round)를 리턴한다.
3. 모든 섬을 탐색하며 최단 다리를 찾는다.

*/

int N;
vector<vector<int> > map;
vector<vector<int> > visit;
vector<vector<int> > game_map;
queue<pair<int, int> > que[100000];

int t_x[] = {1, -1, 0, 0}, t_y[] = {0, 0, 1, -1};

// 1번
void make_map(int x, int y, int team_num) {

  for (int i = 0; i < 4; i++) {
    int p_x = x + t_x[i];
    int p_y = y + t_y[i];

    if(p_x < 0 || p_y < 0 || p_x >= N || p_y >= N){
      continue;
    }
    else{
      if(map[p_x][p_y] == 1 && visit[p_x][p_y] == 0){
        visit[p_x][p_y] = 1;
        game_map[p_x][p_y] = team_num;
        que[team_num].push({p_x,p_y});
        make_map(p_x, p_y, team_num);
      }
    }
  }
}

// 2번
int bfs(int x, int y, int team, vector<vector<int> > temp_game){

  int round = 0;
  while (!que[team].empty()) {

    int temp_size = que[team].size();

    for (int a = 0; a < temp_size; a++) {
      for (int i = 0; i < 4; i++) {
        int p_x = que[team].front().first + t_x[i];
        int p_y = que[team].front().second + t_y[i];

        if(p_x < 0 || p_y < 0 || p_x >= N || p_y >= N){
          continue;
        }
        else if(temp_game[p_x][p_y] == team){
          continue;
        }
        else if(temp_game[p_x][p_y] == 0){
          temp_game[p_x][p_y] = team;
          que[team].push({p_x,p_y});
        }
        else{
          return round;
        }
      }
      que[team].pop();
    }
    round++;
  }
  return 0;
}

int main() {

  cin >> N;

  map = vector<vector<int> >(N, vector<int>(N,0));
  visit = vector<vector<int> >(N, vector<int>(N,0));
  game_map = vector<vector<int> >(N, vector<int>(N,0));

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cin >> map[i][j];
    }
  }

  int team = 0;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if(map[i][j] == 1 && visit[i][j] == 0){
        visit[i][j] = 1;
        game_map[i][j] = team+1;
        make_map(i, j, team+1);
        team += 1;
      }
    }
  }

  int ans = 100000;
  team = 1;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if(game_map[i][j] == team){
        que[team].push({i,j});
        int res = bfs(i, j, team, game_map);
        ans = min(ans, res);
        team += 1;
      }
    }
  }

  cout << ans;

  return 0;
}
