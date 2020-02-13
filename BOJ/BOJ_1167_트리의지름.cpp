#include <iostream>
#include <vector>
using namespace std;
//https://www.acmicpc.net/problem/1167

/*
<트리의 지름>
주요: 트리의 지름
1. 한 트리에서 가장 긴 지름의 길이를 구하는 공식을 이용한다. (양수 가중치)
	1-1 아무점이나 잡고 a라고 한다.
	1-2. a에서 가장 먼 점을 b라고 한다
	1-3. b에서 가장 먼 점을 c라고 한다.
	1-4. b<->c가 가장 긴 지름이다
2 DFS로 각 1-2, 1-3을 구해 값을 찾는다.

*/

int N;
vector<pair<int, int> > g[100100]; // 연결 정점, 가중치
int dist[100100];

void dfs(int n, int prev){

	for (int i = 0; i < g[n].size(); i++) {
		int next = g[n][i].first, cost = g[n][i].second;
		if(next == prev) continue;
		dist[next] = dist[n] + cost;
		dfs(next, n);
	}
}

int main(int argc, char const *argv[]) {

	cin >> N;

	for (int i = 0; i < N; i++) {
		int u, v, w;
		cin >> u;
		while (true) {
			cin >> v;
			if(v == -1) break;
			cin >> w;
			g[u].push_back({v,w});
		}
	}

	dfs(1, 0); // 1부터 다른 모든 정점까지의 거리
	int a = 1;
	for (int i = 1; i <= N; i++) {
		if(dist[a] < dist[i]) a = i;
	}
	for (int i = 1; i <= N; i++) {
		dist[i] = 0;
	}

	dfs(a, 0);
	int b = 1;
	for (int i = 1; i <= N; i++) {
		if(dist[b] < dist[i]) b = i;
	}

	cout << dist[b];

	return 0;
}
