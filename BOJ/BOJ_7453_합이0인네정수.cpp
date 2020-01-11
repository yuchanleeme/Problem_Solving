#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
//https://www.acmicpc.net/problem/7453

/*
<합이 0인 네 정수>
주요: binary serch, lower_bound, upper_bound
1. A[],B[]의 합 조합 배열, C[],D[]의 합 조합 배열 이렇게 크게 2개로 나눈다.
  1-1) A,B,C,D 에서 모두 골라야하고
  1-2) 어차피 순서쌍 개수만 중요하기 때문에 크게 두개로 나누어도 된다.
2. 이분탐색을 하기 위해 seq[1]만 정렬한다.
3. 이제 이분탐색으로 두 배열의 합이 0인 순서쌍의 개수를 센다.
  3-1) lower_bound만 사용하면 중복으로 나오는 값을 셀 수 없으므로 upper_bound도 같이 이용한다.
  3-2) 개 수는 up_idx - low_idx
4. 구한 순서쌍 개수를 출력한다.

===========
* 중복값이 나올 수 있다는 것 유의해야 한다.
* 시간 초과 : 4중 for문은 당연히 시간초과
* 메모리 초과
  => 2^28은 int 범위 내이다, 생각보다 큰 값인줄 알았다.
  => 결과값 ans는 대략 크게 잡으면 4000^4이기 때문에 long long으로 해줬다.

*/

int main() {

  int N;
  cin >> N;

  vector<int> ex[4];
  for (int i = 0; i < N; i++) {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    ex[0].push_back(a);
    ex[1].push_back(b);
    ex[2].push_back(c);
    ex[3].push_back(d);
  }

  // 1번
  vector<int> seq[2];
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      seq[0].push_back(ex[0][i] + ex[1][j]);
    }
  }
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      seq[1].push_back(ex[2][i] + ex[3][j]);
    }
  }

  // 2번
  sort(seq[1].begin(), seq[1].end());

  // 3번
  long long ans = 0;
  for (int i = 0; i < seq[0].size(); i++) {
    auto val_low = lower_bound(seq[1].begin(), seq[1].end(), -seq[0][i]);
    auto val_up = upper_bound(seq[1].begin(), seq[1].end(), -seq[0][i]);
    int idx_low = val_low - seq[1].begin();
    int idx_up = val_up - seq[1].begin();
    if(0 <= idx_low && idx_low < seq[1].size()){
      if(seq[0][i]+seq[1][idx_low] == 0){
        ans += idx_up-idx_low;
      }
    }
  }

  // 4번
  cout << ans;

  return 0;
}
