#include <bits/stdc++.h>
using namespace std;
//https://acmicpc.net/problem/3830

/*
<교수님은 기다리지 않는다.>
주요: 유니온파인드 
1. 유니온파인드를 통해 구현을 한다.
2. 현재 부모(par[X])까지의 거리를 dist 벡터로 한다.
3. 새로운 루트를 그려보며 판단해본다.
4. 정답을 출력한다.

*/

vector<int> par;
vector<long long> dist;

void init(int N) {
    for (int i = 1; i <= N; i++) {
        par[i] = i;
    }
}

int find(int x) {
    if (par[x] == x) {
        return x;
    } else {
        int parX = find(par[x]);
        dist[x] += dist[par[x]];  // 부모까지의 거리로 업데이트
        return par[x] = parX;
    }
}

void unite(int x, int y, long long w) {
    int parx = find(x), pary = find(y);
    if (parx == pary) return;

    // 새로운 부모까지의 거리초기화
    // 새로운 루트 : parY -> x -> parX
    // parY -> x = w + dist[y]
    dist[pary] = dist[x] + (w - dist[y]);

    par[pary] = parx;
    return;
}

void func(int N, int M) {
    // 초기화
    par = vector<int>(N + 1, 0);
    dist = vector<long long>(N + 1, 0);
    init(N);

    for (int ip = 0; ip < M; ip++) {
        char op;
        int a, b, w;
        cin >> op;

        if (op == '!') {
            cin >> a >> b >> w;
            unite(a, b, w);
        } else if (op == '?') {
            cin >> a >> b;
            if (find(a) != find(b)) {
                cout << "UNKNOWN\n";
            } else {
                cout << dist[b] - dist[a] << "\n";
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    while (true) {
        int N, M;
        cin >> N >> M;
        if (N == 0 && M == 0) return 0;
        func(N, M);
    }

    return 0;
}