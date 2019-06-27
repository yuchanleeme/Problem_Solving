#include <iostream>
#include <vector>
using namespace std;
//https://www.acmicpc.net/problem/2775

/*
<부녀회장이 될테야 >
주요: 규칙에 맞게 계산한다.
1. 단순하게 아래층의 자신과 같은 호수 까지 사람들을 다 더해주면 된다.
2. 일일이 다 더하면 효율이 안 좋으니 미리 저장해둔 값을 이용한다.
  => 우리층 바로전 호수 사람이 데려와야하는 사람수 + 내 바로 밑층 호수 사람수
  => ex) apart[4][5] = aprt[4][4] + aprt[3][5]

*/

int main() {

  int T, k, n;
  vector<vector<int> > apart(15, vector<int>(15,0));

  cin >> T;
  for (int testcase = 0; testcase < T; testcase++) {

    cin >> k >> n;

    for (int i = 0; i <= k; i++) {
      for (int j = 1; j <= n; j++) {
        if(i == 0){
          apart[i][j] = j;
        }
        else{
          apart[i][j] = apart[i][j-1] + apart[i-1][j];
        }
      }
    }
    cout << apart[k][n] << endl;

  }
  return 0;
}
