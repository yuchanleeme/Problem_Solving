#include <iostream>
using namespace std;
//https://www.acmicpc.net/problem/17521

/*
<Byte Coin>
주요: 구현
1. 쌀때 샀다가 비쌀때 팔면 된다.
2. 내려가고 올라가는것을 switch화 해서 구현한다.
==========
* 모든 경우의 수를 큐에 넣어서 계산하는 방법을 썼는데 계속 런타임 에러가 나왔다.
* 그냥 단순 아이디어 구현이었다. DP도 아니고 그냥 구현
* coin도 충분히 커질 수 있음에 유의한다.

*/

long long N, W, coin, price[20];
int main() {

  cin >> N >> W;
  for (int i = 1; i <= N; i++) {
    cin >> price[i];
  }

  // 처음은 내려가는 중이라 생각한다.
  bool down = true;
  bool up = false;

  for (int i = 1; i <= N; i++) {

    if(price[i+1] > price[i]){
      // 내려가는 중인데 다음 값이 나보다 크다면 매수
      if(down){
        coin = W / price[i];
        W = W % price[i];
      }
      up = true;
      down = false;
    }
    else if(price[i+1] < price[i]){
      // 올라가는 중인데 다음 값이 나보다 작다면 매도
      if(up){
        W += coin * price[i];
        coin = 0;
      }
      up = false;
      down = true;
    }
  }

  // 마지막 남은 코인까지 판다.
  W += coin * price[N];
  cout << W;

  return 0;
}
