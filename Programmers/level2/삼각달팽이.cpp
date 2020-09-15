#include <bits/stdc++.h>
using namespace std;
//https://programmers.co.kr/learn/courses/30/lessons/68645

/*
<삼각 달팽이>
주요: 구현
1. 2차원 배열에 값을 써내려가도록 구현한다.
2. 갈수 있는 방향은 아래방향, 오른쪽 방향, 좌상대각선 방향 총 세가지이므로 모드를 3으로 설정한다.
3. 각 방향에 따라 board에 값을 써내려간다.
  3-1. 방향이 전환 될때마다 써내려 가야하는 개수가 하나씩 감소한다.
  3-2. ex) 아래 : 1 2 3 4, 오른쪽 : 5 6 7, 좌상: 8 9 , 아래 10
  3-3. 이를 이용해 구현한다.
4. 최종적으로 board를 순회하면서 0이 아닌 값일때만 answer에 넣는다.
==========
* 너무 어렵게 생각해서 살짝 고민했는데 개수를 세다 규칙을 발견해서 구현할 수 있었다.
* 코드를 조금 더 최적화 하는 스킬을 길러야겠다.

*/

int board[1010][1010];
vector<int> solution(int n) {
  vector<int> answer;
  int mode = 0;
  int x = 0, y = 0; // board[x][y]
  int num = 1;  // board에 써질 숫자 값
  int number = n;

  while (n != 0) {

    if(mode == 0){  //아래
      for (int i = 0; i < n; i++) {
        board[x+i][y] = num++;
      }
      x += (n-1);
      y += 1;
      mode = 1;
    }
    else if(mode == 1){ // 오른쪽
      for (int i = 0; i < n; i++) {
        board[x][y+i] = num++;
      }
      x -= 1;
      y += (n-2);
      mode = 2;
    }
    else if(mode == 2){ // 좌상대각선
      for (int i = 0; i < n; i++) {
        board[x-i][y-i] = num++;
      }
      x -= (n-2);
      y -= (n-1);
      mode = 0;
    }
    n--;
  }

  // 4번
  for (int i = 0; i < number; i++) {
    for (int j = 0; j < number; j++) {
      if(board[i][j] == 0)break;
      answer.push_back(board[i][j]);
    }
  }
  
  return answer;
}
