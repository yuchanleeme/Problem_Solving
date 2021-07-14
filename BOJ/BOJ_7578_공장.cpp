#include <bits/stdc++.h>
using namespace std;
//https://acmicpc.net/problem/7578

/*
<공장>
주요: 세그먼트 트리, Inversion Counting(Merge Sort)
1. 먼저, 장비의 번호들을 차례대로 re-indexing을 한다.
2. 차례대로 인덱스를 조사하면서 순서가 역전되어 있는 장비의 번호가 있는지 조사한다.
    ex) 1.  - - - O - - O - - (O는 앞의 장비들이 연결한 흔적)
        2.  - X - O - Y O Z -
        1, 2번 순서대로 진행하고, 
            연결될 장비의 위치가 X라면 O가 2개이므로 교차점 2개
            연결될 장비의 위치가 Y라면 O가 1개이므로 교차점 1개
            연결될 장비의 위치가 Zㄹ면 O이 0개이므로 교차점 0개
3. 오른쪽 방향의 장비의 개수를 구간합 세그먼트 트리로 저장해놓는다.
4. 결과를 출력한다.

*/
typedef long long ll;

int N;
ll tree[1010101 * 4];
ll newIdx[1010101];
ll arr[1010101];

// start~end 구간 값 업데이트
ll update(int node, int start, int end, int idx, int val) {
    if (idx < start || end < idx) return tree[node];
    if (start == end) {
        return tree[node] = val;
    }
    int mid = (start + end) / 2;
    return tree[node] = update(node * 2, start, mid, idx, val) + update(node * 2 + 1, mid + 1, end, idx, val);
}

ll sum(int node, int start, int end, int left, int right) {
    if (right < start || end < left) return 0;
    if (left <= start && end <= right) return tree[node];

    int mid = (start + end) / 2;
    return sum(node * 2, start, mid, left, right) + sum(node * 2 + 1, mid + 1, end, left, right);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> N;
    // 순서 입력
    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
    }

    // 새롭게 인덱싱
    for (int i = 1; i <= N; i++) {
        int temp;
        cin >> temp;
        newIdx[temp] = i;
    }

    ll ans = 0;
    for (int i = 1; i <= N; i++) {
        long long connect = newIdx[arr[i]];
        ans += sum(1, 1, N, connect + 1, N);
        update(1, 1, N, connect, 1);
    }

    cout << ans;

    return 0;
}