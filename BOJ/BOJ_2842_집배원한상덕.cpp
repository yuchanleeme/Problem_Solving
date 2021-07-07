#include <bits/stdc++.h>
using namespace std;
//https://acmicpc.net/problem/2842

/*
<집배원 한상덕>
주요: BFS, 투 포인터
1. 최소 높이, 최대 높이를 먼저 선정해 놓고 BFS 탐색을 통해 개수를 찾는다.
2. 단, 최소 높이, 최대 높이는 유효한 값만 이용할 수 있게 설정한다. (입력에서 미리 받아놓는다.)
3. 투 포인터를 이용해 최소 높이, 최대 높이를 조절해 값을 찾는다.
4. 최소 피로도를 출력한다.
===========
* 이것저것 카운팅이 많은 문제, 효율성을 고려하는 습관을 기르자.

*/

typedef struct Info {
    int x;
    int y;
} Info;

const int INF = 1e9;
int N, px, py, k_cnt, lo, hi, ans = INF;
vector<string> town;
vector<int> harr;
int height[55][55];
int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1}, dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

// low ~ high로 방문할 수 있는 집의 숫자를 리턴
int bfs(int low, int high) {
    // 시작점이 유효하지 않으면 0으로 리턴
    if (height[px][py] < harr[low] || height[px][py] > harr[high]) return 0;

    int bfs_cnt = 0;
    queue<Info> que;
    bool visit[55][55] = {
        false,
    };
    visit[px][py] = true;
    que.push({px, py});

    while (!que.empty() && bfs_cnt < k_cnt) {
        Info now = que.front();
        que.pop();

        for (int j = 0; j < 8; j++) {
            int nx = now.x + dx[j];
            int ny = now.y + dy[j];

            if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
            if (height[nx][ny] < harr[low] || height[nx][ny] > harr[high]) continue;
            if (visit[nx][ny] == true) continue;
            if (town[nx][ny] == 'K') bfs_cnt++;
            visit[nx][ny] = true;
            que.push({nx, ny});
        }
    }
    return bfs_cnt;
}

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        string temp;
        cin >> temp;
        town.push_back(temp);
        for (int j = 0; j < N; j++) {
            if (town[i][j] == 'P') {
                px = i;
                py = j;
            } else if (town[i][j] == 'K') {
                k_cnt++;
            }
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> height[i][j];
            harr.push_back(height[i][j]);
        }
    }

    // 중복 제거
    sort(harr.begin(), harr.end());
    harr.erase(unique(harr.begin(), harr.end()), harr.end());

    Info st = {px, py};
    lo = harr[0];
    hi = harr[0];
    int lidx = 0, hidx = 0;

    while (lidx <= hidx && lidx < harr.size() && hidx < harr.size()) {
        int res = bfs(lidx, hidx);
        if (res == k_cnt) {
            ans = min(ans, harr[hidx] - harr[lidx]);
            lidx += 1;
        } else {
            hidx += 1;
        }
    }
    cout << ans;

    return 0;
}