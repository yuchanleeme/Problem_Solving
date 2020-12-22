#include <bits/stdc++.h>
using namespace std;
//https://www.acmicpc.net/problem/10709

/*
<기상캐스터>
주요: 구현
1. 먼저 INF 값으로 배열을 초기화 시켜준다.
2. 이제 순회를 하면서 구름이 있으면 한칸씩 앞으로 전진하면서 예상 도착시간을 최신화 시킨다.
  => 최소값이 되도록 최신화 한다.
3. 다시 순회를 하면서 아직 INF 값이면 구름이 안 오는 것이므로 -1로 바꿔서 출력한다.
  => 나머지는 구름의 최소 도착시간을 출력한다.

*/

const int INF = 200;
int H, W;
int square[110][110];
int answer[110][110];

int main(int argc, char const *argv[]) {
  scanf("%d %d", &H, &W);
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      scanf(" %1c", &square[i][j]);
      if(square[i][j] == 'c') answer[i][j] = 0;
      else answer[i][j] = INF;
    }
  }

  // 2번
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      int cnt = 0;
      if(square[i][j] == 'c'){
        for (int k = j+1; k < W; k++) {
          cnt++;
          answer[i][k] = min(answer[i][k], cnt);
        }
      }
    }
  }

  // 3번
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      if(answer[i][j] == INF) answer[i][j] = -1;
      printf("%d ", answer[i][j]);
    }
    printf("\n");
  }

  return 0;
}
