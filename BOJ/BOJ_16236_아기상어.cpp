#include <bits/stdc++.h>
using namespace std;
//https://acmicpc.net/problem/16236

/*
<아기 상어>
주요: 시뮬레이션 
1. 먼저 상어의 위치로 부터 BFS 탐색을 통해 갈 수 있는 모든 격자의 위치에 거리값(거리 배열)을 표시한다.
2. 위에서부터 왼쪽에서부터 먼저 먹는다 했으므로 2중 for문 방향으로 조사한다.
3. 거리 배열에서 유효한 값을 찾아 먹을 수 있는 물고기를 찾는다.
4. 물고기를 먹을 수 있으면 상어의 위치와 크기, 위치를 초기화 한다.
5. 결과를 출력한다.

*/

int N, sx, sy, ans, sd = 2, sc = 2;  // sx, sy : 상어위치  sd: 상어 크기 sc: 상어 커질때까지 남은 물고기 수
int board[22][22];
bool eat[22][22];
int dx[4] = {0, 1, -1, 0}, dy[4] = {1, 0, 0, -1};
const int INF = 500;

bool step() {
    int dis = 0;
    vector<vector<int> > mapDistance(22, vector<int>(22, INF));
    queue<pair<int, int> > que;
    que.push({sx, sy});
    mapDistance[sx][sy] = 0;

    // bfs
    while (!que.empty()) {
        ++dis;  // 거리
        int temp_size = que.size();
        while (temp_size--) {
            for (int i = 0; i < 4; i++) {
                int nx = que.front().first + dx[i];
                int ny = que.front().second + dy[i];

                if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;

                if (board[nx][ny] <= sd && mapDistance[nx][ny] > dis) {
                    mapDistance[nx][ny] = dis;
                    que.push({nx, ny});
                }
            }
            que.pop();
        }
    }

    // 거리배열에서 유효한 값을 찾아 먹을 수 있는 물고기를 찾음
    int fx = -1, fy = -1, fd = INF;  // 물고기 위치
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (mapDistance[i][j] == INF || mapDistance[i][j] == 0) continue;
            if (board[i][j] > 0 && board[i][j] < sd && mapDistance[i][j] < fd) {
                fx = i, fy = j;
                fd = mapDistance[i][j];
            }
        }
    }

    // 물고기를 먹을 수 있으면 상어의 위치와 크기, 위치를 초기화 한다.
    if (fx == -1 && fy == -1)
        return false;
    else {
        board[fx][fy] = 0;
        ans += mapDistance[fx][fy];
        sc--;
        sx = fx, sy = fy;
        if (sc == 0) {
            sd++;
            sc = sd;
        }
        return true;
    }
}

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> board[i][j];
            if (board[i][j] == 9) {
                sx = i;
                sy = j;
                board[i][j] = 0;  // 상어 위치 초기화
            }
        }
    }

    while (true) {
        if (!step()) break;
    }
    cout << ans;

    return 0;
}