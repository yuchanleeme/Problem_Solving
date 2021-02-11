#include <bits/stdc++.h>
using namespace std;
//https://programmers.co.kr/learn/courses/30/lessons/17679

/*
<프렌즈 4블록>
주요: 구현
1. 4블록 짜리 위치를 찾아 그 위치를 explode 벡터에 넣는다. (4블록 기준 좌상)
2. explode 벡터에 있는 정보를 바탕으로 board 값을 '.'으로 바꾼다.
3. 이제 board의 값들을 아래로 내리는 과정을 거친다.
4. 이 과정을 반복하다 explode 벡터에 원소가 없으면 '.'의 개수를 세서 리턴한다.

*/

int dx[3] = {1, 0, 1}, dy[3] = {0, 1, 1};
vector<pair<int, int> > explode;
int solution(int m, int n, vector<string> board) {
    int answer = 0;

    while (true) {
        for (int i = 0; i < m - 1; i++) {
            for (int j = 0; j < n - 1; j++) {
                bool isErase = true;
                if (board[i][j] == '.') continue;
                for (int k = 0; k < 3; k++) {
                    int nx = i + dx[k];
                    int ny = j + dy[k];
                    if (board[i][j] != board[nx][ny]) {
                        isErase = false;
                        break;
                    }
                }
                if (isErase) {
                    explode.push_back({i, j});
                }
            }
        }
        if (explode.size() == 0) break;  // 터뜨릴게 없으면 끝
        // 터뜨리기
        for (int i = 0; i < explode.size(); i++) {
            int nowx = explode[i].first;
            int nowy = explode[i].second;
            board[nowx][nowy] = '.';
            for (int j = 0; j < 3; j++) {
                board[nowx + dx[j]][nowy + dy[j]] = '.';
            }
        }
        explode.clear();

        //내리기
        for (int j = 0; j < n; j++) {
            for (int i = m - 1; i > 0; i--) {
                if (board[i][j] == '.') {
                    for (int k = i - 1; k >= 0; k--) {
                        if (board[k][j] != '.') {
                            board[i][j] = board[k][j];
                            board[k][j] = '.';
                            break;
                        }
                    }
                }
            }
        }
    }
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (board[i][j] == '.') answer++;
        }
    }

    return answer;
}
