#include <iostream>
using namespace std;
// https://www.acmicpc.net/problem/1072

/*
<게임>
주요: 수학
1. X : 총판수, Y : 이긴판수, Z: 현재 확률 , A: 필요한 게임 수
2. 아래 공식을 만족시키는 A를 구하면된다.
   (Y+A)
  ------- X 100  >= Z + 1
   (X+A)
3. 위의 계산값이 나누어 떨어지면 그대로 A, 아니면 A+1
4. 승률이 99퍼이상 일때는 몇판을 이겨도 100퍼가 될수 없기에 -1

*/

int main() {

  long long X, Y, Z, A;

  cin >> X >> Y;

  Z = (100*Y / X); // 확률

  if(Z < 99){
    A = (X*(Z+1) - 100*Y) / (99-Z);
    if((X*(Z+1) - 100*Y) % (99-Z) == 0){
      cout << A;
    }
    else{
      cout << A + 1;
    }
  }
  else{
    cout << "-1";
  }

  return 0;
}
