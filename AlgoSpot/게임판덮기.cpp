#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
//https://algospot.com/judge/problem/read/BOARDCOVER

/*
<게임판 덮기>
주요: 백트래킹, 구현
1. 가장 중요한 점은 자신 기준 왼쪽, 위쪽 칸은 무조건 채워져있다고 가정해야 한다는 것이다.
  => L타일을 끼워서 맞춰보는 개수가 확 줄어든다. (중복 제거)
  => 왼쪽, 위쪽 칸이 다 채워져있을 때 내 위치에서 끼울 수 있는 L타일 모양은 4개이다.
2. 백트래킹을 하면서 가능한 타일들을 다 끼워 맞춰본다.
  => 끼웠으면 방문처리 한 뒤 재귀호출
  => 뱄으면 방문 취소 처리 한 뒤 for문 진행
3. 다음에 끼울 위치를 찾는 함수를 만든다. (find_rc 함수)
  => 끼울 곳이 있다면 그 위치 좌표 리턴
  =>  더이상 끼울 부분이 없으면 -1,-1 리턴
4. -1 이라면 하나 완성한것이므로 ans 값을 증가 시키고 최종 값을 출력한다.

===========
* 초과 범위 선정 할 때 주의해야함 (out of range, 구간끝 등호 표시 주의)
* 좌표 loc 설정할 때 3차원 배열을 사용할 수 있다는 점을 유의한다.
* 변수 초기화 주의
* 중복으로 세는 법을 최대한 피한다. (Ex. 자신기준 12방향 다 세기 등)

*/

int T, H, W, goal, ans;
int board[25][25];
int loc[4][3][2] =
{
  {{0, 0}, {0, 1}, {1, 1}},
  {{0, 0}, {1, 0}, {1, 1}},
  {{0, 0}, {1, 0}, {1, -1}},
  {{0, 0}, {0, 1}, {1, 0}},
};

// pair 형태로 다음 row col 값 찾기
pair<int, int> find_rc(){

  pair<int, int> location = {-1, -1};
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      if(board[i][j] == 0)
        return {i,j};
    }
  }
  return location;
}

void backtracking(int level, int row, int col){

  // 4개 shape 형태의 L 타일 끼워 보기
  for (int i = 0; i < 4; i++) {
    bool fill_board = true;
    for (int j = 0; j < 3; j++) {
      int x = loc[i][j][0] + row;
      int y = loc[i][j][1] + col;

      if(board[x][y] == 1 || x < 0 || x >= H || y < 0 || y >= W){
        fill_board = false;
        break;
      }
    }

    // 채울 수 았다면 재귀
    if(fill_board){
      // 방문처리
      for (int j = 0; j < 3; j++) {
        int x = loc[i][j][0] + row;
        int y = loc[i][j][1] + col;
        board[x][y] = 1;
      }

      // 다음 채울위치 찾기
      pair<int, int> next = find_rc();
      if(next.first == -1){
        ans+= 1;
      }
      else
        backtracking(level+1, next.first, next.second);

      // 나왔으니까 방문 해제
      for (int j = 0; j < 3; j++) {
        int x = loc[i][j][0] + row;
        int y = loc[i][j][1] + col;
        board[x][y] = 0;
      }
    }
  }
}

int main(int argc, char const *argv[]) {

  cin >> T;
  for (int tc = 0; tc < T; tc++) {
    cin >> H >> W;
    goal = 0;
    ans = 0;

    // #이면
    for (int row = 0; row < H; row++) {
      for (int col = 0; col < W; col++) {
        char input;
        cin >> input;
        if(input == '#'){
          board[row][col] = 1;
        }
        else{
          board[row][col] = 0;
          goal += 1;
        }
      }
    }

    // 3으로 나누어 떨어지지 않으면 skip 한다.
    if(goal % 3 != 0){
      cout << 0 << "\n";
      continue;
    }

    // 시작 위치 찾기 및 백트래킹 수행
    pair<int, int> start = find_rc();
    backtracking(0, start.first, start.second);

    cout << ans << "\n";
  }

  return 0;
}
