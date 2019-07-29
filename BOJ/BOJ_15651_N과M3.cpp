#include <iostream>
#include <vector>
using namespace std;
//https://www.acmicpc.net/problem/15651

/*
<N과 M(3)>
주요: DFS, 백트래킹
1. 백트래킹을 이용한 기본적인 풀이
2. 중복을 허용 했으므로 방문처리를 따로 하지 않는다.
  -> 방문처리를 하는 경우 : 중복 불허로 같은 값이 나오지 않는다.
3. 함수를 호출 했을때 level값과 M이 같다면 seq벡터를 출력해준다.
===========
* N과M(1)과 다른점 : 방문(visit)벡터기 필요없다.
  -> 중복을 허용 했기 때문에 for문 순서대로 그냥 벡터에 삽입하면 된다.

*/

int N, M;
vector<int> seq;

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
        seq.push_back(i);
        dfs(level + 1);
        seq.pop_back();
      }
    }
 }

int main() {

  cin >> N >> M;

  dfs(0);

  return 0;
}
