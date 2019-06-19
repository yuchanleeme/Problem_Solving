#include <iostream>
#include <queue>
using namespace std;
// https://www.acmicpc.net/problem/1260

/*
<분수찾기>
주요: DFS, BFS
1. DFS : 재귀를 활용하여 구현
2. BFS : 큐를 활용하여 구현

*/

int N, M, V, line[1010][1010]; // 간선의 관계를 표현한 배열
int check_node[1010]; // 방문했는지 확인하는 배열 (방문했으면 true, 아니면 false)

void dfs(int num){

  cout << num << " ";
  check_node[num] = true;

  for (int i = 1; i <= N; i++) {
    if(!check_node[i] && line[num][i] == 1){
      dfs(i); // 방문하지 않았거나 , 점 사이의 간선이 존재하면 재귀
    }
  }
}

void bfs(int num){

  queue<int> que;
  que.push(num);
  check_node[num] = true; // 초기 큐를 돌리기 위해 저장

  while(!que.empty()){
    for (int i = 1; i <= N; i++) {
      if(!check_node[i] && line[que.front()][i] == 1){
        que.push(i);
        check_node[i] = true; // 방문하지 않았거나, 점 사이의 간선이 존재하면 큐에 push
      }
    }
    cout << que.front() << " ";
    que.pop();
  }
}

int main() {

  int a, b;

  cin >> N >> M >> V;

  for (int i = 0; i < M; i++) {
    cin >> a >> b;
    line[a][b] = 1;
    line[b][a] = 1; // 양방향이므로 둘 다 저장
  }

  dfs(V);
  cout << endl;
  fill(check_node, check_node + 1001, false); // 노드방문체크 배열 초기화;
  bfs(V);

  return 0;
}
