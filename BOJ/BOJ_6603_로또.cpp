#include <iostream>
#include <vector>
using namespace std;
//https://www.acmicpc.net/problem/6603

/*
<로또>
주요: DFS, 백트래킹
1. 백트래킹을 이용한 풀이
2. dfs를 수행하면서 결과벡터에 lotto번호를 삽입하고 방문처리한다.
  => 최대값을 전달해줌으로서 중복 출력을 막는다.
3. dfs를 나오면서 결과벡터에 lotto번호를 빼주고 방문처리를 풀어준다.

*/
int N;
vector<int> lotto;
vector<int> result;
vector<int> visit;

void dfs(int level, int max){

  if(level == 6){

    for (int i = 0; i < 6; i++) {
      cout << result[i] << " ";
    }
    cout <<"\n";
    return;
  }
  else{
    for (int i = max; i < N; i++) {
      if(visit[i] == 0){
        result.push_back(lotto[i]);
        visit[i] = 1;
        dfs(level + 1, i);
        visit[i] = 0;
        result.pop_back();
      }
    }
  }
}


int main() {

  while (cin >> N) {
    if(N == 0){ break;}

    int num;
    lotto.clear();
    result.clear();
    visit.assign(N, 0);

    for (int i = 0; i < N; i++) {
      cin >> num;
      lotto.push_back(num);
    }
    dfs(0, 0);
    cout << "\n";
  }

  return 0;
}
