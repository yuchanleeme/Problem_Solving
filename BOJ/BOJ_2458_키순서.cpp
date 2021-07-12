#include <bits/stdc++.h>
using namespace std;
//https://acmicpc.net/problem/2458

/*
<키순서>
주요: DFS
1. DFS탐색을 통해 각 노드별 방문할 수 있는 노드의 수를 센다.
2. 이렇게 센 노드 카운트 벡터를 오름차순으로 정렬한다.
3. 이제 등수를 알아보기 위해 1,2,3,4,5...N을 nodeCnt[1], nodeCnt[2]...nodeCnt[N]과 각각 비교한다.
4. 중복되는 숫자 없이 유일하게 현재 idx와 해당 nodeCnt[idx]가 같으면 등수를 알 수 있는 것이다.
5. 모든 결과를 측정해 정답을 출력한다.

*/

int N, M, ans;
vector<int> graph[505];
vector<bool> v;
int nodeCnt[505];

void dfs(int prev, int num) {
    for (int i = 0; i < graph[prev].size(); i++) {
        int next = graph[prev][i];
        if (v[next] == true) continue;
        else {
            v[next] = true;
            nodeCnt[num]++;
            dfs(next, num);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M;

    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
    }

    for (int i = 1; i <= N; i++) {
        v = vector<bool>(N + 1, false);
        v[i] = true;
        dfs(i, i);
        nodeCnt[i]++;
    }

    sort(nodeCnt + 1, nodeCnt + 1 + N);

    int idx = 1;
    while (idx <= N) {
        if (idx == nodeCnt[idx]) {
            int sameCnt = 0, cmp = nodeCnt[idx];
            while (idx <= N && cmp == nodeCnt[idx]) {
                sameCnt++;
                idx++;
            }
            if (sameCnt == 1) ans++;
        } else {
            idx++;
        }
    }
    cout << ans;
    return 0;
}