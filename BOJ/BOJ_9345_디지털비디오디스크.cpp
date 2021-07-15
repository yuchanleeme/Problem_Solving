#include <bits/stdc++.h>
using namespace std;
//https://acmicpc.net/problem/9345

/*
<디지털 비디오 디스크>
주요: 세그먼트 트리 
1. 최소값 세그트리와 최댓값 세그트리를 만든다.
  ex) 2~4 번을 빌릴거고 A~B구간을 조사했을 때, 구간 내 최솟값이 2이고, 구간 내 최댓값이 4이면 숫자가 연속으로 있다는 뜻이다. 
2. 각 명령어에 맞게 조건을 수행한다.
3. 단, 번호의 위치는 바뀔 수 있으므로, 따로 번호의 위치 벡터로 관리한다.
4. 조건마다 결과를 출력한다.
==========
* 시간을 더 최적화 하는 방법을 고민하자.

*/

typedef long long ll;
const int INF = 1e6;
int T, N, K;
vector<ll> tree_min;
vector<ll> tree_max;
vector<ll> arr;

ll min_update(int n, int st, int ed, int idx, int val) {
    if (idx < st || ed < idx) return tree_min[n];
    if (st == ed) return tree_min[n] = val;
    int mid = (st + ed) / 2;
    return tree_min[n] = min(min_update(n * 2, st, mid, idx, val), min_update(n * 2 + 1, mid + 1, ed, idx, val));
}

ll max_update(int n, int st, int ed, int idx, int val) {
    if (idx < st || ed < idx) return tree_max[n];
    if (st == ed) return tree_max[n] = val;
    int mid = (st + ed) / 2;
    return tree_max[n] = max(max_update(n * 2, st, mid, idx, val), max_update(n * 2 + 1, mid + 1, ed, idx, val));
}

ll min_query(int n, int st, int ed, int l, int r) {
    if (r < st || ed < l) return INF;
    if (l <= st && ed <= r) return tree_min[n];
    int mid = (st + ed) / 2;
    return min(min_query(n * 2, st, mid, l, r), min_query(n * 2 + 1, mid + 1, ed, l, r));
}
ll max_query(int n, int st, int ed, int l, int r) {
    if (r < st || ed < l) return -1;
    if (l <= st && ed <= r) return tree_max[n];
    int mid = (st + ed) / 2;
    return max(max_query(n * 2, st, mid, l, r), max_query(n * 2 + 1, mid + 1, ed, l, r));
}

void input() {
    cin >> N >> K;
    tree_min.clear();
    tree_max.clear();
    arr.clear();
    tree_min = vector<ll>(N * 4, 0);
    tree_max = vector<ll>(N * 4, 0);

    for (ll i = 0; i < N; i++) {
        min_update(1, 0, N - 1, i, i);
        max_update(1, 0, N - 1, i, i);
        arr.push_back(i);
    }

    for (int i = 0; i < K; i++) {
        int Q, a, b;
        cin >> Q >> a >> b;

        if (Q == 0) {
            int now_a = arr[a];
            int now_b = arr[b];
            min_update(1, 0, N - 1, a, now_b);
            min_update(1, 0, N - 1, b, now_a);
            max_update(1, 0, N - 1, a, now_b);
            max_update(1, 0, N - 1, b, now_a);
            arr[a] = now_b;
            arr[b] = now_a;

        } else if (Q == 1) {
            ll res_min = min_query(1, 0, N - 1, a, b);
            ll res_max = max_query(1, 0, N - 1, a, b);
            if (res_min == a && res_max == b) {
                cout << "YES\n";
            } else {
                cout << "NO\n";
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> T;
    while (T--) {
        input();
    }
    return 0;
}