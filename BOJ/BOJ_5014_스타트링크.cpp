#include <bits/stdc++.h>
using namespace std;
// https://www.acmicpc.net/problem/5014

/*
<스타트링크>
주요: BFS
1. 방문한 building은 다시 방문하지 않는다. (building 배열)
2. 큐에 방문할 다음 방문할 층들의 정보를 넣어서 갱신한다.
3. BFS 탐색을 통해 누른 버튼의 수를 출력한다.

*/

int F, S, G, U, D, trial;
int building[2000010];
queue<int> que;

int main(){
  scanf("%d %d %d %d %d", &F, &S, &G, &U, &D);
  if(S == G) return !printf("0"); // 버튼 안 눌러도 됐을 때

  // 처음 S 값처리
  building[S] = 1;
  que.push(S);

  while (!que.empty()) {
    trial++;
    int temp_size = que.size();
    for (int i = 0; i < temp_size; i++) {
      int up = que.front() + U;
      int down = que.front() - D;
      que.pop();

      // up 버튼 확인
      if(building[up] != 1 && up <= F){
        if(up == G) return !printf("%d", trial);
        building[up] = 1;
        que.push(up);
      }

      // down 버튼 확인
      if(building[down] != 1 && down >= 1){
        if(down == G) return !printf("%d", trial);
        building[down] = 1;
        que.push(down);
      }
    }
  }
  printf("use the stairs");
}
