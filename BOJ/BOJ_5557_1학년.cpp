#include <bits/stdc++.h>
using namespace std;
//https://acmicpc.net/problem/5557

/*
<1학년>
주요: DP
1. DP[x][y] = x번째 항까지 계산하였을 때 Y 가되는 경우의 수의 값
  ex) 8 2 3 4 ....
  DP[2][13] = 1, DP[2][7] = 1, DP[2][9] = 1, DP[2][3] = 1 ....
2. 즉 DP[X][이전 숫자 +- 다음 항] += DP[X-1][이전숫자]
3. 결과를 출력한다. 

*/

int N;
vector<int> arr;
long long dp[110][22];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;
    for (int i = 0; i < N; i++) {
        int temp;
        cin >> temp;
        arr.push_back(temp);
    }

    dp[0][arr[0]] = 1;
    for (int i = 1; i < N - 1; i++) {
        for (int j = 0; j <= 20; j++) {
            if (dp[i - 1][j] == 0) continue;
            int nextNum_plus = j + arr[i];
            if (nextNum_plus <= 20) {
                dp[i][nextNum_plus] += dp[i - 1][j];
            }

            int nextNum_minus = j - arr[i];
            if (nextNum_minus >= 0) {
                dp[i][nextNum_minus] += dp[i - 1][j];
            }
        }
    }

    cout << dp[N - 2][arr[N - 1]];
    return 0;
}