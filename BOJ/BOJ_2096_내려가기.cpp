#include <iostream>
#include <vector>
using namespace std;
//https://www.acmicpc.net/problem/2096

/*
<내려가기>
주요: DP, 토글링
1. dp_max, dp_min배열을 만든다. (dp[][x] = 각각 x번째 칸에 도달했을때 최대,최소값 )
  => 메모리 크기를 줄이기 위해 토글링을 이용한다.
2. 이전 칸에서 올 수 있는 값들 중 최대,최소값을 구한 뒤 해당 칸의 nums값을 더해준다.
3. 최종적으로 계산된 dp 배열에서 최대, 최소값을 찾아 출력한다.

===========
* nums[100001][3]가 아닌 nums[3]으로 배열 크기를 줄여도 된다.
  => 입력 받을때마다 dp 갱신
* abs를 이용해서 코드 최적화도 가능하다.

*/

int dp_max[2][3];
int dp_min[2][3];
int nums[100001][3];
const int INF = 1e7;

int main() {

  int N;
  cin >> N;
  for (int i = 1; i <= N; i++) {
    cin >> nums[i][0] >> nums[i][1] >> nums[i][2];
  }

  for (int i = 1; i <= N; i++) {
      dp_max[i%2][0] = max(dp_max[(i-1)%2][0], dp_max[(i-1)%2][1]) + nums[i][0];
      dp_min[i%2][0] = min(dp_min[(i-1)%2][0], dp_min[(i-1)%2][1]) + nums[i][0];

      int temp_A = max(dp_max[(i-1)%2][0], dp_max[(i-1)%2][1]);
      dp_max[i%2][1] =  max(temp_A, dp_max[(i-1)%2][2])+ nums[i][1];
      int temp_B = min(dp_min[(i-1)%2][0], dp_min[(i-1)%2][1]);
      dp_min[i%2][1] =  min(temp_B, dp_min[(i-1)%2][2])+ nums[i][1];

      dp_max[i%2][2] = max(dp_max[(i-1)%2][2], dp_max[(i-1)%2][1]) + nums[i][2];
      dp_min[i%2][2] = min(dp_min[(i-1)%2][2], dp_min[(i-1)%2][1]) + nums[i][2];
  }

  int minV = INF, maxV = -1;
  for (int i = 0; i < 3; i++) {
    minV = min(minV, dp_min[N%2][i]);
    maxV = max(maxV, dp_max[N%2][i]);
  }

  cout << maxV << " " << minV;

  return 0;
}
