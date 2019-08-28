#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>
using namespace std;
//https://www.acmicpc.net/problem/1753

/*
<최단 경로>
주요: 다익스트라 알고리즘
1.

*/

int main() {
  int V, E, K, x, y, z;

  cin >> V >> E >> K;

  vector<vector<int> > graph(V+1, vector<int>(V+1, 0));
  vector<int> w(V+1, 11); // 가중치
  vector<int> visit(V+1, 0);
  w[K] = 0;

  for (int i = 0; i < E; i++) {
    cin >> x >> y >> z;
    if(graph[x][y] == 0 || graph[x][y] > z){
      graph[x][y] = z;
    }
  }
  stack<int> stk;
  stk.push(K);
  visit[K] = 1;

  while(stk.size() != V){

    for (int i = 1; i <= V; i++) {
      if(graph[stk.top()][i] != 0){
        w[i] = min(w[i], w[stk.top()] + graph[stk.top()][i]);
      }
    }
    int temp_value = 11, idx;
    for (int i = 1; i <= V; i++) {
      if(visit[i] == 0){
        if(temp_value > w[i]){
          temp_value = w[i];
          idx = i;
        }
      }
    }
    stk.push(idx);
    visit[idx] = 1;
  }
  for (int i = 1; i <= V; i++) {
    if(w[i] == 11){
      printf("INF\n");
    }
    else{
      printf("%d\n", w[i]);
    }
  }

  return 0;
}
