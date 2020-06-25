#include <iostream>
using namespace std;
//https://www.acmicpc.net/problem/2004

/*
<조합 0의 개수>
주요: 2,5의 개수, 전체 관점에서 수 세기, 거듭 제곱
1. nCm 은 n!/ m!(n-m)! 이다.
2. 이를 기반으로 구하되, 팩토리얼 계산할 때 일일이 하지 않고 전체 관점에서 수를 센다.
  => 등장횟수를 세는 방법이다.
  => 예를들어, 1~100에서 5를 찾는다면 100/5 = 20개이고 25를 찾는다면 100/25 = 4개이다.
     즉, 25, 50, 75, 100은 중복 등장한다는 소리다. 이 횟수를 세면 된다.
==========
* 2,5 를 각각 찾아서 숫자를 비교하면 시간초과가 발생한다. (거듭제곱을 이용하지 않고)

*/

int main() {

  long long N, M;
  cin >> N >> M;
  long long num_2_N = 0, num_5_N = 0, num_2_M = 0, num_5_M = 0;
  long long num_2_NM = 0, num_5_NM = 0;

  // N!
  for (long long i = 2; i <= N; i*=2)
    num_2_N += N/i;
  for (long long i = 5; i <= N; i*=5)
    num_5_N += N/i;

  // M!
  for (long long i = 2; i <= M; i*=2)
    num_2_M += M/i;
  for (long long i = 5; i <= M; i*=5)
    num_5_M += M/i;

  // N-M!
  for (long long i = 2; i <= N-M; i*=2)
    num_2_NM += (N-M)/i;
  for (long long i = 5; i <= N-M; i*=5)
    num_5_NM += (N-M)/i;

  // 분자에 모이는 2,5의 개수
  long long val_2 = num_2_N - (num_2_M + num_2_NM);
  long long val_5 = num_5_N - (num_5_M + num_5_NM);

  // 그 중 최소
  cout << min(val_2,val_5);

  return 0;
}
