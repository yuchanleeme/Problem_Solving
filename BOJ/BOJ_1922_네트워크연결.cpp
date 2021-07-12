#include <bits/stdc++.h>
using namespace std;
//https://acmicpc.net/problem/1922

/*
<네트워크 연결>
주요: 유니온 파인드
1. 크루스칼 알고리즘을 이용해 최소 스패닝 트리를 찾아 최소값을 구한다.
2. 효율성을 위해 각 깊이를 rnk배열에 넣는다.
3. 유니온 파인드 알고리즘을 이용한다.
4. 최종 결과를 출력한다.

*/

typedef struct edge {
    int u, v;
    long long w;
} Edge;

int N, M;
long long res;
vector<Edge> G;
int parent[1010];
int rnk[1010];

void init(int N) {
    for (int i = 1; i <= N; i++) {
        parent[i] = i;
        rnk[i] = 1;
    }
}

int find(int x) {
    if (parent[x] == x) {
        return x;
    } else {
        return parent[x] = find(parent[x]);
    }
}

void unite(Edge edge) {
    int pU = find(edge.u), pV = find(edge.v);
    if (pU == pV) return;
    else {
        if (rnk[pU] > rnk[pV]) swap(pU, pV);
        else if (rnk[pU] == rnk[pV])
            rnk[pV]++;

        parent[pU] = pV;
        res += edge.w;
    }
}

bool comp(const Edge &A, const Edge &b) {
    return A.w < b.w;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M;

    for (int i = 0; i < M; i++) {
        int x, y, w;
        cin >> x >> y >> w;
        if (x == y) continue;
        G.push_back({x, y, w});
    }

    sort(G.begin(), G.end(), comp);

    init(N);

    for (int i = 0; i < G.size(); i++) {
        unite(G[i]);
    }

    cout << res;

    return 0;
}