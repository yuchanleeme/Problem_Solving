#include <bits/stdc++.h>
using namespace std;
//https://programmers.co.kr/learn/courses/30/lessons/72413

/*
<합승 택시 요금>
주요: 플로이드 워셜
1. 플로이드 워셜 알고리즘으로 각각 경로의 최소값을 구한다.
2. 이제 거점을 기준으로 조건에 맞게 계산을 해 각 조건에 맞게 어느 거점이 최소인지 찾는다.
3. 조건에 맞는 값을 리턴한다.
-----------
* 플로이드워셜 쓰던지 다익스트라 2번 쓰던지

*/

long long INF = 1e9 * 2;
vector<vector<long long>> graph(210, vector<long long>(210, INF));

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    for (int i = 1; i <= n; i++) {
        graph[i][i] = 0;
    }

    for (auto fa : fares) {
        graph[fa[0]][fa[1]] = fa[2];
        graph[fa[1]][fa[0]] = fa[2];
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            for (int k = 1; k <= n; k++) {
                if (graph[j][k] > graph[j][i] + graph[i][k]) {
                    graph[j][k] = graph[j][i] + graph[i][k];
                }
            }
        }
    }

    // 거점 기준
    long long answer = INF;
    for (int i = 1; i <= n; i++) {
        if (graph[s][i] == INF || graph[i][a] == INF || graph[i][b] == INF) continue;
        answer = min(answer, graph[s][i] + graph[i][a] + graph[i][b]);
    }

    return answer;
}

int main() {
    cout << solution(6, 4, 6, 2, {{4, 1, 10}, {3, 5, 24}, {5, 6, 2}, {3, 1, 41}, {5, 1, 24}, {4, 6, 50}, {2, 4, 66}, {2, 3, 22}, {1, 6, 25}});
    return 0;
}