#include <bits/stdc++.h>
using namespace std;
//https://acmicpc.net/problem/3020

/*
<개똥벌레>
주요: 누적 합
1. 석순과 종유석의 위치에 따라 누적합을 구한다. 
2. 이 누적합을 기준으로 조건에 따라 결과를 구해 출력한다.

*/

int N, H;
int cave[505050];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> N >> H;
    for (int i = 0; i < N; i += 2) {
        int d, u;
        cin >> d >> u;
        cave[1]++;
        cave[d + 1]--;
        cave[H - u + 1]++;
    }

    int res = 0, ans = -1, cnt = 0;
    for (int i = 1; i <= H; i++) {
        res += cave[i];
        if (ans == -1 || res < ans) {
            ans = res;
            cnt = 1;
        } else if (res == ans) {
            cnt++;
        }
    }
    cout << ans << " " << cnt;
    return 0;
}