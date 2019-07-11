#include <iostream>
using namespace std;
//https://www.acmicpc.net/problem/1913

/*
<달팽이>
주요: 달팽이 알고리즘
1. 한 loop 안에 한번에 해결할 방법이 없나 생각해 본다.
2. Down up 은 배열의 x값만 바뀌고 Right, Left는 배열의 y값만 바뀌는데 주목한다.
3. 반복되는 행위를 찾는다 DRUL / DRUL / D ....
  ex) N = 5 -> 5443 /3221 /1
4. 위를 종합해 알고리즘을 만든다.

*/

int snail[1000][1000];
int main() {

  int N, M, std, val, ans_x, ans_y, x = -1, y = 0, idx = 1;

  cin >> N >> M;

  std = N;
  val = N * N;
  while(std != 0){

    for (int i = 0; i < std; i++) {
      x += idx;
      snail[x][y] = val--;
    }

    std--;
    if(std < 0){ break;}

    for (int i = 0; i < std; i++) {
      y += idx;
      snail[x][y] = val--;
    }

    idx *= -1;
  }


  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cout << snail[i][j] << " ";
      if(M == snail[i][j]){
        ans_x = i, ans_y = j;
      }
    }
    cout << endl;
  }
  cout << ans_x + 1 << " " << ans_y + 1;

  return 0;
}
