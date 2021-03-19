#include <bits/stdc++.h>
using namespace std;
//https://programmers.co.kr/learn/courses/30/lessons/42861

/*
<섬 연결하기>
주요: 유니온 파인드, 크루스칼
1. 크루스칼 알고리즘을 통해 구현한다.
2. 유니온 파인드 알고리즘을 통해 크루스칼 알고리즘을 구현한다.
3. 최소 값을 구한다.
==========
* find함수만 써도 구현이 가능하지만 유니온 파인드를 이용해 풀기 위해 일부러 unite함수를 넣었다.

*/

vector<pair<int, int>> graph[110];  // 연결된 섬, 거리
int parent[110];

void init(int N) {
    for (int i = 0; i < N; i++) {
        parent[i] = i;
    }
}

int find(int x) {
    if (parent[x] == x) {
        return x;
    } else {
        return find(parent[x]);
    }
}

void unite(int x, int y) {
    x = find(x), y = find(y);
    if (x == y)
        return;
    else {
        parent[x] = y;
    }
}

// costs 벡터 정렬
bool comp(vector<int> &A, vector<int> &B) {
    return A[2] < B[2];
}

int solution(int n, vector<vector<int>> costs) {
    int cnt = 0;
    int answer = 0;
    init(n);
    sort(costs.begin(), costs.end(), comp);
    for (auto items : costs) {
        if (find(items[0]) != find(items[1])) {
            cnt++;
            unite(items[0], items[1]);
            answer += items[2];
        }
    }

    return answer;
}