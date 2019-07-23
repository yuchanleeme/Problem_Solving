#include <iostream>
#include <cstring>
#include <queue>
using namespace std;
//https://www.acmicpc.net/problem/1389

/*
<케빈 베이컨의 6단계 법칙>
주요: BFS
1. BFS를 이용해서 각각의 케빈 베이컨 수를 구한다.
2. 같은 너비에서는 step값을 같게 하고 깊이가 깊어질때마다 step값을 1씩 더해준다.
3. 만약 찾아야하는 정점을 방문했다면 그때의 step값을 ans에 각각 더해준다.
4. BFS 함수를 돌고 리턴되는 ans값이 시작 정점의 케빈 베이컨의 수다.
5. 이를 비교해서 조건에 맞는 답을 도출한다.

*/

int N, M, line, target;
int friends[101][101];
int visit[101];

int bfs(int num){

  int temp_size, step = 0, ans = 0;
  queue<int> que;

  que.push(num);
  visit[num] = 1;

  while(!que.empty()){
    temp_size = que.size();
    step++;
    for (int i = 0; i < temp_size; i++) {
      for (int j = 1; j <= N; j++) {
        if(visit[j] == 0){
          if(friends[que.front()][j] == 1){
            visit[j] = 1;
            ans += step;
            que.push(j);
          }
        }
      }
      que.pop();
    }
  }
  return ans;
}

int main() {

  cin >> N >> M;

  int a, b, temp, ans, comp;

  // 양방향 그래프 저장
  for (int i = 0; i < M; i++) {
    cin >> a >> b;
    friends[a][b] = 1;
    friends[b][a] = 1;
  }

  // 초기값 지정
  comp = bfs(1);
  ans = 1;

  for (int i = 2; i <= N; i++) {
    memset(visit, 0, sizeof(visit));
    temp = bfs(i);
    if(temp < comp){
      comp = temp;
      ans = i;
    }
  }

  cout << ans;

  return 0;
}
