#include <bits/stdc++.h>
using namespace std;
//https://acmicpc.net/problem/11779

/*
<최소비용 구하기2>
주요: 다익스트라
1. 다익스트라 알고리즘을 구현한다.
2. 거리가 갱신될 때마다 경로 추적 벡터를 갱신해준다.
3. 문제에서 요구하는 조건대로 출력해준다.

*/

int n, m, st, ed;
vector<pair<int, int> > graph[1010];
vector<int> W(1010, 1e9 + 1000);
vector<vector<int> > route(1010);

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int x, y, d;
        cin >> x >> y >> d;
        graph[x].push_back({y, d});
    }
    cin >> st >> ed;

    priority_queue<pair<int, int> > que;
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

            // 값이 바뀔 때 경로 저장
            if (next_distance < W[next_node]) {
                W[next_node] = next_distance;
                vector<int> temp = route[cur_node];
                temp.push_back(next_node);
                route[next_node] = temp;
                que.push({-next_distance, next_node});
            }
        }
    }

    cout << W[ed] << "\n";
    cout << route[ed].size() + 1 << "\n";
    cout << st << " ";
    for (int i = 0; i < route[ed].size() - 1; i++) {
        cout << route[ed][i] << " ";
    }
    cout << ed;

    return 0;
}