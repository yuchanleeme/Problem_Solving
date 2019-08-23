#include <iostream>
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

  for (int i = 0; i < E; i++) {
    cin >> x >> y >> z;
    if(graph[x][y] == 0 || graph[x][y] > z){
      graph[x][y] = z;
    }
  }

  for (int p = 0; p < V+1; p++) {
    for (int k = 0; k < V+1; k++) {
      printf("%d ", graph[p][k]);
    }
    printf("\n");
  }

  return 0;
}
