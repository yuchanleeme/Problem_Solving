#include <iostream>
#include <vector>
using namespace std;
//https://www.acmicpc.net/problem/14499

/*
<주사위 굴리기>
주요: 구현
1. 주사위의 고정위치 idx를 생각한다.
  => idx (0~5) : 상, 하, 왼, 오, 전, 후
  => 주사위 값은 각 위치에 따라 배정되는 것으로 한다.
2. 동, 서, 남, 북으로 이동 시 값들을 바꿔준다.
  2-0. 이동 불가시 continue로 무시하고 진행한다.
  2-1. 일단 똑같은 주사위 값을 복사해놓는다.
  2-2. 각 방향으로 이동 했을 때 바뀐 값을 2-1에 복사한 값을 이용해 주사위값에 옮긴다.('하'면 제외)
  2-3. 문제 조건에 맞게 maps타일이 0일때와 아닐때를 비교해서 값을 넣는다.
    => 타일값 0일때 : 주사위 '하' dice_eyes[1] 값(temp_eyes[*]) -> maps[x][y]로 복사
    => 타일값 0 아닐 때 : maps[x][y]값 -> 주사위 '하' dice_eyes[1]로 복사, maps[x][y] = 0
3. 마지막으로 dice_eyes[0] 주사위 '상' 값을 출력한다.
4. 명령이 끝날때까지 진행한다.

==========
* 조건을 빼먹지 말고 코딩할 것
* 중복되는 부분은 함수로 구현해도 좋을 것 같다.

*/

int dice_eyes[6] = {0, 0, 0, 0, 0, 0}; // 상 하 왼 오 전 후
int maps[21][21];

// 동쪽 이동 order : 1
void move_E(int &x, int &y){

  int temp_eyes[6];
  copy(dice_eyes,dice_eyes+6,temp_eyes);
  dice_eyes[0] = temp_eyes[2];
  dice_eyes[2] = temp_eyes[1];
  dice_eyes[3] = temp_eyes[0];

  if(maps[x][y] != 0){
    dice_eyes[1] = maps[x][y];
    maps[x][y] = 0;
  }
  else{
    dice_eyes[1] = temp_eyes[3];
    maps[x][y] = temp_eyes[3];
  }

  cout << dice_eyes[0] << "\n";
}

// 서쪽 이동 order : 2
void move_W(int &x, int &y){

  int temp_eyes[6];
  copy(dice_eyes,dice_eyes+6,temp_eyes);

  dice_eyes[0] = temp_eyes[3];
  dice_eyes[2] = temp_eyes[0];
  dice_eyes[3] = temp_eyes[1];

  if(maps[x][y] != 0){
    dice_eyes[1] = maps[x][y];
    maps[x][y] = 0;
  }
  else{
    dice_eyes[1] = temp_eyes[2];
    maps[x][y] = temp_eyes[2];
  }

  cout << dice_eyes[0] << "\n";
}

// 북쪽 이동 order : 3
void move_N(int &x, int &y){

  int temp_eyes[6];
  copy(dice_eyes,dice_eyes+6,temp_eyes);

  dice_eyes[4] = temp_eyes[1];
  dice_eyes[5] = temp_eyes[0];
  dice_eyes[0] = temp_eyes[4];

  if(maps[x][y] != 0){
    dice_eyes[1] = maps[x][y];
    maps[x][y] = 0;
  }
  else{
    dice_eyes[1] = temp_eyes[5];
    maps[x][y] = temp_eyes[5];
  }

  cout << dice_eyes[0] << "\n";
}

// 남쪽 이동 order : 4
void move_S(int &x, int &y){

  int temp_eyes[6];
  copy(dice_eyes,dice_eyes+6,temp_eyes);

  dice_eyes[4] = temp_eyes[0];
  dice_eyes[5] = temp_eyes[1];
  dice_eyes[0] = temp_eyes[5];

  if(maps[x][y] != 0){
    dice_eyes[1] = maps[x][y];
    maps[x][y] = 0;
  }
  else{
    dice_eyes[1] = temp_eyes[4];
    maps[x][y] = temp_eyes[4];
  }

  cout << dice_eyes[0] << "\n";
}

int main() {

  int N, M, x, y, K;

  cin >> N >> M >> x >> y >> K;

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      cin >> maps[i][j];
    }
  }

  // 명령에 따른 동,서,남,북 함수 수행
  for (int i = 0; i < K; i++) {
    int order;
    cin >> order;
    if(order == 1){
      if(y+1 >= M){ continue;}
      y += 1;
      move_E(x, y);
    }
    else if(order == 2){
      if(y-1 < 0){ continue;}
      y -= 1;
      move_W(x, y);
    }
    else if(order == 3){
      if(x-1 < 0){ continue;}
      x -= 1;
      move_N(x, y);
    }
    else if(order == 4){
      if(x+1 >= N){ continue;}
      x += 1;
      move_S(x, y);
    }
  }

  return 0;
}
