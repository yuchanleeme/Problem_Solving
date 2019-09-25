#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef struct loc{

  char color;
  int x;
  int y;

}Loc;

int N, M, ans = 11, res = 0;
int dx[4] = {1, 0, 0 ,-1}, dy[4] = {0, 1, -1, 0};
vector<char> board[10];
vector<char> game[10];
Loc R_loc, B_loc, O_loc;
queue<pair<Loc, Loc> > que;

// 움직인다.
void move(vector<char> &game[], Loc &f, Loc &s, int idx){
  int tx_f = dx[idx] + f.x;
  int ty_f = dy[idx] + f.y;
  int tx_s = dx[idx] + s.x;
  int ty_s = dy[idx] + s.y;
  bool f_goal = false, s_goal = false;

  while(true){
    if(game[tx_f][ty_f] == '#' && game[tx_s][ty_s] == '#'){
      return;
    }
    // 먼저 출발
    while (game[tx_f][ty_f] != '#') {
      tx_f += dx[idx];
      ty_f += dy[idx];
      if(game[tx_f][ty_f] == 'O'){
        f_goal == true;
        break;
      }
    }
    // 후에 출발 => #이거나 앞에 출발한 공을 만나거나
    while (game[tx_s][ty_s] != '#' || game[tx_s][ty_s] != f.color) {
      tx_s += dx[idx];
      ty_s += dy[idx];
      if(game[tx_s][ty_s] == 'O'){
        s_goal == true;
        break;
      }
    }

    if(f_goal && s_goal){
      // 동시에 골인 -> 실패
    }
    else if(f_goal && !s_goal){
      if(f.color == 'R'){
        // RED 골인 성공
        ans = min(ans, res+1);
      }
      else{
        // Blue 골인 실패
      }
    }
    else if(!f_goal && s_goal){
      if(s.color == 'R'){
        // RED 골인 성공
        ans = min(ans, res+1);
      }
      else{
        // Blue 골인 실패
        // return;
      }
    }
    else{
      // 아무것도 아니면 이동
      game[f.x][f.y] = '.';
      game[s.x][s.y] = '.';
      f.x = tx_f + dx[idx];
      f.y = ty_f + dy[idx];
      s.x = tx_s + dx[idx];
      s.y = ty_s + dy[idx];
      game[f.x][f.y] = f.color;
      game[s.x][s.y] = s.color;
      res++;
    }
  }
}

void back_tracking(vector<char> game[], int level) {
  if(level > 10){
    return;
  }
  Loc r = que.front().first;
  Loc b = que.front().second;

  for (int i = 0; i < 4; i++) {


    if(i == 0){
      // down
      if(r.x > b.x){
        // R이 B보다 아래
        move(game,r,b,i);
      }
      else{
        // R이 B보다 위에
        move(game,b,r,i);
      }
    }
    else if(i == 1){
      // right
      if(r.y > b.y){
        // R이 B보다 오른쪽
        move(game,r,b,i);
      }
      else{
        // R이 B 왼쪽
        move(game,b,r,i);
      }
    }
    else if(i == 2){
      // left
      if(r.y < b.y){
        // R이 B보다 왼쪽
        move(game,r,b,i);
      }
      else{
        // R이 B보다 오른쪽
        move(game,b,r,i);
      }
    }
    else if(i == 3){
      // up
      if(r.x < b.x){
        // R이 B보다 위
        move(game,r,b,i);
      }
      else{
        // R이 B보다 아래
        move(game,b,r,i);
      }
    }
    que.push({r,b});
    back_tracking(game, level+1);
    res--;
    que.pop();
  }
}

int main() {

  scanf("%d %d", &N, &M);
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      char input;
      while (scanf("%1c", &input)) {
        if(input != '\n'){ break;}
        if(input == 'R'){
          R_loc = {'R',i,j};
        }
        else if(board[i][j] == 'B'){
          B_loc = {'B',i,j};
        }
        else if(board[i][j] == 'O'){
          O_loc = {'O',i,j};
        }
      }
    }
  }
  game = board;
  que.push({R_loc,B_loc});
  back_tracking(board, 0);


  return 0;
}
