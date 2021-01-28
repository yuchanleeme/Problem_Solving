#include <iostream>
#include <tuple>
#include <queue>
using namespace std;
//https://www.acmicpc.net/problem/13459

/*
<구슬 탈출>
주요: BFS
1. 큐에 3개의 값을 전달시켜준다. (이동이 끝난 R,B의 위치, 방향idx)
  => 각 위치에서 4방향의 값을 큐에 넣어주어 반복시킨다.
  => 이렇게 하면 모든 방향의 가능성을 판단 할 수 있다.
2. R이 먼저 이동하는지 B가 먼저 이동하는지 판단해야 한다.
  => 각 방향의 진행방향과 R,B의 위치를 기준으로 판단한다.
3. 각 조건에 맞게 move 하면서 goal판단을 한다.
  => 조건에 맞게 빨간 구슬만 goal했다면 그때의 단계를 ans에 값을 넣는다.
  => 11번 이상 이동하거나 조건에 맞지 않으면 -1을 ans에 넣는다.
4. 이렇게 최종계산된 ans에 따라 정답을 출력한다.

*/

typedef struct info{

  int x;
  int y;
  char color;

}Info;

int N,M;
int ans = 0, level = 1;
bool end_game = false;
int dx[4] = {1,-1,0,0}, dy[4] = {0,0,1,-1}; // 아래, 위, 오른쪽, 왼족
char board[11][11];
Info R_location, B_location, O_location; // 최초 R,B,O의 위치
queue<tuple<Info, Info, int> > que; // red blue info정보, 방향idx

// 골인했는지 확인
bool check_goal(int x, int y){
  if(O_location.x == x && O_location.y == y){
    return true;
  }
  else{
    return false;
  }
}

// 이동 하는 함수 (한칸씩 이동하며 비교)
void move(Info r, Info b, int idx, int order){

  bool r_goal = false, b_goal = false;

  if(order == 0){
    // R부터 이동, B 다음 이동
    while (board[r.x+dx[idx]][r.y+dy[idx]] != '#') {
      r.x += dx[idx];
      r.y += dy[idx];
      // 골인 했을 때
      r_goal = check_goal(r.x,r.y);
      if(r_goal){ break;}
    }

    while (board[b.x+dx[idx]][b.y+dy[idx]] != '#') {
      if(b.x+dx[idx] == r.x && b.y+dy[idx] == r.y){
        // 앞에 이동한 구슬과 같은 위치에 있을때
        if(!r_goal){ break;} // 만약에 골인한거였으면 그대로진행
      }
      b.x += dx[idx];
      b.y += dy[idx];
      b_goal = check_goal(b.x,b.y);
      if(b_goal){ break;}
    }
  }
  else{
    // B부터 이동, R 다음 이동
    while (board[b.x+dx[idx]][b.y+dy[idx]] != '#') {
      b.x += dx[idx];
      b.y += dy[idx];
      b_goal = check_goal(b.x,b.y);
      if(b_goal){ break;}
    }

    while (board[r.x+dx[idx]][r.y+dy[idx]] != '#') {
      // 앞에 이동한 구슬과 같은 위치에 있을때
      if(r.x+dx[idx] == b.x && r.y+dy[idx] == b.y){
        if(!b_goal){ break;} // 만약에 골인한거였으면 그대로진행
      }
      r.x += dx[idx];
      r.y += dy[idx];
      r_goal = check_goal(r.x,r.y);
      if(r_goal){ break;}
    }
  }

  // 골인 판정 및 게임 판정
  if(!r_goal && !b_goal){
    // 둘다 골인 못 했으면 계속 진행하기 위해 큐에 push
    for (int direction = 0; direction < 4; direction++) {
      que.push({r,b,direction});
    }
  }
  else if(r_goal && !b_goal){
    // 빨간 구슬이 들어갔다면 결과에 ans를 넣고 end_game 처리한다.
    ans = level;
    end_game = true;
  }
}

// bfs로 값 확인
void bfs() {

  int level_size = que.size();
  for (int p = 0; p < level_size; p++) {
    Info r_loc =  get<0>(que.front());
    Info b_loc =  get<1>(que.front());
    int move_idx = get<2>(que.front());

    int order = 0; // 0 이면 red 부터, 1이면 blue부터 이동
    if(move_idx == 0 && r_loc.x < b_loc.x){ order = 1;} // 아래
    else if(move_idx == 1 && r_loc.x > b_loc.x){ order = 1;} // 위
    else if(move_idx == 2 && r_loc.y < b_loc.y){ order = 1;} // 오른
    else if(move_idx == 3 && r_loc.y > b_loc.y){ order = 1;} // 왼
    move(r_loc,b_loc,move_idx,order);

    que.pop();
  }
  level++; // 트리의 밑의 단계로 이동

  if(level > 11){
    ans = -1;
    end_game = true;
  }

  if(!end_game){ bfs();}
  return;
}

int main() {

  scanf("%d %d", &N, &M);

  // 입력 , R,B를 .으로 바꿔주어 후에 move가 편하게 한다.
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      while (scanf("%1c", &board[i][j])) {
        if(board[i][j] == '\n'){ continue;}
        if(board[i][j] == 'R'){
          R_location = {i,j,'R'};
          board[i][j] = '.';
        }
        else if(board[i][j] == 'B'){
          B_location = {i,j,'B'};
          board[i][j] = '.';
        }
        else if(board[i][j] == 'O'){
          O_location = {i,j,'O'};
        }
        break;
      }
    }
  }

  // 최초 4방향 이동을 큐에 push
  for (int i = 0; i < 4; i++) {
    que.push({R_location, B_location, i});
  }

  bfs();

  if(ans == -1) printf("0");
  else printf("1");

  return 0;
}
