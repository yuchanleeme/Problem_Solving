#include <iostream>
using namespace std;
//https://www.acmicpc.net/problem/11047

/*
<동전 0 >
주요: 그리디 알고리즘 이용
1. 가장 큰 가치의 동전만큼 K에서 뺴주고 뻬준만큼 coin값을 더해준다.
2. 가장 큰 가치의 동전으로 K값을 빼줄 수 없다면 그 다음 가치의 동전을 이용한다.
3. K값이 0 이 될때까지 계산해준다.
=======
* DP가 아닌 그리디를 쓴 이유
 => 제시된 문제 조건에 의해 매 순간의 최적해가 문제에 대한 최적해이기 때문이다.
    (A1 = 1, i ≥ 2인 경우에 Ai는 Ai-1의 배수)

*/

int main() {

  int N, K, idx, coin = 0;
  int a[11];

  cin >> N >> K;

  for (int i = 0; i < N; i++) {
    cin >> a[i];
  }

  idx = N - 1; // 가장 큰 가치의 동전 위치

  while (K != 0) {
    if (a[idx] <= K) {
      K -= a[idx];
      coin++;
    }
    else{
      idx--;
    }
  }

  cout << coin;

  return 0;
}
