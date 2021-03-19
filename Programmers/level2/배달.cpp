#include <bits/stdc++.h>
using namespace std;
//https://programmers.co.kr/learn/courses/30/lessons/12978

/*
<배달>
주요: 다익스트라 
1. 다익스트라 알고리즘을 통해 최단거리를 구한다.
2. 구한 최단거리 중 K 이하의 노드들의 수를 센다.
3. 센 결과를 리턴한다.

*/

vector<pair<int, int> > graph[52];
vector<int> W(52, 1000000);

int solution(int N, vector<vector<int> > road, int K) {
    int answer = 0;

    for (int i = 0; i < road.size(); i++) {
        int x1 = road[i][0];
        int x2 = road[i][1];
        int dist = road[i][2];
        graph[x1].push_back({dist, x2});
        graph[x2].push_back({dist, x1});
    }

    priority_queue<pair<int, int> > pq;
    pq.push({0, 1});
    W[1] = 0;

    while (!pq.empty()) {
        int cur_node = pq.top().second;
        int cur_distance = -pq.top().first;
        pq.pop();

        if (W[cur_node] < cur_distance) continue;
        for (int i = 0; i < graph[cur_node].size(); i++) {
            int next_node = graph[cur_node][i].second;
            int next_distance = graph[cur_node][i].first + cur_distance;

            if (next_distance < W[next_node]) {
                W[next_node] = next_distance;
                pq.push({-next_distance, next_node});
            }
        }
    }

    for (int i = 1; i <= N; i++) {
        if (W[i] <= K) answer++;
    }
    return answer;
}
