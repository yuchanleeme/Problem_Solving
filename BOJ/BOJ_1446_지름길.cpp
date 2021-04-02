#include <bits/stdc++.h>
using namespace std;
//https://acmicpc.net/problem/1446

/*
<지름길>
주요: 다익스트라 
1. 각 1m당 정점을 세운다고 생각해 i -> i+1 이렇게 1의 길이로 연결되어 있다고 생각한다.
2. 지름길의 끝 부분이 가려는 D 보다 크거나, 지름길을 이용하는게 더 느리다면 그래프의 정보를 넣지 않는다.
3. 최종 만들어진 그래프로 다익스트라 알고리즘을 돌아 정답을 출력한다.

*/

int N, D;
vector<pair<int, int> > graph[10100];
vector<int> W(10101, 10101);

int main() {
    cin >> N >> D;
    for (int i = 0; i <= D; i++) {
        graph[i].push_back({i + 1, 1});
    }

    for (int i = 0; i < N; i++) {
        int st, ed, d;
        cin >> st >> ed >> d;
        if (ed > D || (ed - st) < d) continue;
        graph[st].push_back({ed, d});
    }

    priority_queue<pair<int, int> > que;
    que.push({0, 0});
    W[0] = 0;

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
    cout << W[D];

    return 0;
}