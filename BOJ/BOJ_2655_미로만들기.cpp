#include <bits/stdc++.h>
using namespace std;
//www.acimpc.net/problem/2655

/*
<미로 만들기>
주요: BFS
1. BFS탐색을 통해 전 경로를 돌아다닌다.
2. res[x][y] = K => (x,y)에 도달 했을 때 방을 바꾼 횟수
3. res 배열과 비교하며 BFS 탐색을 한다.
4. 모든 경로 탐색이 끝났을 시 그 결과 res[N-1][N-1] 을 출력한다. 

*/

typedef struct info {
    int x;
    int y;
    int cnt;
} Info;

int N;
int check[52][52];
int res[52][52];
vector<string> room;
queue<Info> que;

int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        string temp;
        cin >> temp;
        room.push_back(temp);
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            res[i][j] = 2555;
        }
    }

    res[0][0] = 0;
    que.push({0, 0, 0});

    while (!que.empty()) {
        for (int i = 0; i < 4; i++) {
            int nx = que.front().x + dx[i];
            int ny = que.front().y + dy[i];
            int ncnt = que.front().cnt;

            if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
            if (room[nx][ny] == '1') {
                //검은방
                if (res[nx][ny] > ncnt) {
                    res[nx][ny] = ncnt;
                    que.push({nx, ny, ncnt});
                }
            } else if (room[nx][ny] == '0') {
                // 흰방
                if (res[nx][ny] > ncnt + 1) {
                    res[nx][ny] = ncnt + 1;
                    que.push({nx, ny, ncnt + 1});
                }
            }
        }
        que.pop();
    }
    cout << res[N - 1][N - 1];

    return 0;
}