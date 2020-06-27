#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
//https://www.acmicpc.net/problem/7806

/*
<GCD!>
주요: 수학
1. 우선 팩토리얼은 값이 너무 크므로 K를 먼저 소인수분해한 후 그 결과를 seq 벡터에 넣는다.
2. seq 벡터에 있는 값을 기준으로 1~N에서 얼마나 등장했는지 세본다.
  => ex) 2^4을 가지고 있다면 1~N 에서 2,4,8,16의 배수들의 등장횟수 카운팅
3. 각 카운딩 된 결과를 결과값 res에 곱해준다.
4. 입력이 끝날 때까지 진행한다.
==========
* 큰 수부터 나머지 비교하면서 곱해주는 방법은 시간초과
* 소수 구하는 알고리즘을 최대한 최적화를 한다.
* for문 에서 범위 지정을 정확히 해준다.(j <= N 부분)
*/

vector<pair<int, int> > seq; // 소인수, 지수

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  long long N, K;
  while(true){
    cin >> N >> K;
    if(cin.eof()) break;
    seq.clear();

    // K를 소인수 분해하여 seq 벡터에 넣는다.
    for (int i = 2; i*i <= K; i++) {
      int factor = i;
      if(K%i == 0)
        seq.push_back({factor, 0});
      while(K % i == 0){
        seq[seq.size()-1].second++;
        K/= i;
      }
      if(K < i) break;
    }
    seq.push_back({K,1}); // 마지막으로 남은 수는 무조건 지수가 1인 소수이다.

    // 각 숫자가 몇번 등장하는지 센다.
    long long res = 1;
    for (int i = 0; i < seq.size(); i++) {
      long long sum_val = 0;
      long long factor = seq[i].first;
      for (long long j = factor; j <= N; j*= factor) {
        long long temp = N/j;
        if((sum_val + temp) >= seq[i].second){
          sum_val = seq[i].second;
          break;
        }
        else sum_val += temp;
      }
      res *= pow(factor, sum_val);
    }
    cout << res << "\n";
  }

  return 0;
}
