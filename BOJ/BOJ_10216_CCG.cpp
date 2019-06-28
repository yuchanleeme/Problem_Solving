#include <iostream>
#include <vector>
using namespace std;
//https://www.acmicpc.net/problem/10216

/*
<Count Circle Groups>
주요: DFS
1. 0번 idx 입력값부터 하나씩 탐색한다.
2. 방문하지 않았다면 그룹값(ans)을 1 올려주고 enemy_count 함수를 호출한다.
 => enemy_count : DFS를 이용해 연결되어 있고 방문한적이 없다면 방문표시를 한다.
 => is_area : 비교값 두 개를 입력받아 두 범위의 관계를 밝힌다.
3. 이렇게 모든 idx를 조사하고 계산된 그룹값 출력

*/

int T, N, ans;
vector<vector<int> > info;
vector<int> visit;

// 접하거나 겹치면 true 리턴, 아니면 false 리턴
bool is_area(int n1, int n2){

  int x = (info[n1][0] - info[n2][0]);
  int y = (info[n1][1] - info[n2][1]);
  int r1 = info[n1][2];
  int r2 = info[n2][2];

  if(x*x + y*y > (r1+r2) * (r1+r2)){
    return 0;
  }
  else{
    return 1;
  }
}

// DFS
void enemy_count(int num){

  visit[num] = 1;
  for (int i = 0; i < N; i++) {
    if(visit[i] == 0){
      if(is_area(num, i)){
        enemy_count(i);
      }
    }
  }
}

int main() {

  cin >> T;
  for (int testcase = 0; testcase < T; testcase++) {

    ans = 0;
    cin >> N;
    info.assign(N,vector<int>(3,0));
    visit.assign(N,0);

    for (int enemy = 0; enemy < N; enemy++) {
      cin >> info[enemy][0] >>info[enemy][1] >> info[enemy][2];
    }

    // 1,2번
    for (int i = 0; i < N; i++) {
      if(visit[i] == 0){
        ans++;
        enemy_count(i);
      }
    }

    // 3번
    cout << ans <<endl;
  }

  return 0;
}
