#include <iostream>
#include <vector>
#include <stack>
using namespace std;
//https://www.acmicpc.net/problem/9663

/*
<N-Queen>
주요: DFS, 백트래킹
1. 제일 중요한 사실은 각 행에 1개씩만 퀸이 배치가 가능하다는 것이다.
  => 따라서 조사할때마다 모든 N*N 벡터를 조사하는게 아니라 첫번째줄, 두번째줄 이런식으로 한다.
2. 백트래킹하여 조사한다.
  => 첫번째 행의 열에 1개씩 넣는것을 기준으로 시작한다.
  => DFS를 호출할때마다 퀸이 지나가는 경로를 방문처리하고 그 위치를 스택에 넣어준다.
  => 만약에 퀸이 다 배치가 되었다면(level == N-1) count해주고 함수 호출을 끝낸다.
  => DFS호출이 끝나면 스택을 pop 하면서 방문처리 한것을 풀어준다.
3. 계산된 count값을 출력한다.

==========
* check_visit에서 가로, 좌상대각선, 우상대각선까지 다 조사하면 시간초과가 뜬다.(불필요하므로 빼준다.)
  => 어차피 0행부터 N-1행까지 조사할것이므로 세로, 좌하대각선, 우하대각선만 check_visit해준다.

*/

int N, count = 0;
vector<vector<int> > visit;
stack<pair<int, int> > stk;

int check_visit(int x, int y){

  int num = 0;
  // 세로
  for (int i = x; i < N; i++) {
    if(visit[i][y] == 0){
      visit[i][y] = 1;
      stk.push(make_pair(i, y));
      num++;
    }
  }

  // 좌하 대각선
  for (int i = 1; ; i++) {
    if(x+i == N || y-i < 0){
      break;
    }
    else{
      if(visit[x+i][y-i] == 0){
        visit[x+i][y-i] = 1;
        stk.push(make_pair(x+i, y-i));
        num++;
      }
    }
  }

  // 우하 대각선
  for (int i = 1; ; i++) {
    if(x+i == N || y+i == N){
      break;
    }
    else{
      if(visit[x+i][y+i] == 0){
        visit[x+i][y+i] = 1;
        stk.push(make_pair(x+i, y+i));
        num++;
      }
    }
  }
  return num;
}

// 2번
void dfs(int level){
  if(level == N-1){
    count++;
    return;
  }
  else{
    for (int col = 0; col < N; col++) {
      if(visit[level+1][col] == 0){
        int temp_size = check_visit(level+1, col);
        dfs(level + 1);
        for (int j = 0; j < temp_size; j++) {
          visit[stk.top().first][stk.top().second] = 0;
          stk.pop();
        }
      }
    }
  }
}

int main() {

  cin >> N;
  for (int i = 0; i < N; i++) {
    visit = vector<vector<int> >(N, vector<int>(N, 0)); // 방문 벡터 초기화
    int first_size = check_visit(0, i); // 초기값 설정(0번째 행의 퀸)

    dfs(0);
    while(!stk.empty()){ stk.pop();} // 스택 초기화
  }

  // 3번
  cout << count;

  return 0;
}
