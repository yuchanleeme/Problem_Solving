#include <iostream>
using namespace std;
//https://algospot.com/judge/problem/read/FESTIVAL

/*
<록 페스티벌>
주요: 구현
1. 가능한 경우를 모두 찾은 뒤 평균값 중 최솟값을 찾는다.
2. 최소로 가능한 경우에서 하나씩 값을 더해 평균을 비교한다.

*/

int C, N, L;
const double INF = 1100.0;
int day[1010];
int main(int argc, char const *argv[]) {

  cin >> C;
  for (int testcase = 0; testcase < C; testcase++) {
    cin >> N >> L;
    for (int i = 1; i <= N; i++) {
      cin >> day[i];
    }

    double res = 0, ans = INF;
    for (int i = 1; i <= N-L+1; i++) {
      res = 0;
      // 최소 개수 만큼 연속한 값
      for (int j = i; j < i+L; j++) {
        res += day[j];
      }
      ans = min(ans, res/L);

      // 하나씩 더해서 최솟값
      int idx = 0;
      for (int k = i+L; k <= N; k++) {
        idx++;
        res += day[k];
        ans = min(ans, res/(L+idx));
      }
    }

    // 소수점 11자리까지 출력
    cout << fixed;
    cout.precision(11);
    cout << ans << "\n";
  }

  return 0;
}
