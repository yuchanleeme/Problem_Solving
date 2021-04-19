#include <bits/stdc++.h>
using namespace std;
//https://acmicpc.net/problem/20922

/*
<겹치는 건 싫어>
주요: 투 포인터
1. st, ed 인덱스 2개로 값을 조사해나간다.
2. arr[ed]를 조사할 때, 최대로 등장했다면 st를 움직여 조사 길이를 조절한다.
3. 이 과정에서 조사 길이의 값과 해당값 방문 횟수 배열을 최신화 해주어야한다.
4. 최종 결과를 출력한다.
==========
* st 움질일 때 cnt 배열도 최신화 해주어야한다.

*/

int N, K, st, ed, ans;
int cnt[201010];
vector<int> arr;

int main() {
    cin >> N >> K;

    for (int i = 0; i < N; i++) {
        int temp;
        cin >> temp;
        arr.push_back(temp);
    }

    for (int i = 0; i < N; i++) {
        ed = i;
        if (cnt[arr[ed]] + 1 > K) {
            while (arr[st] != arr[ed]) {
                cnt[arr[st++]]--;
            }
            st++;
        } else {
            cnt[arr[ed]]++;
            ans = max(ed - st + 1, ans);
        }
    }
    cout << ans;

    return 0;
}