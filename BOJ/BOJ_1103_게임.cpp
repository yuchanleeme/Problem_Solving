#include <bits/stdc++.h>
using namespace std;
//https://acmicpc.net/problem/1103

/*
<게임>
주요: DFS, DP
1. 0,0 부터 DFS 탐색을 통해 갈 수 있는 위치인지 확인한다.
2. 갈 수 있다면 내가 방문 했었는지 확인한다.
    -> 내가 이미 방문을 했다면 또 돌고 돌아 방문할 것이므로 무한번 돈다고 할 수 있다.
3. 모든 과정에서 내가 방문이 가능했다면 현재의 깊이(level)를 dp 값으로 지정한다.
    -> DP[x][y] = x,y에 도달할 수 있는 최대 거리
4. 현재 깊이보다 더 적은 방법으로 방문했으면 계산에서 빼준다.
5. 최종 결과값을 출력한다.
==========
* 싸이클을 찾을때는 DFS 쓰는게 좋다...
  -> BFS로 싸이클을 찾는거보다 훨씬 쉬웠다.
*/

int N, M, ans;
vector<string> board;
bool visitBoard[55][55];
int dp[55][55];                                    // x, y에 도달 할 수 있는 최대 거리
int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};  // 북 동 남 서
bool isInfinity = false;

void dfs(int level, int x, int y) {
    if (isInfinity) return;
    ans = max(ans, level);

    int cur_num = board[x][y] - '0';
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i] * cur_num;
        int ny = y + dy[i] * cur_num;

        if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
        if (board[nx][ny] == 'H') continue;
        if (dp[nx][ny] > level) continue;
        if (visitBoard[nx][ny] == true) {
            isInfinity = true;
            return;
        }
        visitBoard[nx][ny] = true;
        dp[x][y] = level;
        dfs(level + 1, nx, ny);
        visitBoard[nx][ny] = false;
    }
}

int main() {
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        string temp;
        cin >> temp;
        board.push_back(temp);
    }

    dp[0][0] = 0;
    dfs(1, 0, 0);

    if (isInfinity) cout << "-1";
    else
        cout << ans;

    return 0;
}