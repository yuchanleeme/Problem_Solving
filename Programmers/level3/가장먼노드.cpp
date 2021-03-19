#include <bits/stdc++.h>
using namespace std;
//https://programmers.co.kr/learn/courses/30/lessons/49189

/*
<가장 먼 노드>
주요: 다익스트라
1. 간선의 길이가 1인 그래프라고 생각하고 계산한다.
2. max_element를 써서 maxValue를 찾고 그에 해당하는 idx를 센다.
3. 결과값을 리턴한다.
==========
* max_elemnt 사용법 숙지

*/

vector<pair<int, int>> graph[20201];
vector<int> W(20201, 20201);

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;

    for (int i = 0; i < edge.size(); i++) {
        int x1 = edge[i][0];
        int x2 = edge[i][1];
        graph[x1].push_back({1, x2});
        graph[x2].push_back({1, x1});
    }

    priority_queue<pair<int, int>> que;
    que.push({0, 1});
    W[1] = 0;

    while (!que.empty()) {
        int cur_node = que.top().second;
        int cur_distance = -que.top().first;
        que.pop();

        if (cur_distance > W[cur_node]) continue;
        for (int i = 0; i < graph[cur_node].size(); i++) {
            int next_node = graph[cur_node][i].second;
            int next_distance = graph[cur_node][i].first + cur_distance;

            if (W[next_node] > next_distance) {
                W[next_node] = next_distance;
                que.push({-next_distance, next_node});
            }
        }
    }
    int maxValue = *max_element(W.begin() + 1, W.begin() + n + 1);

    for (int i = 1; i <= n; i++) {
        if (W[i] == maxValue) answer++;
    }

    return answer;
}