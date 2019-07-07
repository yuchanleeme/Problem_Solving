#include<iostream>
#include<vector>
using namespace std;
// https://www.acmicpc.net/problem/1325

/*
<효율적인 해킹>
주요: DFS
1. 신뢰관계를 파악해 연결되어 있는 가장 연결이 많이 되어있는 정점을 찾는다.
2. 오름차순 나열이므로 정점 번호가 작은 것 부터 조사한다.
3. 메모리 초과를 줄이기 위해 인접행렬이 아닌 간선의 정보만 저장한다.
===========
* 벡터의 활용법 파악(인접행렬 -> 간선의 정보 저장)

*/

int N, cnt;
vector<int> computer[10002];
vector<int> visit(10002, 0);

void dfs(int num){

  visit[num] = 1;

  for (int i = 0; i < computer[num].size(); i++) {
    if(visit[computer[num][i]] == 0){
        cnt++;
        dfs(computer[num][i]);
    }
  }
}

int main() {

  int M, a, b, temp_max = 0;
  vector<int> ans;
  cin >> N >> M;

  // 3번
  for (int trust = 0; trust < M; trust++) {
    cin >> a >> b;
    computer[b].push_back(a);
  }

  // 1, 2번
  for (int i = 1; i <= N; i++) {
    cnt = 0;
    visit.assign(N+2, 0);
    dfs(i);
    if(temp_max < cnt){
      ans.clear();
      ans.push_back(i);
      temp_max = cnt;
    }
    else if(temp_max == cnt){
      ans.push_back(i);
    }
  }

  for (int i = 0; i < ans.size(); i++) {
    cout << ans[i] << " ";
  }

  return 0;
}
