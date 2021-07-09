#include <bits/stdc++.h>
using namespace std;
//https://acmicpc.net/problem/2904

/*
<수학은 너무 쉬워>
주요: 소인수 분해, map
1. 먼저, 소수를 모두 찾는다.
2. 모든 입력에 대한 소인수 분해를 진행한다.
3. 단, 이때 모든 입력의 곱에 대한 소인수도 구한다.
4. 그 소인수를 총 입력의 개수를 이용해 최종 최대공약수를 찾는다.
5. 최대공약수에 따라 처음 입력받은 수가 필요한 인수의 개수를 센다.
6. 그렇게 최대공약수와 횟수를 출력한다.
==========
* 소인수 분해를 어떤식으로 저장 시킬지 고민한다.
* A/x , B*x 가 동시에 일어난다는 뜻은 A, B의 인수를 하나씩 옮긴다.
    => 따라서, 필요한 인수를 얻는 다는 것은 "어디선가" 인수를 가져오는 것이나 마찬가지다.

*/

int N;
bool prime[1010101];
vector<int> pri;
map<int, int> mp;
map<int, int> dict[101];

void cal(int num, int n) {
    int idx = 0;
    while (num != 1) {
        int div = pri[idx];
        while (num % div == 0) {
            num /= div;
            mp[pri[idx]]++;       // 전체 소인수
            dict[n][pri[idx]]++;  // 입력받은 숫자의 소인수
        }
        idx++;
    }
}

int main() {
    cin >> N;

    // 소수 계산
    for (int i = 2; i <= 1000000; i++) {
        if (prime[i] == true) continue;
        pri.push_back(i);
        for (int j = i * 2; j <= 1000000; j += i) {
            prime[j] = true;
        }
    }

    // 소인수 분해
    for (int i = 0; i < N; i++) {
        int num;
        cin >> num;
        cal(num, i);
    }

    // 최대 공약수 계산 및 mp초기화
    int gcd = 1;
    for (auto &x : mp) {
        int cnt = x.second / N;
        x.second /= N;
        while (cnt--) {
            gcd *= x.first;
        }
    }
    cout << gcd;

    // 필요한 인수 개수 구하기
    int cnt = 0;
    for (int i = 0; i < N; i++) {
        for (auto x : mp) {
            int gcd_prime = x.first;
            int gcd_primeCnt = x.second;
            if (dict[i][gcd_prime] < gcd_primeCnt) {
                cnt += (gcd_primeCnt - dict[i][gcd_prime]);
            }
        }
    }
    cout << " " << cnt;

    return 0;
}