#include <bits/stdc++.h>
using namespace std;
//https://acmicpc.net/problem/13549

/*
<숨바꼭질 3>
주요: 다익스트라
1. 2배인 노드는 크기가 0인 간선이라 치고 나머지 x-1, x+1인 노드는 1인 간선인 그래프를 만든다.
2. 이제 다익스트라 알고리즘을 이용해 모든 노드의 최단거리를 구한다.
3. 타겟 위치의 최단거리 값을 출력한다.
==========
* 0-1 BFS알고리즘으로 풀 수 있다.

*/

int N, K;
vector<pair<int, int> > graph[101010];
vector<int> W(101010, 101010);

int main() {
    cin >> N >> K;
    for (int i = 0; i <= 100000; i++) {
        if (i - 1 >= 0)
            graph[i].push_back({i - 1, 1});
        if (i + 1 <= 100000)
            graph[i].push_back({i + 1, 1});
        if (i * 2 <= 100000)
            graph[i].push_back({i * 2, 0});
    }

    priority_queue<pair<int, int> > que;
    que.push({0, N});
    W[N] = 0;

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
    cout << W[K];
    return 0;
}