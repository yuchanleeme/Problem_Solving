#include <bits/stdc++.h>
using namespace std;
//https://acmicpc.net/problem/11049

/*
<행렬 곱셈 순서>
주요: DP
1. DP[x][y] = X부터 Y까지의 행렬들의 곱중 최솟값
2. A[K] = DP[X][K] + DP[K+1][Y] + cal(x,k,y)라 하면,
   DP[X][Y] = min(A[X], A[X+1].... A[Y])이다.
   단, cal(x,k,y) 는 행렬 곱셈 횟수이다.
3. 위 점화식을 풀어 결과를 출력한다.

*/

int N;
long long dp[505][505];
vector<pair<int, int>> arr;

long long cal(int x, int k, int y) {
    return arr[x].first * arr[k].second * arr[y].second;
}

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        int R, C;
        cin >> R >> C;
        arr.push_back({R, C});
    }
    for (int i = 0; i < N; i++) {
        for (int x = 0; i + x < N; x++) {
            int y = i + x;
            if (x != y) dp[x][y] = 1e10;
            for (int k = x; k + 1 <= y; k++) {
                dp[x][y] = min(dp[x][y], dp[x][k] + dp[k + 1][y] + cal(x, k, y));
            }
        }
    }
    cout << dp[0][N - 1];
    return 0;
}