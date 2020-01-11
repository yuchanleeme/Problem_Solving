#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
//https://www.acmicpc.net/problem/1920

/*
<수 찾기>
주요: binary serch
1. 이분 탐색 STL을 이용해 문제를 푼다.
2. 값들을 입력 받고 정렬을 한다.
3. 정렬된 벡터를 binary_search STL을 이용해 찾고 그 결과를 출력한다.

===========
* 정렬 문제는 cin, cout을 자제해야 하는 것 같다.(입력, 출력 값이 많다.)
  => 같은 코드 scanf, printf는 AC 받음

*/

int main() {

  int N;
  scanf("%d", &N);
  vector<int> seq;

  for (int i = 0; i < N; i++) {
    int input;
    scanf("%d", &input);
    seq.push_back(input);
  }
  sort(seq.begin(), seq.end());

  int M;
  cin >> M;

  for (int i = 0; i < M; i++) {
    int input;
    scanf("%d", &input);
    printf("%d\n",binary_search(seq.begin(), seq.end(), input));
  }

  return 0;
}
