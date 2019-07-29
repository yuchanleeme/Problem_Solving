#include <iostream>
#include <vector>
using namespace std;
//https://www.acmicpc.net/problem/15652

/*
<N과 M(4)>
주요: DFS, 백트래킹
1. 백트래킹을 이용한 기본적인 풀이
2. 중복을 허용 했으므로 방문처리를 따로 하지 않는다.
  -> 방문처리를 하는 경우 : 중복 불허로 같은 값이 나오지 않는다.
3. dfs함수의 인자에 비교를 시작하는 최소값을 전달해 비내림차순을 만든다.
4. 함수를 호출 했을때 level값과 M이 같다면 seq벡터를 출력해준다.
===========
* N과M(1)과 다른점 : 방문(visit)벡터기 필요없다, 최소값 인자를 전달한다.
  -> 중복을 허용 했기 때문에 for문 순서대로 그냥 벡터에 삽입하면 된다.
  -> 최소값 인자를 전달함으로서 for문이 돌고 seq에 넣을때 비내림차순으로 만들게 된다.

*/

int N, M;
vector<int> seq;

void dfs(int level, int min){
  // 4번
  if(level == M){
    for (int l = 0; l < M; l++) {
      cout << seq[l] << " ";
    }
    cout << "\n";
    return;
  }
  else{
    // 2,3번
    for (int i = min; i <= N; i++) {
        seq.push_back(i);
        dfs(level + 1, i);
        seq.pop_back();
      }
    }
 }

int main() {

  cin >> N >> M;

  dfs(0, 1);

  return 0;
}
