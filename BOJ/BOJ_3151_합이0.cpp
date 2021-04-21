#include <bits/stdc++.h>
using namespace std;
// https://acmicpc.net/problem/3151

/*
<합이 0>
주요: 이분탐색, 투포인터
1. 우선, 입력받은 코딩 실력 배열을 정렬한다.
2. 이제, 두개의 포인터를 이용해 정렬된 배열의 양 끝을 지정하고 이 합을 sum이라 한다.
3. 지정된 양 끝 포인터 사이에서 이제 -sum의 개수를 찾는다.(upper_bound - lower_bound)
4. 결과를 출력한다.
==========
* 정답 long long을 주의하자.
* DP 카운팅으로 푸는 방법도 있다.
=> 코딩 실력에 해당하는 값을 배열 형태로 저장시킨다.
=> 2중for문을 돌며 더했을 때 0이 되는 배열의 값을 차례대로 더한다.

*/

int N;
long long ans;

vector<int> ability;
int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> N;
    for (int i = 0; i < N; i++) {
        int temp;
        cin >> temp;
        ability.push_back(temp);
    }

    sort(ability.begin(), ability.end());

    for (int i = 0; i < N - 2; i++) {
        for (int j = i + 2; j < N; j++) {
            int sum = ability[i] + ability[j];

            auto st = ability.begin() + i + 1;
            auto ed = ability.begin() + j;

            auto idx1 = lower_bound(st, ed, -sum);
            auto idx2 = upper_bound(st, ed, -sum);

            ans += idx2 - idx1;
        }
    }
    cout << ans;

    return 0;
}