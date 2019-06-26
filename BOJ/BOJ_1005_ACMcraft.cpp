#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// https://www.acmicpc.net/problem/1005

/*
<ACM Craft>
주요: dp
1. 각종 입력값들을 모두 입력받아 저장한다.
2. dp를 이용해 타겟 건물까지 지어지는데 걸리는 최소시간을 계산한다.
  -> 지어지는데 필요한 건물들의 건설시간 중 최댓값이 타겟건물까지 지어지기전 건설시간의 최솟값이다.
  -> dp를 이용해 계산한다.
3. 계산된 dp[w] 값에 타겟건물이 지어지는 시간까지 더해 출력한다.


*/
int T, N, K, D, X, Y, W;

vector<int> dp; // 타겟 건물까지 지어지는데 걸리는 최소시간을 저장
vector<int> building;
vector<vector<int> > order;

// 2번
int cal(int num){

  int temp = 0;

  if(dp[num]){
    return dp[num];
  }
  else{
    for (int i = 1; i <= N; i++) {
      if(order[i][num] == 1){
        temp = max(temp, cal(i)+building[i-1]);
        order[i][num] = 0;
      }
    }
    return dp[num] += temp;
  }
}

int main() {

  cin >> T;
  for (int testcase = 0; testcase < T; testcase++) {

    cin >> N >> K;
    dp.assign(N+1, 0);
    building.clear();
    order.assign(N+1, vector<int>(N+1, 0));

    for (int time = 0; time < N; time++) {
      cin >> D;
      building.push_back(D);
    }
    for (int rule = 0; rule < K; rule++) {
      cin >> X >> Y;
      order[X][Y] = 1;
    }

    // 3번
    cin >> W;
    cal(W);
    cout << dp[W] + building[W-1] << endl;

  }

  return 0;
}
