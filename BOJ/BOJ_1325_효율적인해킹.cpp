#include <iostream>
#include <vector>
using namespace std;
// https://www.acmicpc.net/problem/1325

/*
<효율적인 해킹>
주요: DFS, BFS , DP
1.

*/
void dfs(int num){

  visit[num] = 1;

  for (int i = 1; i < count; i++) {
    /* code */
  }

}



int main() {

  int N, M, A, B, computer;

  cin >> N >> M;
  vector<vector<int> > credit(N+1, vector<int>(N+1, 0));
  vector<int> visit(N+1, 0);

  for (int i = 0; i < M; i++) {
    cin >> A >> B;
    credit[B][A] = 1;
  }

  for (int i = 1; i <= N; i++) {
    visit.assign(N+1, 0); // 방문초기화
    computer = 0;
    dfs(i);
  }
  return 0;
}
