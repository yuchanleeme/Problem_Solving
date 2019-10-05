#include <iostream>
#include <queue>
using namespace std;
//https://www.acmicpc.net/problem/1495

/*
<기타리스트>
주요: DP, 브루트포스
1. 단순하게 다 조사하면 된다.
2. 이전 볼륨이 y 값이고 x번째때 볼륨을 조절할 수 있으면
  => ex) dp[x][y +- music[x]] = true 처리한다.
  => y +- music[x] 가 조절 가능한 값
3. N번 곡 까지 범위에 맞게 조사한다.
4. 모든 조사가 끝났으면 N번째의 true인 값을 찾아서 출력한다.

==========
* dp[i][0]최대, dp[i][1] 최소로 놓고 하는 알고리즘은 잘못된 풀이
  => M 범위를 초과하면 값이 다른방향으로 연산된다.
* 큐로 하나씩 삽입하면서 비교하니까 메모리 초과가 떴다.

*/

int N, S, M, music[101];
bool dp[101][1001];

int cal(){

  int res, idx = 0;

  dp[0][S] = true;

  // 2,3번
  for (int i = 1; i <= N; i++) {
    for (int j = 0; j < 1001; j++) {
      if(dp[i-1][j] == true){
        if(j + music[i] <= M){ dp[i][j+music[i]] = true;}
        if(j - music[i] >= 0){ dp[i][j-music[i]] = true;}
      }
    }
  }

  // 4번 - 하나도 true 가 없다면 그대로 -1 리턴하게 한다.
  res = -1;
  for (int i = 0; i < 1001; i++) {
    if(dp[N][i]){ res = max(res,i);}
  }
  return res;
}

int main() {

  cin >> N >> S >> M;
  for (int i = 1; i <= N; i++) {
    cin >> music[i];
  }

  cout << cal();

  return 0;
}
