#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
// https://www.acmicpc.net/problem/1516

/*
<게임 개발>
주요: DFS, 위상정렬
1. dfs 종료 역순은 위상정렬이다.
  => 따라서 DFS로 돈 정점을 stk에 넣고 그 역순을 이용한다.
2. 여러개의 그래프가 존재 할 수 있음을 인지한다.
3. 역순이된 stk의 값들을 하나씩 빼낸다.
  3-1) 빼내는 순간에 건물을 짓는다 생각하고 건물 짓는 시간을 fin[]에더해준다.
  3-2) 꺼낸 건물번호와 그 다음으로 지어질 건물들의 fin값을 비교해서 그 다음으로 지어질 건물의 fin값을 max값으로 갱신해준다.
  => 최종 갱신값은 그 건물을 짓기 직전까지 필요한 시간.
4. 위 3번을 반복한다음 fin을 출력하면 된다.
==========
* stk을 쓰면 좋지만 그냥 편의상 vector를 썼다.

*/

int N;
vector<int> g[505];
vector<int> st;
int t[505], fin[505];
bool visit[505];

void dfs(int n){

  visit[n] = true;
  for (int i = 0; i < g[n].size(); i++) {
    int next = g[n][i];
    if(visit[next] == false){
      dfs(next);
    }
  }
  st.push_back(n);
}

int main() {

  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> N;
  for (int i = 1; i <= N; i++) {
    cin >> t[i];
    int prev;
    while(true){
      cin >> prev;
      if(prev == -1) break;
      g[prev].push_back(i);
    }
  }

  // 2번
  for (int i = 1; i <= N; i++) {
    if(visit[i] == false)
      dfs(i);
  }

  reverse(st.begin(), st.end()); // dfs 종료 역순은 위상정렬 순이다.

  // 3번
  for(auto n : st){
    fin[n] += t[n];
    for(auto next : g[n]){
      fin[next] = max(fin[next], fin[n]);
    }
  }

  // 4번
  for (int i = 1; i <= N; i++) {
    cout << fin[i] << '\n';
  }

  return 0;
}
