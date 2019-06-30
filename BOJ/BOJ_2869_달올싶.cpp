#include <iostream>
using namespace std;
// https://www.acmicpc.net/problem/2869

/*
<달팽이는 올라가고 싶다>
주요: 수학
1. 마지막날 부분만 조심한다.
2. 총 높이 V - 낮길이 A 를 A-B로 나누면 다음 낮에 끝날지 아니면 하루 더걸릴지를 알 수 있게된다.
 = > 딱 목표지점에서 A 만큼 떨어져있다면 하루, 아닌 경우 2일이 소요된다.
3. 즉, 총 구하는 길이는 [(V-A) / (A-B)] + 1 or [(V-A) / (A-B)] + 2 이 된다.

*/

int main() {

  int A, B, V, day;

  cin >> A >> B >> V;

  day = ((V-A) / (A-B));

  if((V-A) % (A-B) == 0){
    day += 1;
  }
  else{
    day += 2;
  }

  cout << day;

  return 0;
}
