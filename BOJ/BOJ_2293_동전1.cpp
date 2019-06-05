#include <iostream>
using namespace std;
//https://www.acmicpc.net/problem/2293

/*
<동전 1>
주요: DP를 활용한다.
1. 1번째 동전만을 이용해 1부터 k 까지 가능한 경우의 수를 찾는다.
2. 1,2번째 동전만을 이용해 1부터 k까지 가능한 경우의 수를 찾는다. (DP활용)
  => ex) 예제기준 coin_count[4] = 1111 , 112, 22 인데 112,22 는 coin_count[2](11,2)에 2만큼 추가한 경우
        즉, 2번째 코인의 가치인 2만큼 뺀 coin_count[2]만 알면 1,2 동전을 이용한 coin_count[4]를 구할 수 있게되고
        기존에 저장되어 있던 coin_count[4](1111) 와 더해 주면 되는 것이다.
3. 이렇게 1~n번째 동전까지 계산한다.
4. coin_count[0]이 1인 이유 :계산하려는 값 - 동전 가치 = 0 일 경우 경우의 수는 1가지 이므로

*/

int main() {

  int N, k, coin_price[101], coin_count[10001]={1, };
  cin >> N >> k;

  for (int i = 1; i <= N; i++) {
    cin >> coin_price[i];
  }

  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= k; j++) {
      if (j - coin_price[i] >= 0) {
        coin_count[j] += coin_count[j-coin_price[i]];
      }
    }
  }

  cout << coin_count[k];

  return 0;
}
