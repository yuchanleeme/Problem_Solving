#include <bits/stdc++.h>
using namespace std;
//https://acmicpc.net/problem/3055

/*
<탈출>
주요: BFS
1. BFS 탐색을 진행한다.
2. 물 -> 고슴도치 -> 물 -> 고슴도치 순서로 BFS 탐색을 한다.
3. 조건에 맞는 결과를 출력한다.

*/

int R, C, ex, ey;
char forest[55][55];
bool board[55][55];  // true면 이동 불가
queue<pair<int, int> > water;
queue<pair<int, int> > G;
int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
int main() {
    cin >> R >> C;

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            scanf(" %c", &forest[i][j]);
            if (forest[i][j] == '*') {
                water.push({i, j});
                board[i][j] = true;
            } else if (forest[i][j] == 'D') {
                ex = i;
                ey = j;
                board[i][j] = true;
            } else if (forest[i][j] == 'S') {
                G.push({i, j});
            } else if (forest[i][j] == 'X') {
                board[i][j] = true;
            }
        }
    }

    int ans = 0;
    while (!G.empty()) {
        ans++;
        // 홍수 확장
        int water_size = water.size();
        for (int i = 0; i < water_size; i++) {
            for (int j = 0; j < 4; j++) {
                int nx = water.front().first + dx[j];
                int ny = water.front().second + dy[j];

                if (nx < 0 || ny < 0 || nx >= R || ny >= C) continue;
                if (board[nx][ny] == true) continue;
                board[nx][ny] = true;
                water.push({nx, ny});
            }
            water.pop();
        }

        int G_size = G.size();
        for (int i = 0; i < G_size; i++) {
            for (int j = 0; j < 4; j++) {
                int nx = G.front().first + dx[j];
                int ny = G.front().second + dy[j];

                if (nx == ex && ny == ey) return !printf("%d", ans);
                if (nx < 0 || ny < 0 || nx >= R || ny >= C) continue;
                if (board[nx][ny] == true) continue;
                board[nx][ny] = true;
                G.push({nx, ny});
            }
            G.pop();
        }
    }
    printf("KAKTUS");

    return 0;
}