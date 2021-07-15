#include <bits/stdc++.h>
using namespace std;
//https://acmicpc.net/problem/1615

/*
<교차수세기>
주요: 세그먼트 트리, Inversion Count
1. 세그먼트 트리를 활용해서 오른쪽에 위치했던 정점들의 개수를 찾는다.
2. 차례대로 정점들을 조사하되, 간선들의 정보는 업데이트 하지 않고 개수만 먼저 구해서 더해준다.
3. 모든 간선들의 조사가 끝났을 때, 간선들의 정보들을 업데이트 해준다.
4. 최종 ans를 출력한다.

*/

typedef long long ll;

int N, M;
vector<ll> G[2020];
ll tree[2020 * 4];

// 업데이트
ll update(int node, int start, int end, int idx, int val) {
    if (idx < start || idx > end) return tree[node];
    if (start == end) return tree[node] += val;  // 중복으로 더해주기
    int mid = (start + end) / 2;
    return tree[node] = update(node * 2, start, mid, idx, val) + update(node * 2 + 1, mid + 1, end, idx, val);
}

// 구간 합 구하기
ll sum(int node, int start, int end, int left, int right) {
    if (right < start || end < left) return 0;
    if (left <= start && end <= right) return tree[node];
    int mid = (start + end) / 2;
    return sum(node * 2, start, mid, left, right) + sum(node * 2 + 1, mid + 1, end, left, right);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        int x, y;
        cin >> x >> y;
        G[x].push_back(y);  // 노드 x와 연결된 정점은 y이다.
    }

    ll ans = 0;
    for (int i = 1; i <= N; i++) {
        // 일단 간선 정보 업데이트 하지 않고 오른쪽~N까지의 개수 구하기
        for (int j = 0; j < G[i].size(); j++) {
            int next_node = G[i][j];
            ans += sum(1, 1, N, next_node + 1, N);
        }

        // i번째 노드 간선들의 모든 개수를 구한 뒤 정보 업데이트
        for (int j = 0; j < G[i].size(); j++) {
            int next_node = G[i][j];
            update(1, 1, N, next_node, 1);
        }
    }
    cout << ans;

    return 0;
}