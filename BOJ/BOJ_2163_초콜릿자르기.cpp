#include <iostream>
using namespace std;
//https://www.acmicpc.net/problem/2163

/*
<초콜릿 자르기>
주요: 단순하게 생각한다.
1. N x M 초콜릿을 M x 1 크기(N개)로 자른다. -> 자른 횟수 : N-1
2. 잘려진 모든 M x 1 초콜릿 N개를 1 X 1 크기로 자른다 -> 자른 횟수: N(M-1)
3. 총 자른 횟수 : N-1 + N(M-1) = N x M - 1
4. 자른 개수를 출력한다.

*/

int main() {

  int N, M;

  cin >> N >> M;

  cout << N * M - 1;

  return 0;
}
