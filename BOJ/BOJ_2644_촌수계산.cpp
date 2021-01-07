#include <bits/stdc++.h>
using namespace std;
//https://www.acmicpc.net/problem/2644

/*
<촌수계산>
주요: DFS
1. DFS 탐색을 통해 얼마나 깊이 이어져 있는지 찾는다.
2. 깊이를 찾을 수 없다면 -1을 출력한다.

*/

int N, a, b, m, ans;
vector<int> family[110];
int gameVisit[110];
void dfs(int num, int level){
  if(num == b){
    ans = level;
    return;
  }

  for (int i = 0; i < family[num].size(); i++) {
    int nx = family[num][i];
    if(gameVisit[nx] == 1) continue;
    gameVisit[nx] = 1;
    dfs(nx, level+1);
    gameVisit[nx] = 0;
  }

}

int main(int argc, char const *argv[]) {
  cin >> N >> a >> b >> m;
  for (size_t i = 0; i < m; i++) {
    int x, y;
    cin >> x >> y;
    family[x].push_back(y);
    family[y].push_back(x);
  }
  gameVisit[a] = 1;
  dfs(a, 0);
  if(ans == 0) cout << -1;
  else cout << ans;
  return 0;
}
