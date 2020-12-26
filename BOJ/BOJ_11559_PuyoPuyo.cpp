#include <bits/stdc++.h>
using namespace std;
// https://www.acmicpc.net/problem/11559

/*
<Puyo Puyo>
주요: BFS
1. BFS를 통해 연결 되어 있는 뿌요의 개수와 그 위치를 구한다.
  => 큐 사이즈를 통해 개수를 구한다.
2. 위치 벡터를 통해 연결된 뿌요들을 다 터뜨린다.
3. 다 터지면 중력을 작용해 모든 뿌요들을 아래로 끌어당긴다.
4. 1~3 과정이 멈출때까지 하고 그 수를 출력한다.

*/

vector<string> gameBoard; // 게임판
int gameCheck, gameErase, ans;
int tx[4] = {-1, 0, 1, 0}, ty[4] = {0, 1, 0, -1};

void bfs(int x, int y, char color){

  int gameVisit[12][6] = {0, };
  gameVisit[x][y] = 1;

  queue<pair<int, int> > que;
  vector<pair<int, int> > seq;
  que.push({x, y});
  seq.push_back({x, y});

  while(!que.empty()){
    int temp_size = que.size();
    gameCheck += temp_size; // 연결된 애들 개수 세기
    for (int qs = 0; qs < temp_size; qs++) {
      for (size_t i = 0; i < 4; i++) {
        int nx = que.front().first + tx[i];
        int ny = que.front().second + ty[i];

        if(nx < 0 || ny < 0 || nx >= 12 || ny >= 6) continue;
        if(gameVisit[nx][ny] == 1) continue;
        if(gameBoard[nx][ny] != color) continue;
        gameVisit[nx][ny] = 1;
        que.push({nx, ny});
        seq.push_back({nx, ny});
      }
      que.pop();
    }
  }

  // 4개 이상이면
  if(gameCheck >= 4){
    gameErase++; // 지울 때마다 1 더하기
    for (int i = 0; i < seq.size(); i++) {
      gameBoard[seq[i].first][seq[i].second] = '.';
    }
  }
}

// 중력 작용
void down(){
  for (int i = 0; i < 6; i++) {
    string temp = "";
    for (int j = 11; j >= 0; j--) {
      if(gameBoard[j][i] != '.'){
        temp += gameBoard[j][i];
        gameBoard[j][i] = '.';
      }
    }
    for (int j = 0; j < temp.length(); j++) {
      gameBoard[11-j][i] = temp[j];
    }
  }
}

int main(){

  for (int i = 0; i < 12; i++) {
    string temp;
    cin >> temp;
    gameBoard.push_back(temp);
  }

  while(true){
    gameErase = 0;
    for (int i = 0; i < 12; i++) {
      for (int j = 0; j < 6; j++) {
        if(gameBoard[i][j] == '.') continue;
        gameCheck = 0;
        bfs(i, j, gameBoard[i][j]);
      }
    }

    down();

    // 0이라는 것은 지울게 없다는거
    if(gameErase == 0){
      cout << ans;
      break;
    }
    ans++;
  }
  return 0;
}
