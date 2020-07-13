#include <iostream>
#include <vector>
using namespace std;
//https://www.acmicpc.net/problem/14500

/*
<테트로미노>
주요: 백트래킹, 브루트포스
1. 4가지 연속된 칸의 모양이 테트로미노 라고 생각하면 된다.
  => 즉, 깊이 4인 dfs 탐색을 해서 최댓값을 찾는다.
  => 단, 'ㅗ', 'ㅜ', 'ㅓ', 'ㅏ' 모영은 따로 세준다.
2. 상단은 이미 조사했다는 전제하에 탐색을 진행할 때 그래프 위쪽은 탐색하지 않게 한다.
3. 깊이가 3일때 seq의 두번째 칸에서 하나를 추가하면 'ㅗ'모양 꼴이 되기 때문에 이를 이용한다.
  => 'ㅡ' 모양에서 'ㅗ' 모양이 된다는 뜻
4. 최종적으로 젤 큰값을 출력한다.
==========
* 상단은 이미 조사했다는 전제하에 point 배열을 만들다가 너무 idx가 커서 방법을 바꿨다.

*/

int N, M, ans;
int board[505][505];
int visit[505][505];
int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
vector<pair<int, int> > seq;

void backtracking(int level, int row, int col){

  // 4개 모양
  if(level == 4){
    int res = 0;
    for (int i = 0; i < seq.size(); i++) {
      res += board[seq[i].first][seq[i].second];
    }
    ans = max(ans, res);
    return;
  }

  // 'ㅗ' 'ㅜ' 'ㅓ' 'ㅏ' 모양
  if(level == 3){
    int res = 0;
    for (int i = 0; i < seq.size(); i++) {
      res += board[seq[i].first][seq[i].second];
    }
    for (int i = 0; i < 4; i++) {
      int mx = seq[1].first + dx[i];
      int my = seq[1].second + dy[i];
      if(visit[mx][my] != 1 && (mx>= 0 && mx <N && my >=0 && my < M)){
        ans = max(ans, res + board[mx][my]);
      }
    }
  }

  // 상단은 방문하지 않는다. (이미 조사했다고 생각)
  for (int i = 1; i < 4; i++) {
    int nx = row + dx[i];
    int ny = col + dy[i];

    if(visit[nx][ny] != 1 && (nx>= 0 && nx <N && ny >=0 && ny < M)){
      visit[nx][ny] = 1;
      seq.push_back({nx,ny});
      backtracking(level+1, nx, ny);
      seq.pop_back();
      visit[nx][ny] = 0;
    }
  }
}

int main() {

  cin >> N >> M;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      cin >> board[i][j];
    }
  }

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      backtracking(0, i, j);
    }
  }

  cout << ans << endl;

  return 0;
}
