#include <iostream>
using namespace std;
//https://www.acmicpc.net/problem/1712

/*
<손익분기점>
주요: 계산
1. x를 판매 대수라고 하면 A + B*x < C*x 가 처음 성립하는 x값을 찾는다.
2. C-B가 0보다 작거나 같은 경우는 손익분기점이 존재 할 수 없다.
  => 분모가 될 수 없거나 음수

*/

int main() {

  int A, B, C, ans;

  cin >> A >> B >> C;

  if(C-B <= 0){
    cout << -1;
  }
  else{
    ans = A / (C-B) + 1;
    cout << ans;
  }

  return 0;
}
