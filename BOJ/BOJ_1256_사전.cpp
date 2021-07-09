#include <bits/stdc++.h>
using namespace std;
//https://acmicpc.net/problem/1256

/*
<사전>
주요: DP
1. int func(int X, int Y)
    => a가 X개, z가 Y개일 때 만들 수 있는 경우의 수 리턴
    => 단, 10억까지만 조사할 것이므로 10억 이상인 값은 최대값으로 취급한다.
2. 이제 Acnt와 Zcnt를 기준으로 하나씩 깎아가면서 개수를 조사한다.
3. a, z를 하나씩 붙여보면서 유효한 개수가 남아있는지 확인하며 값을 계산한다.
4. 최종결과를 출력한다.
============
* K개 이하면 -1을 리턴해야 한다.

*/

long long N, M, K;
long long dp[110][110];

// a가 a개, z가 z개일 때 만들 수 있는 경우의 수 리턴
int func(int a, int z) {
    if (a == 0 || z == 0) {
        return 1;
    }
    if (dp[a][z]) return dp[a][z];
    else {
        long long temp = func(a - 1, z) + func(a, z - 1);
        if (temp > 1e9 + 10) return dp[a][z] = 1e9 + 10;
        else
            return dp[a][z] = temp;
    }
}

int main() {
    cin >> N >> M >> K;

    if (func(N, M) < K) {
        cout << -1;
        return 0;
    }

    int Acnt = N, Zcnt = M;
    string ans = "";
    for (int i = 0; i < N + M; i++) {
        if (Acnt > 0) {
            int temp = func(Acnt - 1, Zcnt);
            if (temp < K) {
                // temp가 K보다 적으면 이 위치는 a가 아니라 z가 와야함
                ans += "z";
                K -= temp;
                Zcnt--;
            } else {
                // 그게 아니라면, a가 온다.
                ans += "a";
                Acnt--;
            }
        } else {
            ans += "z";
        }
    }
    cout << ans;

    return 0;
}