#include <bits/stdc++.h>
using namespace std;
//https://www.acmicpc.net/problem/10816

/*
<숫자카드 2>
주요: lower_bound
1. 입력받은 값을 일단 정렬한다.
2. 이제 찾을 값들을 lower_bound, upper_bound로 찾는다.
3. 그 차이만큼 출력해준다.
==========
* 입출력 코드 써줘야함 (cin.tie(0) 이런거)

*/

int N, M;
vector<int> seq;
int main(int argc, char const *argv[]) {
  cin.tie(0); ios_base::sync_with_stdio(false);
  cin >> N;
  for (int i = 0; i < N; i++) {
    int temp; cin >> temp;
    seq.push_back(temp);
  }
  sort(seq.begin(), seq.end());

  cin >> M;
  for (int i = 0; i < M; i++) {
    int temp; cin >> temp;
    int lidx = lower_bound(seq.begin(), seq.end(), temp)-seq.begin();
    int uidx = upper_bound(seq.begin(), seq.end(), temp)-seq.begin();
    cout << uidx - lidx << " ";
  }
  return 0;
}
