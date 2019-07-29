#include <iostream>
#include <vector>
using namespace std;
//https://www.acmicpc.net/problem/15650

/*
<N과 M(2)>
주요: DFS, 백트래킹
1. 백트래킹을 이용한 기본적인 풀이
2. 방문체크를 해주면서 순서대로 벡터에 삽입한다.
  -> dfs 함수를 수행하면서 방문안한 i 값은 벡터에 넣어주고 방문처리 한다.
  -> dfs를 수행 할때마다 level값을 증가시켜 dfs함수를 재호출한다. (몇번째 값인지 순서 파악)
  -> 현재 인자를 전달 시켜서 for문을 돌린다. -> 오름차순 정렬을 위해
  -> dfs 함수를 나왔다면 방문한 i값을 벡터에서 빼주고 방문처리를 원상복구한다.
  -> 이렇게 하면 각 level값에 따라 백트래킹이 완성된다.
3. 함수를 호출 했을때 level값과 M이 같다면 seq벡터를 출력해준다.
===========
* N과M(1)과 다른점 : dfs함수가 인자를 2개 받는다 (기존 level, 최소값)
  -> 최소값을 전달 시켜 for문을 돌림으로서 자기 자신보다 작은값은 seq벡터에 넣지 않는다.

*/

int N, M;
vector<int> seq;
vector<int> visit;

void dfs(int level, int min){
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
    for (int i = min; i <= N; i++) {
      if(visit[i] == 0){
        visit[i] = 1;
        seq.push_back(i);
        dfs(level + 1, i);
        visit[i] = 0;
        seq.pop_back();
      }
    }
  }
}

int main() {

  cin >> N >> M;

  visit = vector<int>(N+1, 0);

  dfs(0, 1);

  return 0;
}
