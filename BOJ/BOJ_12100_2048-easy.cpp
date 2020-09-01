#include <bits/stdc++.h>
using namespace std;
// https://www.acmicpc.net/problem/12100

/*
<2048 (easy)>
주요: BFS, 구현
1. 상하좌우 이동 하는 경우를 모두 세본다.
  => 계산하는 경우의 수는 5^4 + 1 이므로 시간초과에 걸리지 않는다.
2. 한 단계씩 이동 할때 생기는 보드판의 모양을 큐에 넣어 단계별로 BFS 탐색을 한다.
  2-1. 이동 할 때 기록 될 숫자들을 각 방향에 맞게 큐에 넣는다. (line 큐 배열)
  2-2. 각 큐에서 값을 꺼내고, 꺼냈을 때 큐의 front 값과 같다면 한번 더 pop을하고 2배한 값을 new_board에 차례대로 입력한다.
  2-3. 이 외의 경우는 그냥 new_board에 입력한다.
  * 단 new_board idx를 각각 조건에 맞게 증가시키거나 감소시킨다.
3. 큐에서 pop할때마다 전체 보드에서의 최대값을 갱신한다.
4. 최종 최댓값을 출력한다.
==========
* 5^4 + 1 밖에 안되기 때문에 다 찾아보는게 가능했다.
* 경우의 수가 5^4 + 1 인 이유는 맨 처음 입력받은 base_board도 계산해서 이다. (for문 idx 주의)

*/

vector<vector<int> > base_board(25, vector<int>(25, 0));
queue<vector<vector<int> > > que;
int N, ans;

// 3번, board에서 제일 큰 값을 갱신
void checkMax(vector<vector<int> > cur){
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      ans = max(ans, cur[i][j]);
    }
  }
}

// 왼쪽 이동
void moveLeft(vector<vector<int> > cur){
  queue<int> line[N];

  // 전체 큐에 push 될 새로운 보드 판
  vector<vector<int> > newBoard(25, vector<int>(25,0));

  // 각 방향 줄에 있는 값들을 차례대로 큐에 넣는다.
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if(cur[i][j] != 0) line[i].push(cur[i][j]);
    }
  }

  // 큐를 하나씩 꺼내고 값을 처리한다.
  for (int i = 0; i < N; i++) {
    int idx = 0;
    while(!line[i].empty()){
      int now = line[i].front();
      line[i].pop();

      if(!line[i].empty() && line[i].front() == now){
        newBoard[i][idx++] = now*2;
        line[i].pop();
      }
      else{
        newBoard[i][idx++] = now;
      }
    }
  }

  // 새로 만들어진 보드를 전체 큐에 넣는다.
  que.push(newBoard);
}

// 오른쪽 이동
void moveRight(vector<vector<int> > cur){
  queue<int> line[N];
  vector<vector<int> > newBoard(25, vector<int>(25,0));
  for (int i = 0; i < N; i++) {
    for (int j = N-1; j >= 0; j--) {
      if(cur[i][j] != 0) line[i].push(cur[i][j]);
    }
  }

  for (int i = 0; i < N; i++) {
    int idx = N-1;
    while(!line[i].empty()){
      int now = line[i].front();
      line[i].pop();

      if(!line[i].empty() && line[i].front() == now){
        newBoard[i][idx--] = now*2;
        line[i].pop();
      }
      else{
        newBoard[i][idx--] = now;
      }
    }
  }
  que.push(newBoard);
}

// 위쪽 이동
void moveUp(vector<vector<int> > cur){
  queue<int> line[N];
  vector<vector<int> > newBoard(25, vector<int>(25,0));
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if(cur[j][i] != 0) line[i].push(cur[j][i]);
    }
  }

  for (int i = 0; i < N; i++) {
    int idx = 0;
    while(!line[i].empty()){
      int now = line[i].front();
      line[i].pop();

      if(!line[i].empty() && line[i].front() == now){
        newBoard[idx++][i] = now*2;
        line[i].pop();
      }
      else{
        newBoard[idx++][i] = now;
      }
    }
  }
  que.push(newBoard);
}

// 아래쪽 이동
void moveDown(vector<vector<int> > cur){
  queue<int> line[N];
  vector<vector<int> > newBoard(25, vector<int>(25,0));
  for (int i = N-1; i >= 0; i--) {
    for (int j = N-1; j >= 0; j--) {
      if(cur[j][i] != 0) line[i].push(cur[j][i]);
    }
  }

  for (int i = 0; i < N; i++) {
    int idx = N-1;
    while(!line[i].empty()){
      int now = line[i].front();
      line[i].pop();

      if(!line[i].empty() && line[i].front() == now){
        newBoard[idx--][i] = now*2;
        line[i].pop();
      }
      else{
        newBoard[idx--][i] = now;
      }
    }
  }
  que.push(newBoard);
}

// moveManager
void move(vector<vector<int> > cur){
  moveLeft(cur);
  moveRight(cur);
  moveUp(cur);
  moveDown(cur);
}

int main(){
  cin >> N;
  for (int i = 0; i < N; i++) {
    for (size_t j = 0; j < N; j++) {
      cin >> base_board[i][j];
    }
  }
  que.push(base_board); // 초기 board push

  // 총 5번 이동시켜본다 (idx 0 : 초기 상태) - BFS
  for (size_t dir = 0; dir <= 5; dir++) {
    int temp_size = que.size();
    while (temp_size--) {
      vector<vector<int> > cur = que.front();
      checkMax(cur);  // pop 할때 마다 최대값 갱신
      move(cur);
      que.pop();
    }
  }

  cout << ans;
}
