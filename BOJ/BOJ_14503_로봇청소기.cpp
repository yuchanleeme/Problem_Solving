#include <bits/stdc++.h>
using namespace std;
//https://www.acmicpc.net/problem/14503

/*
<로봇 청소기>
주요: 구현
1. 우선 입력받은 값을 통해 baord에 할당한다.
2. 문제의 조건에 맞게 while문을 돌린다.
3. 계산된 ans를 출력한다.

*/

int board[52][52];
int N, M, x, y, head, ans, cnt; // 북 동 남 서
int dx[4] = {-1 ,0 ,1 ,0}, dy[4] = {0, 1, 0, -1};

int main(int argc, char const *argv[]) {

  cin >> N >> M;
  cin >> x >> y >> head;

  // 맵 만들기
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      cin >> board[i][j];
    }
  }

  while (true) {

    // 1번 조건
    if(board[x][y] == 0){
      ans++;
      cnt = 0;    // 방향 몇번 돌았는지 체크
      board[x][y] = 2;  // 청소 했으면 2
    }
    else{   // 2번 조건
      // 왼쪽 방향으로 head 꺾기
      if(head == 0) head = 3;
      else head -=1;

      // 다음 이동할 위치
      int tmpx = x + dx[head];
      int tmpy = y + dy[head];
      cnt++;

      // 그 위치가 청소 안했으면 이동하고 1번 다시
      if(board[tmpx][tmpy] == 0){
        x = tmpx;
        y = tmpy;
        continue;
      }

      // 4방향 다 돌았을 때
      if(cnt == 4){
        // 후진 방향 head 계산
        if(head+2 >= 4){
          tmpx = x + dx[head-2];
          tmpy = y + dy[head-2];
        }
        else{
          tmpx = x + dx[head+2];
          tmpy = y + dy[head+2];
        }

        // 후진방향이 벽으로 막혀 있으면 청소 종료
        if(board[tmpx][tmpy] == 1){
          break;
        }
        else{
          // 아니면 후진 하고 cnt 초기화
          x = tmpx;
          y = tmpy;
          cnt = 0;
        }
      }
    }
  }

  // 결과 출력
  cout << ans;

  return 0;
}
