#include <bits/stdc++.h>
using namespace std;
//https://programmers.co.kr/learn/courses/30/lessons/67259

/*
<경주로 건설>
주요: BFS, 구현
1. 모든 경우를 계산한다.
2. 이전방향이 어딘가에 따라서 코너를 돌았는지 직진인지 판단한다.
3. 2번사항을 기준으로 DP 배열을 만들면서 BFS 탐색을 돈다.
    => 값이 최소를 조건으로 BFS 탐색
4. 최소비용을 리턴한다.
==========
* 직선 100원, 코너 500
* 방위표
   3
 2   0
   1 
*/

typedef struct loc {
    int x;
    int y;
    int price;  // 현재까지 가격
    int dir;    // 이전 방향
} Loc;

int dp[30][30][5];
int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};
int answer = 1e9 * 2;

queue<Loc> que;

int cal_price(int prev, int next) {
    if (prev == next)
        return 100;
    else
        return 100 + 500;
}

int solution(vector<vector<int>> board) {
    int N = board.size();
    que.push({0, 0, 0, -1});

    while (!que.empty()) {
        int qx = que.front().x;
        int qy = que.front().y;
        int qp = que.front().price;
        int prev_dir = que.front().dir;

        que.pop();

        for (int idx = 0; idx < 4; idx++) {
            int nx = qx + dx[idx];
            int ny = qy + dy[idx];
            if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
            if (board[nx][ny] == 1) continue;
            if (prev_dir == -1) {
                // 시작 할 때니까
                dp[nx][ny][idx] = 100;
                que.push({nx, ny, 100, idx});
            } else if (abs(prev_dir - idx) == 2) {
                // 왔던길 되돌아 오는 경우
                continue;
            } else {
                int np = qp + cal_price(prev_dir, idx);
                if (dp[nx][ny][idx] == 0 || dp[nx][ny][idx] > np) {
                    dp[nx][ny][idx] = np;
                    que.push({nx, ny, np, idx});
                }
            }
        }
    }

    for (int idx = 0; idx < 4; idx++) {
        if (dp[N - 1][N - 1][idx] == 0) continue;
        answer = min(answer, dp[N - 1][N - 1][idx]);
    }
    return answer;
}

int main() {
    return 0;
}