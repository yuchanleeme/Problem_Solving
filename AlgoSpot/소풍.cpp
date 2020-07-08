#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
//https://algospot.com/judge/problem/read/PICNIC

/*
<소풍>
주요: 구현, 재귀
1. 친구 관계 그래프를 만들 때 작은 번호의 벡터에 한번만 저장시킨다.
2. 번호가 증가하는 순서로 짝을 찾는다.
  2-1. 기저조건 : level 이 N으로 모든 학생이 짝을 가졌을때 ans값을 증가시키고 종료
  2-2. 자신과 연결된 번호 중 방문 하지 않았고, 번호가 증가하는 방향으로 방문한다.
  2-3. 짝을 찾았으면 level + 2를 해주고 계속 짝을 매칭한다.
  2-4. 방문 종료 시 다른 경우의 수를 위해 방문 해제 해준다.
3. 최종 ans 값을 출력한다.
==========
* 시간초과 유의 : 인접리스트 만들 때 양방향 할 필요 없음(번호 큰 순서대로 할거니까)
* 중복이 됐다면 팩토리얼을 이용하는 법이 있지만 비효율적이다. (시간이 더 증가)
  => 중복을 최대한 줄이는 방향으로 생각해야 한다.

*/

int N, M, ans;
vector<int> relation[11];
vector<int> visit(11, 0);
void nextStep(int level, int num){

  // 2-1번
  if(level == N){
    ans+=1;
    return;
  }

  for (int i = num; i < N; i++) {
    if(visit[i] == 0){
      visit[i] = 1;
      for (int j = 0; j < relation[i].size(); j++) {
        // 2-2번
        int next = relation[i][j];
        if(visit[next] == 1) continue;
        if(next < i) continue;
        visit[next] = 1;
        nextStep(level+2, i+1); // 2-3번
        visit[next] = 0; // 2-4번
      }
      visit[i] = 0; // 2-4번
    }
  }
}

int main(int argc, char const *argv[]) {

  int C;
  cin >> C;

  for (int tesctace = 0; tesctace < C; tesctace++) {
    ans = 0;
    visit.clear();
    for (int i = 0; i < 11; i++)
      relation[i].clear();

    cin >> N >> M;
    for (int fr = 0; fr < M; fr++) {
      int x, y;
      cin >> x >> y;
      // 1번
      if(x > y) swap(x,y);
      relation[x].push_back(y);
    }

    nextStep(0, 0);
    cout << ans << "\n";
  }

  return 0;
}
