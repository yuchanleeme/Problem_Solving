#include <bits/stdc++.h>
using namespace std;
//https://acmicpc.net/problem/5676

/*
<음주 코딩>
주요: 세그먼트 트리
1. 세그먼트 트리를 구현해서 구간 곱을 구한다.
2. 단, 범위를 초과하는것을 염두해 -1, 0, 1로 치환해서 사용한다.
3. 구간 곱 세그먼트 트리를 구해서 푼다.
4. 명령어별 결과를 출력한다.
==========
* 배열 초기화를 잘하자. tree의 초기 값은 0, 곱셉에 대한 역원은 1이다.

*/

int N, K;
vector<int> arr;
vector<int> tree;

int change(int num) {
    if (num > 0) return 1;
    else if (num < 0)
        return -1;
    else if (num == 0)
        return 0;
}

int update(int node, int start, int end, int idx, int val) {
    if (idx < start || idx > end) return tree[node];
    if (start == end) return tree[node] = val;
    int mid = (start + end) / 2;
    return tree[node] = update(node * 2, start, mid, idx, val) * update(node * 2 + 1, mid + 1, end, idx, val);
}

int query(int node, int start, int end, int l, int r) {
    if (end < l || r < start) return 1;
    if (l <= start && end <= r) return tree[node];
    int mid = (start + end) / 2;
    return query(node * 2, start, mid, l, r) * query(node * 2 + 1, mid + 1, end, l, r);
}

void func(int N, int K) {
    tree.clear();
    arr.clear();

    tree = vector<int>(N * 5, 0);
    arr = vector<int>(N + 1, 0);

    // 처음 배열
    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
        int val = change(arr[i]);
        update(1, 1, N, i, val);
    }

    for (int i = 0; i < K; i++) {
        char op;
        int A, B;
        cin >> op >> A >> B;
        if (op == 'C') {
            update(1, 1, N, A, change(B));
        } else if (op == 'P') {
            int res = query(1, 1, N, A, B);
            if (res > 0) cout << "+";
            else if (res < 0)
                cout << "-";
            else if (res == 0)
                cout << "0";
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    while (cin >> N >> K) {
        func(N, K);
        cout << "\n";
    }

    return 0;
}