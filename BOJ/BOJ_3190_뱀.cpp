#include <bits/stdc++.h>
using namespace std;
//https://acmicpc.net/problem/3190

/*
<뱀>
주요: 덱, 큐, 시뮬레이션
1. 머리를 움직이고, 따라오는 몸통은 그 앞의 몸의 정보를 이어 받는다.
2. 머리가 움질일 때 방향을 꺾는지, 아니면 계속 직진하는지 판단한다.
3. 그 다음 사과의 위치에 따라 정보를 갱신한다.
4. 시뮬레이션을 돌렸을 때의 결과값을 출력한다.

*/

int N, K, L;
int board[110][110];
queue<pair<int, char> > dir;
deque<pair<int, int> > deq;

int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};  // D이면 idx +1, L이면 idx -1

int main() {
    cin >> N >> K;
    for (int i = 0; i < K; i++) {
        int x, y;
        cin >> x >> y;
        board[x - 1][y - 1] = 2;
    }

    cin >> L;
    for (int i = 0; i < L; i++) {
        int X;
        char C;
        cin >> X >> C;
        dir.push({X, C});
    }

    int time = 0, dirIdx = 0;
    deq.push_front({0, 0});  // 뱀의 머리 정보를 덱에 넣는다.
    board[0][0] = 1;         // 뱀이 있다고 처리
    while (true) {
        ++time;
        int nx = deq.front().first + dx[dirIdx];
        int ny = deq.front().second + dy[dirIdx];

        if (nx < 0 || nx >= N || ny < 0 || ny >= N) break;  // 벽에 부딪힐 때
        if (board[nx][ny] == 1) break;                      // 나랑 부딪힐 때

        // 사과가 있을 때, 없을 때
        if (board[nx][ny] == 2) {
            board[nx][ny] = 1;
            deq.push_front({nx, ny});
        } else {
            board[nx][ny] = 1;
            deq.push_front({nx, ny});
            int lx = deq.back().first;
            int ly = deq.back().second;
            board[lx][ly] = 0;
            deq.pop_back();
        }

        // 방향 전환
        if (!dir.empty()) {
            int nowTurn = dir.front().first;
            if (time == nowTurn) {
                char nowC = dir.front().second;
                if (nowC == 'D')
                    dirIdx = (dirIdx + 1) % 4;
                else if (nowC == 'L')
                    dirIdx = (dirIdx + 4 - 1) % 4;
                dir.pop();
            }
        }
    }

    cout << time;

    return 0;
}