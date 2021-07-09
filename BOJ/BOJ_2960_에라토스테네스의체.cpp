#include <bits/stdc++.h>
using namespace std;
//https://acmicpc.net/problem/2960

/*
<에라토스테네스의 체>
주요: 수학
1. 에라토스테네스의 체를 구현한다.
2. 지울 때마다 cnt를 더해서 몇번째인지 확인한다.
3. 결과를 출력한다.

*/

int N, K, cnt;
int chk[1010];

int main() {
    cin >> N >> K;

    for (int i = 2; i <= N; i++) {
        if (chk[i] == true) continue;
        cnt++;
        if (cnt == K) return !printf("%d", i);
        for (int j = i * 2; j <= N; j += i) {
            if (chk[j] == true) continue;
            chk[j] = true;
            cnt++;
            if (cnt == K) return !printf("%d", j);
        }
    }

    return 0;
}