#include <iostream>
using namespace std;
//https://www.acmicpc.net/problem/2294

/*
<동전 2>
주요: DP를 활용한다.
1. coin_count 배열은 현재 위치의 동전까지로만 만들수 있는 idx의 최솟값을 의미한다.
2. 동전 1(2293번)과 비슷하게 1번째 동전만을 이용해 만들 수 있는 1~k 값까지 최솟값을 구한다.
  2-1 coin_count[j] 와 coin_count[j-coin_price[i]] + 1 를 비교해 준다.
    => coin_count[j] : 현재 진행중인 동전 이전 동전까지만 이용했을 때의 최솟값
    => coin_count[j-coin_price[i]] + 1 : 현재 진행중인 동전을 이용했을때 그 때의 최솟값
  2-2 둘 중 최솟값을 골라 최종 coin_count[j]에 저장한다.
3. coin_count[k] 가 10001이면 불가능이므로 -1을 리턴하고 아니면 coin_count[k]를 리턴한다.

*/

int min(int a, int b){

  if(a > b){
    return b;
  }
  else{
    return a;
  }
}

int main() {

  int N, k, coin_price[101];
  int coin_count[10001] = {0, };

  cin >> N >> k;

  for (int i = 1; i <= N; i++) {
    cin >> coin_price[i];
  }

  // 최솟값을 구하는 문제이므로 나머지 값들 큰 값인 10001로 초기화
  for (int i = 1; i <= k; i++) {
    coin_count[i] = 10001;
  }

  // 2번
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= k; j++) {
      if (j - coin_price[i] >= 0) {
        coin_count[j] = min(coin_count[j], coin_count[j-coin_price[i]] + 1);
      }
    }
  }

  // 3번
  if (coin_count[k] == 10001) {
    cout << "-1" << endl;
  }
  else{
    cout << coin_count[k];
  }

  return 0;
}
