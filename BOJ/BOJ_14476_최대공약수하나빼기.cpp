#include <bits/stdc++.h>
using namespace std;
//https://acmicpc.net/problem/14476

/*
<최대 공약수 하나 빼기>
주요: 유클리드 호제법 
1. leftgcd[X] = 1 ~> X-1까지의 누적 최대공약수
2. leftgcd[X] = X+1 <~ N까지의 누적 최대공약수
3. 이제 X를 처음부터 조사해서 leftgcd[X-1], rightgcd[X+1]의 최대공약수를 찾는다.
4. 조건에 만족한 값 중 가장 큰 값을 출력한다.
===========
* 여기서 아이디어는 최대공약수들의 최대공약수는 전체 최대공약수라는 점이다.

*/

int N;
int arr[1010101];
int leftgcd[1010101];
int rightgcd[1010101];

int gcd(int a, int b) {
    if (b == 0) return a;
    else
        return gcd(b, a % b);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    leftgcd[0] = arr[0];
    rightgcd[N - 1] = arr[N - 1];

    // leftgcd
    for (int i = 1; i < N; i++) {
        leftgcd[i] = gcd(leftgcd[i - 1], arr[i]);
    }

    // rightgcd
    for (int i = N - 2; i >= 0; i--) {
        rightgcd[i] = gcd(arr[i], rightgcd[i + 1]);
    }

    pair<int, int> ans = make_pair(-1, -1);
    for (int i = 0; i < N; i++) {
        int num = 0;
        if (i == 0) {
            num = rightgcd[i + 1];
        } else if (i == N - 1) {
            num = leftgcd[i - 1];
        } else {
            num = gcd(min(leftgcd[i - 1], rightgcd[i + 1]), max(leftgcd[i - 1], rightgcd[i + 1]));
        }
        if (arr[i] % num != 0) {
            if (ans.first < num) {
                ans.first = num;
                ans.second = arr[i];
            }
        }
    }

    if (ans.first == -1) cout << ans.first;
    else
        cout << ans.first << " " << ans.second;

    return 0;
}