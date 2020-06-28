#include <iostream>
#include <vector>
using namespace std;
//https://www.acmicpc.net/problem/17391

/*
<무한부스터>
주요: DP
1. 모든 NxM맵을 돌면서 부스터 횟수를 갱신한다.
2. 최솟값을 위해 오른쪽, 아래로만 움직여야 한다.
3. dp[i][j]는 (1,1)에서 현 위치(i,j)까지 이동할 때의 촤소 이동 횟수이다.
  => 각 map의 최대 부스터 개수만큼 한 칸 씩 이동해서 최소값을 갱신한다.
  => 최종 dp[N][M] 은 (1,1)에서 (N,M) 까지의 최솟값이 형성된다.

*/

const int INF = 350;
vector<vector<int> > map;
vector<vector<int> > dp;

int main() {

  int N, M;
  cin >> N >> M;
  map = vector<vector<int> > (N+1, vector<int>(M+1, 0));
  dp = vector<vector<int> > (N+1, vector<int>(M+1, INF));

  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= M; j++) {
      int input;
      cin >> input;
      map[i][j] = input;
    }
  }

  dp[1][1] = 0;
  // 전체 탐색을 진행한다.
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= M; j++) {

      int r_idx = 0;
      int d_idx = 0;

      // 최대 부스터 개수 만큼 한칸씩 이동해서 값 갱신시키는 과정
      // 오른쪽 이동
      while (r_idx != map[i][j]) {
        r_idx++;  // 부스터 한개쓴다고 생각하면 됨
        if(j+r_idx > M){ break;}  // 범위 초과 시 break
        dp[i][j+r_idx] = min(dp[i][j+r_idx], dp[i][j]+1); // 기존 값과 갱신값 비교
      }
      // 아래로 이동
      while (d_idx != map[i][j]) {
        d_idx++;  // 부스터 한개쓴다고 생각하면 됨
        if(i+d_idx > N){ break;} // 범위 초과 시 break
        dp[i+d_idx][j] = min(dp[i+d_idx][j], dp[i][j]+1); // 기존 값과 갱신값 비교
      }
    }
  }

  cout << dp[N][M];

  return 0;
}
