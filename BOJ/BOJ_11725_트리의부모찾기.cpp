#include <iostream>
#include <vector>
#include <stack>
using namespace std;
//https://www.acmicpc.net/problem/11725

/*
<트리의 부모 찾기>
주요: 트리, DFS
1. 1을 root로 설정하고 DFS 탐색을 한다.
  => 초기값 방문처리하고 1을 스택에 넣어준다.
2. 방문하지않은 노드를 방문하되 그 노드의 부모값(스택의 top값)을 ans에 저장한다.
  => 이 이후에 방문처리를 하고 스택에 넣어준다.
3. 모든 탐색이 끝났으면 ans 값들을 2부터 출력한다.

*/

vector<int> ans;
vector<int> visit;
vector<vector<int> > node;
stack<int> stk;

void dfs(){
  int p = stk.top();
  for (int i = 0; i < node[p].size(); i++) {
    int temp = node[p][i];
    if(visit[temp] == 0){
      ans[temp] = stk.top();
      stk.push(temp);
      visit[temp] = 1;
      dfs();
      stk.pop();
    }
  }
}

int main() {

  int N;
  scanf("%d", &N);

  int x, y;
  node = vector<vector<int> >(N+1);
  ans = vector<int>(N+1, 0);
  visit = vector<int>(N+1, 0);
  for (int i = 0; i < N-1; i++) {
    scanf("%d %d", &x, &y);
    node[x].push_back(y);
    node[y].push_back(x);
  }

  stk.push(1);
  visit[1] = 1;
  dfs();

  for (int i = 2; i < ans.size(); i++) {
    printf("%d\n", ans[i]);
  }

  return 0;
}
