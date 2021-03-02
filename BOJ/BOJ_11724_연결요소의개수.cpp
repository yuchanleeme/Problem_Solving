#include <bits/stdc++.h>
using namespace std;
//https://www.acmicpc.net/problem/11724

/*
<연결 요소의 개수>
주요: DFS
1. 간선 정보를 통해 양방향 그래프(인접 리스트)를 만든다.
2. isChecked배열을 통해 연결 요소를 센다.
3. 최종 연결 요소의 개수를 출력한다.
==========
* 방향이 없는 그래프는 양방향 그래프

*/

int N, M;
vector<int> graph[1010];
bool isChecked[1010];

void dfs(int prev){
  for (int i = 0; i < graph[prev].size(); i++) {
    int next = graph[prev][i];
    if(isChecked[next] == true) continue;
    else{
      isChecked[next] = true;
      dfs(next);
    }
  }
}

int main(int argc, char const *argv[]) {
  cin >> N >> M;
  for (int i = 0; i < M; i++) {
    int x, y; cin >> x >> y;
    graph[x].push_back(y);
    graph[y].push_back(x);
  }

  int ans = 0;
  for (int i = 1; i <= N; i++) {
    if(isChecked[i] == false){
      ans++;
      isChecked[i] = true;
      dfs(i);
    }
  }

  cout << ans;
  return 0;
}
