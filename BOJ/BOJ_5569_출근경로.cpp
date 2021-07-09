#include <bits/stdc++.h>
using namespace std;
//https://acmicpc.net/problem/5569

/*
<출근 경로>
주요: DP
1. 꺾어서 오는 경로인지, 직진해서 오는 경로인지 구분해서 점화식을 세운다.
2. 꺾어서 오기 위해서는 직전에 직진한 경로만 가능하다.
3. 이를 유의해서, DP식을 세우고 결과를 출력한다.
============
* dp 계산 중에 mod 연산을 빼먹지 말자.

*/

int w, h;
int dp[110][110][2][2];
// 1 1 -> 대각선 아래(w,h)로 이동한다는 생각
// 0 0 : 북쪽에서 왔는데 직진한애
// 0 1 : 북쪽에서 왔는데 꺾어서 온 애
// 1 0 : 서쪽에서 왔는데 직진한애
// 1 1 : 서쪽에서 왔는데 꺾어서 온 애

int main() {
    cin >> w >> h;

    for (int i = 2; i <= h; i++) {
        dp[i][1][0][0] = 1;
    }
    for (int j = 2; j <= w; j++) {
        dp[1][j][1][0] = 1;
    }

    int mod = 100000;
    for (int i = 2; i <= h; i++) {
        for (int j = 2; j <= w; j++) {
            dp[i][j][0][0] = (dp[i - 1][j][0][0] + dp[i - 1][j][0][1]) % mod;
            dp[i][j][0][1] = dp[i - 1][j][1][0];

            dp[i][j][1][0] = (dp[i][j - 1][1][0] + dp[i][j - 1][1][1]) % mod;
            dp[i][j][1][1] = dp[i][j - 1][0][0];
        }
    }

    int ans = 0;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            ans += dp[h][w][i][j];
            ans %= mod;
        }
    }
    cout << ans;

    return 0;
}