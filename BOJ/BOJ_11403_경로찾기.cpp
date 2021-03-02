#include <bits/stdc++.h>
using namespace std;
//https://www.acmicpc.net/problem/11403

/*
<경로 찾기>
주요: DFS
1. 0~N-1 까지 하나씩 dfs 탐색을 통해 각 정점까지 도달하는지 체크한다.
2. 새로운 answer 배열을 만들어 해당하는 숫자를 다 기록한다.
3. answer배열을 출력한다.

*/

int N;
int answer[110][110];
int graph[110][110];

void dfs(int now, int prev, vector<int> &isChecked){

  for (int i = 0; i < N; i++) {
    if(graph[prev][i] == 1){
      if(isChecked[i] == 0){
        int next = i;
        answer[now][i] = 1;
        isChecked[i] = 1;
        dfs(now, next, isChecked);
      }
    }
  }
}

int main(int argc, char const *argv[]) {
  cin >> N;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cin >> graph[i][j];
    }
  }

  for (int i = 0; i < N; i++) {
    vector<int> isChecked(N, 0);
    dfs(i, i, isChecked);
  }

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cout << answer[i][j] << " ";
    }
    cout << endl;
  }
  return 0;
}
