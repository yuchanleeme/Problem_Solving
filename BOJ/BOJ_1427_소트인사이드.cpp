#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
//https://www.acmicpc.net/problem/1427

/*
<소트인사이드>
주요: 정렬
1. 수를 입력받아 자리수로 나눈다.
2. 나눈 자리수로 seq에 하나씩 넣는다.
3. sort함수로 정렬 후 내림차순 정렬이므로 seq idx 뒤에서부터 출력한다.

*/

int main() {

  int N;
  cin >> N;

  vector<int> seq;
  while (N != 0) {
    seq.push_back(N % 10);
    N/=10;
  }

  sort(seq.begin(),seq.end());

  for (int i = seq.size()-1; i >= 0; i--) {
    cout << seq[i];
  }

  return 0;
}
