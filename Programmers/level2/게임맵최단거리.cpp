#include <bits/stdc++.h>
using namespace std;
//https://programmers.co.kr/learn/courses/30/lessons/1844

/*
<게임 맵 최단거리>
주요: BFS
1. 최단거리를 구하기 위해 BFS탐색을 진행한다.
2. 목표 위치에 도달했으면 해당 answer를 출력한다.

*/

int N, M;
int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
bool visitCheck[110][110];

int solution(vector<vector<int> > maps) {
    int answer = 1;
    N = maps.size();
    M = maps[0].size();

    queue<pair<int, int> > que;
    que.push({0, 0});
    visitCheck[0][0] = true;

    while (!que.empty()) {
        int temp_size = que.size();
        ++answer;
        while (temp_size--) {
            for (int i = 0; i < 4; i++) {
                int nx = que.front().first + dx[i];
                int ny = que.front().second + dy[i];
                if (nx == N - 1 && ny == M - 1) return answer;

                if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
                if (visitCheck[nx][ny] == true || maps[nx][ny] == 0) continue;
                visitCheck[nx][ny] = true;
                que.push({nx, ny});
            }
            que.pop();
        }
    }

    return -1;
}