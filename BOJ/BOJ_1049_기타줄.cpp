#include <iostream>
#include <algorithm>
using namespace std;
//https://www.acmicpc.net/problem/1049

/*
<기타줄>
주요: 패키지와 낱개의 가격 비교는 별개임을 이용한다.
1. 패키지 가격과 낱개 가격의 배열을 따로 저장한다.
2. 각각 오름차순으로 배열한다. -> 각 배열의 인덱스가 0인 값들만 이용한다.
3. 패키지 1팩이 낱개 6개보다 더 비싸면 낱개로 모두 구매하는 것이 더 싸다.
4-1. 패키지 1팩이 낱개 6개보다 더 싸면 6개이하가 될 때까지 패키지 단위로 계속 구매한다.
4-2. 6개 이하가 되면 남은 기타줄을 패키지로 사는게 싼지 낱개로 사는게 싼지 비교한다.
5. 계산된 결과값을 출력한다.

*/


int main() {

  int N, M, package[51], individual[51], res = 0;

  cin >> N >> M;

  // 1번
  for (int i = 0; i < M; i++) {
    cin >> package[i] >> individual[i];
  }

  // 2번
  sort(package, package + M);
  sort(individual, individual + M);

  // 3,4번
  if (package[0] > 6 * individual[0]) {
    res += N * individual[0];
  }
  else{
    while(N > 6){
      N -= 6;
      res += package[0];
    }
    res += min(package[0], N * individual[0]);
  }

  // 5번
  cout << res;

  return 0;
}
