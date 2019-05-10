#include <iostream>
using namespace std;
//https://www.acmicpc.net/problem/1018

/*
<체스판 다시 칠하기>
주요: 8*8 칸을 하나씩 비교해 본다.
1. B,W로 각각 시작하는 8*8 비교판을 만든다.
2. 맵을 입력 받고 각각의 비교판과 비교해본다.
3. 같지 않은 부분이 있으면 각각 카운팅 하고 그 중 가장 작은 값을 count_res에 저장한다.
4. 비교 가능한 모든 구역을 비교해서 그 중 제일 작은 coount_res를 출력한다.

*/

int main(){

  char checking_white[8][8];
  char checking_black[8][8];

  int N,M;
  int count_b = 0;
  int count_w = 0;
  int count_res = 100;

  // checking_white 판 만들기
  for (int i = 0; i < 8; i++){
    for (int j = 0; j < 8; j++){
      if((i+j)%2 == 0){
        checking_white[i][j] = 'B';
      }
      else{
        checking_white[i][j] = 'W';
      }
    }
  }
  // cehcking_blakc 판 만들기
  for (int i = 0; i < 8; i++){
    for (int j = 0; j < 8; j++){
      if((i+j)%2 == 0){
        checking_black[i][j] = 'W';
      }
      else{
        checking_black[i][j] = 'B';
      }
    }
  }

  cin >> N >> M;

  // 맵 입력
  char input_map[N][M];
  for(int i = 0; i < N; i++){
     for(int j = 0; j < M; j++){
      cin >> input_map[i][j];
     }
   }

  // 맵 비교
  for(int i = 0; i < N-7; i++){
     for (int j = 0; j < M-7; j++) {

       for(int x = 0; x < 8; x++){
         for(int y = 0; y < 8; y++){
           if(input_map[x+i][y+j] != checking_black[x][y]){
             count_b++;
           }
           if(input_map[x+i][y+j] != checking_white[x][y]){
             count_w++;
           }
         }
       }
       if(count_res > count_b){
         count_res = count_b;
       }
       if(count_res > count_w){
         count_res = count_w;
       }

       count_b = 0;
       count_w = 0;
     }
   }

  cout << count_res << endl;

  return 0;
}
