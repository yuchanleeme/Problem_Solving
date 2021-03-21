#include <bits/stdc++.h>
using namespace std;
//https://acmicpc.net/problem/10282

/*
<해킹>
주요: 다익스트라
1. 다익스트라 알고리즘을 통해 바이러스의 전파 최단거리를 구한다.
2. 감염되었고, 가장 오래걸렸던 컴퓨터까지의 시간을 출력한다.
3. 모든 테스트케이스마다 값을 출력한다.

*/

int T;
int INF = 1e9 + 1000;
void dijkstra() {
    vector<pair<int, int> > graph[10101];
    vector<int> W(10101, INF);
    int n, d, c;
    cin >> n >> d >> c;
    for (int i = 0; i < d; i++) {
        int a, b, s;
        cin >> a >> b >> s;
        graph[b].push_back({a, s});
    }

    priority_queue<pair<int, int> > que;
    que.push({0, c});
    W[c] = 0;

    while (!que.empty()) {
        int cur_node = que.top().second;
        int cur_distance = -que.top().first;
        que.pop();

        if (W[cur_node] < cur_distance) continue;
        for (int i = 0; i < graph[cur_node].size(); i++) {
            int next_node = graph[cur_node][i].first;
            int next_distance = graph[cur_node][i].second + cur_distance;

            if (W[next_node] > next_distance) {
                W[next_node] = next_distance;
                que.push({-next_distance, next_node});
            }
        }
    }

    int cnt = 0;
    int time = 0;
    for (int i = 1; i <= n; i++) {
        if (W[i] == INF)
            continue;
        else {
            cnt++;
            time = max(time, W[i]);
        }
    }
    cout << cnt << " " << time << "\n";
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> T;

    while (T--) {
        dijkstra();
    }

    return 0;
}