#include <bits/stdc++.h>
using namespace std;
// https://www.acmicpc.net/problem/15886

/*
<내 선물을 받아줘 2>
주요: 구현
1. 주어진 입력에서 지도 밖으로 나가는 경우는 없다.
2. 만약 현재 위치가 'E'인데, 이전이 W이면 res(선물 수)값을 올린다.
3. 나머지 경우에는 이전 위치의 값들을 따라간다.
4. res의 값을 출력한다.
==========
* "EW"의 개수를 세는 것과 같다.

*/

int N, res = 1;
int gift[1010];
string board;

int main(){

  cin >> N >> board;

  gift[0] = res;
  for (int i = 1; i < board.length()-1; i++) {
    if(board[i] == 'E'){
      if(board[i-1] == 'E') gift[i] = gift[i-1];
      else{
        gift[i] = ++res;
      }
    }
    else if(board[i] == 'W'){
      gift[i] = gift[i-1];
    }
  }

  cout << res;
  return 0;
}
