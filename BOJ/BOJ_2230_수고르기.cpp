#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
//https://www.acmicpc.net/problem/2230

/*
<수 고르기>
주요: lower_bound
1. 값을 입력 받아 정렬한다.
2. lower_bound를 이용해 seq[i] + M 값이 처음 나오는 idx를 찾는다.
3. 찾은 두 값의 차이가 가장 작은 값을 출력한다.

===========
* 문제 조건을 잘봐야 한다.
  => M은 0이 될 수 있고, 두 수는 중복될수도 있다.
  => idx의 범위는 자기 자신부터 N-1까지

*/

const long long INF = 2100000000;

int main() {

  long long N, M;
  cin >> N >> M;

  vector<long long> seq;

  for (int i = 0; i < N; i++) {
    long long input;
    cin >> input;
    seq.push_back(input);
  }

  sort(seq.begin(), seq.end());

  long long ans = INF;
  for (int i = 0; i < N; i++) {
    vector<long long>:: iterator val = lower_bound(seq.begin(), seq.end(),seq[i]+M);
    int idx = val - seq.begin();
    if(idx >= i && idx < N){
      ans = min(ans, seq[idx]-seq[i]);
    }
  }
  cout << ans;

  return 0;
}
