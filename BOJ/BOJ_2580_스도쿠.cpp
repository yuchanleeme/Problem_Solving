#include <iostream>
#include <vector>
using namespace std;
//https://www.acmicpc.net/problem/2580

/*
<스도쿠>
주요: DFS, 백트래킹
1. 백트래킹을 이용해 푼다.
2. 스도쿠 퍼즐을 입력 받고 0의 개수를 세준다.
3. 0,0 부터 8,8 까지 check_num 함수와 백트래킹을 이용해 값을 채운다.
  => 0을 다 채우면 end_game변수를 참으로 하여 찾는것을 끝낸다.
  => 다 채웠을 때만 스도쿠 퍼즐을 출력한다.

*/

int count = 0;
bool end_game = false;
vector<vector<int> > sudoku;

// x,y좌표에 num이 들어갈 수 있는지 확인
bool check_num(int x, int y, int num){

  // 세로
  for (int i = 0; i < 9; i++) {
    if(i != x && sudoku[i][y] == num){
      return false;
    }
  }

  // 가로
  for (int i = 0; i < 9; i++) {
    if(i != y && sudoku[x][i] == num){
      return false;
    }
  }

  // 3X3 박스
  int temp_x = (x/3) * 3, temp_y = (y/3) * 3;
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      if(x != (temp_x+i) && y != (temp_y+j)){
        if(sudoku[temp_x+i][temp_y+j] == num){
          return false;
        }
      }
    }
  }

  return true;
}

void back_tracking(int num, int x, int y){

  if(end_game){
    return;
  }
  else{
    // 0을 다 찾은 경우
    if(num == count){
      for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
          cout << sudoku[i][j] << " ";
        }
        cout << endl;
      }
      end_game = true;
      return;
    }
    else{
      for (int i = x; i < 9; i++) {
        for (int j = y; j < 9; j++) {
          if(sudoku[i][j] == 0){
            for (int k = 1; k <= 9; k++) {
              if(check_num(i, j, k)){
                sudoku[i][j] = k;
                back_tracking(num+1,i,j);
                sudoku[i][j] = 0;
              }
            }
            return; // 1~9 다찾았는데도 불가능한 경우
          }
        }
        y = 0; // y값을 0으로 취해주어 2중 for문에서 x,y 다음으로 진행이 가능하다.
      }
    }
  }
}

int main() {

  sudoku = vector<vector<int> >(9, vector<int>(9, 0));

  for (int i = 0; i < 9; i++) {
    for (int j = 0; j < 9; j++) {
      cin >> sudoku[i][j];
      if(sudoku[i][j] == 0){ count++;}
    }
  }

  back_tracking(0, 0, 0);

  return 0;
}
