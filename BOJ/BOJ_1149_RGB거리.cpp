#include <iostream>
#include <algorithm>
using namespace std;
//https://www.acmicpc.net/problem/1149

/*
<RGB거리>
주요: DP를 활용한다.
1. 임의의 N번째 집에 페인트 질을 한다고 하자.
2. 만약에 이 집에 R을 칠한다고 하면 무조건 이전 집에는 G 또는 B를 칠해야 한다.
3. 따라서 정리하면 이 집에 R을 칠할 때 누적비용을 cost_R[N] 이라고 한다면
  => cost_R[N] = (cost_B[N-1],cost_G[N-1]) 의 최솟값 + R[N] 이 되는 것이다.
4. 마찬가지로 cost_B[N], cost_G[N]을 구한다.
5. 그 다음 cost_R[N], cost_B[N], cost_G[N]을 구한 뒤 셋 중 최솟값을 구해 출력하면 된다.

*/

int main() {

  int N, R[1001], G[1001], B[1001];
  int cost_R[1001], cost_G[1001], cost_B[1001];
  int cost_res;
  cin >> N;

  for (int i = 1; i <= N; i++) {
    cin >> R[i] >> G[i] >> B[i];
  }

  // 3,4 번
  for (int i = 1; i <= N; i++) {
    cost_R[i] = min(cost_B[i-1],cost_G[i-1]) + R[i];
    cost_G[i] = min(cost_R[i-1],cost_B[i-1]) + G[i];
    cost_B[i] = min(cost_R[i-1],cost_G[i-1]) + B[i];
  }

  // 5번
  cost_res = min(cost_R[N],cost_G[N]);
  cost_res = min(cost_res,cost_B[N]);
  cout << cost_res;

  return 0;
}
