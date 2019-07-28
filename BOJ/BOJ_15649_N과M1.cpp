#include <iostream>
#include <vector>
#include <stack>
using namespace std;
//https://www.acmicpc.net/problem/15649

/*
<N과 M>
주요: DFS, 백트래킹
1. 백트래킹을 이용한 기본적인 풀이
2. 방문체크를 해주면서 순서대로 벡터에 삽입한다.
  -> dfs 함수를 수행하면서 방문안한 i 값은 벡터에 넣어주고 방문처리 한다.
  -> dfs를 수행 할때마다 level값을 증가시켜 dfs함수를 재호출한다. (몇번째 값인지 순서 파악)
  -> dfs 함수를 나왔다면 방문한 i값을 벡터에서 빼주고 방문처리를 원상복구한다.
  -> 이렇게 하면 각 level값에 따라 백트래킹이 완성된다.
3. 함수를 호출 했을때 level값과 M이 같다면 seq벡터를 출력해준다.
===========
* 시간초과가 나서 endl -> "\n" 으로 바꿔주었더니 통과가 됐다

*/

int N, M;
vector<int> seq;
vector<int> visit;

void dfs(int level){
  // 3번
  if(level == M){
    for (int l = 0; l < M; l++) {
      cout << seq[l] << " ";
    }
    cout << "\n";
    return;
  }
  else{
    // 2번
    for (int i = 1; i <= N; i++) {
      if(visit[i] == 0){
        visit[i] = 1;
        seq.push_back(i);
        dfs(level + 1);
        visit[i] = 0;
        seq.pop_back();
      }
    }
  }
}

int main() {

  cin >> N >> M;

  visit = vector<int>(N+1, 0);

  dfs(0);

  return 0;
}
