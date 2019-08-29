#include <iostream>
#include <vector>
#include <stack>
using namespace std;
//https://www.acmicpc.net/problem/2606

/*
<바이러스>
주요: DFS
1. 간선들의 정보를 입력 받고 양방향으로 정보를 저장한다.
2. DFS 탐색을 통해 감염된 컴퓨터의 개수를 센다
  -> pop해줄때 count값 올려준다.
3. '감염된' 컴퓨터 개수이므로 1번 컴퓨터 개수를 뺀 값을 출력한다.

=========
* 간선 양방향, 초기값 방문 체크

*/
int N, line, count = 0;
vector<vector<int> > v;
vector<int> visit;
stack<int> stk;

void dfs(){

  stk.push(1);
  visit[1] = 1;
  while(stk.size() != 0){
    int temp_top = stk.top();
    bool is_end = true;
    for (int i = 0; i < v[temp_top].size(); i++) {
      if(visit[v[temp_top][i]] == 0){
        stk.push(v[temp_top][i]);
        visit[v[temp_top][i]] = 1;
        is_end = false;
      }
    }

    if (is_end) {
      stk.pop();
      count++;
    }
  }
}

int main() {

  cin >> N >> line;
  v = vector<vector<int> >(N+1);
  visit = vector<int>(N+1, 0);

  int x, y;
  for (int i = 0; i < line; i++) {
    cin >> x >> y;
    v[x].push_back(y);
    v[y].push_back(x);
  }
  dfs();
  cout << count - 1 << endl;


  return 0;
}
