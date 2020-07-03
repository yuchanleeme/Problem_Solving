#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
//https://www.acmicpc.net/problem/13023

/*
<ABCDE>
주요: DFS
1. DFS 깊이가 5이상인게 존재하면 true이다.
2. DFS 탐색을 하여 깊이 5이면 1을 출력하면 된다.
==========
* 모든 그래프를 탐색 할 것 이므로 방문 처리를 풀어주는 코드도 넣어줘야 한다.

*/
int N, M;
bool gameOver = false;
vector<int> graph[2020];
vector<int> visit;

void dfs(int num, int level){
  visit[num] = 1;
  if(gameOver == true) return;
  if(level == 5){
    gameOver = true;
    return;
  }
  for (int i = 0; i < graph[num].size(); i++) {
    int next = graph[num][i];
    if(visit[next] == 0){
      dfs(next, level+1);
    }
  }
  visit[num] = 0;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> N >> M;
  visit = vector<int>(N+1, 0); // visit 벡터
  for (int i = 0; i < M; i++) {
    int x, y;
    cin >> x >> y;
    graph[x].push_back(y);
    graph[y].push_back(x);
  }

  for (int i = 0; i < N; i++) {
    dfs(i, 1);
    if(gameOver) break;
  }

  if(gameOver) cout << "1" << "\n";
  else cout << "0" << "\n";

  return 0;
}
