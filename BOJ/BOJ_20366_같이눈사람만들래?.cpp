#include <bits/stdc++.h>
using namespace std;
// https://acmicpc.net/problem/20366

/*
<같이 눈사람 만들래?>
주요: 투포인터
1. a,b // x, y 이런식으로 조합을 나눠서 눈사람을 만든다.
2. a ... x .. y .. b 이런식으로 조합을 만들어서 죄다 조사한다.
3. 조합을 하나씩 계산해보면서 res값을 비교한다.
4. 최대한 0에 근접하게 계산하기 위해 x,y idx를 지정한다.
5. 두 크기의 차이의 최솟값을 계속 구해서 출력한다.
==========
* a,b 를 놓고 그 사이의 x,y 조합을 만드는게 문제의 핵심이다.

*/

int ans = 2 * (1e9 - 1) + 1;  // 최대값
vector<int> snow;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        int temp;
        cin >> temp;
        snow.push_back(temp);
    }

    sort(snow.begin(), snow.end());

    for (int a = 0; a < N - 3; a++) {
        for (int b = a + 3; b < N; b++) {
            // a,b가 한 조합

            // x, y가 한 조합
            int x = a + 1;
            int y = b - 1;
            // 조합을 하나씩 계산해본다.
            while (x < y) {
                int Elsa = snow[a] + snow[b];  // Elsa 고정
                int Anna = snow[x] + snow[y];  // Anna는 변동

                // 포인트는 이 res값이 0에 최대한 가깝게 계산해서 비교해야한다는 점이다.
                // 따라서, res값이 양수 -> Anna의 x idx가 +1
                //       res값이 음수 -> Anna의 y idx가 -1
                int res = Elsa - Anna;
                ans = min(ans, abs(res));  // 결과 저장

                if (res > 0) {
                    x++;
                } else {
                    y--;
                }
            }
        }
    }
    cout << ans;

    return 0;
}
