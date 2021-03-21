#include <bits/stdc++.h>
using namespace std;
//https://acmicpc.net/problem/1916

/*
<최소비용 구하기>
주요: 다익스트라
1. 다익스트라 알고리즘을 이용해 A 도시에 출발하는 모든 최단거리를 구한다.
2. 그 중 B도시까지의 거리를 출력한다.

*/

int N, M, st, ed;
vector<pair<int, int>> graph[1010];
vector<int> W(1010, 1e8 + 1000);

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> N >> M;

    for (int i = 0; i < M; i++) {
        int x, y, d;
        cin >> x >> y >> d;
        graph[x].push_back({y, d});
    }
    cin >> st >> ed;

    priority_queue<pair<int, int>> que;
    que.push({0, st});
    W[st] = 0;

    while (!que.empty()) {
        int cur_node = que.top().second;
        int cur_distance = -que.top().first;
        que.pop();
        if (W[cur_node] < cur_distance) continue;
        for (int i = 0; i < graph[cur_node].size(); i++) {
            int next_node = graph[cur_node][i].first;
            int next_distance = graph[cur_node][i].second + cur_distance;
            if (next_distance < W[next_node]) {
                W[next_node] = next_distance;
                que.push({-next_distance, next_node});
            }
        }
    }
    cout << W[ed];

    return 0;
}