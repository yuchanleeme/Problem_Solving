#include <bits/stdc++.h>
using namespace std;
//https://programmers.co.kr/learn/courses/30/lessons/43162

/*
<네트워크>
주요: DFS
1. 컴퓨터끼리 인접 배열을 만든다.
2. DFS 탐색으로 각 네트워크의 개수를 센다.

*/

int network[210];

void dfs(int &n, vector<vector<int>> &computers, int prev) {
    for (int i = 0; i < n; i++) {
        if (network[i] == 0 && computers[prev][i] == 1) {
            network[i] = 1;
            dfs(n, computers, i);
        }
    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    for (int i = 0; i < n; i++) {
        if (network[i] == 0) {
            network[i] = 1;
            dfs(n, computers, i);
            answer++;
        }
    }

    return answer;
}