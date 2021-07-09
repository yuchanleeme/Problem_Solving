#include <bits/stdc++.h>
using namespace std;
//https://acmicpc.net/problem/1644

/*
<소수의 연속합>
주요: 수학, 투 포인터
1. 우선 범위 내 소수를 모두 구해 배열을 만든다.
2. 소수 배열을 투포인터로 탐색하여 연속합의 개수를 찾는다.
3. 그 결과를 출력한다.
=============
* 소수의 연속합은 증가함수이므로 이분탐색도 가능하다.

*/

int N, cnt;
int chk[4040404];
vector<int> prime;
int main() {
    cin >> N;
    long long sum = 0;
    for (int i = 2; i <= 4000010; i++) {
        if (chk[i] == true) continue;
        prime.push_back(i);
        for (int j = i * 2; j <= 4000010; j += i) {
            if (chk[j] == true) continue;
            chk[j] = true;
        }
    }

    int st = 0, ed = 0, res = prime[0];
    while (true) {
        if (prime[ed] > N) break;
        if (res == N) cnt++;

        if (res >= N) {
            res -= prime[st];
            st++;
        } else {
            ed++;
            if (ed == prime.size()) break;
            res += prime[ed];
        }
    }
    cout << cnt;
    return 0;
}