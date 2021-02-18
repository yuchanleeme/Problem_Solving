#include <bits/stdc++.h>
using namespace std;
// https://www.acmicpc.net/problem/7795

/*
<먹을 것인가 먹힐 것인가>
주요: 정렬, 이분탐색
1. A와 B를 입력 받고 정렬한다.
2. 이제 lower_bound를 통해 해당 두 벡터 원소들의 대소관계를 비교한다.
3. 그 결과를 출력한다.

*/

int T;
int main(int argc, char const *argv[]) {
  cin >> T;

  while (T--) {
    int N, M, ans = 0;
    cin >> N >> M;
    vector<int> A, B;
    for (int i = 0; i < N; i++)  {
      int temp; cin >> temp;
      A.push_back(temp);
    }
    for (int i = 0; i < M; i++)  {
      int temp; cin >> temp;
      B.push_back(temp);
    }

    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    for (int i = 0; i < A.size(); i++) {
      ans += lower_bound(B.begin(), B.end(), A[i])-B.begin();
    }
    cout << ans << "\n";
  }
  return 0;
}
