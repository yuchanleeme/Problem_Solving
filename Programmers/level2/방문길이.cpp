#include <bits/stdc++.h>
using namespace std;
//https://programmers.co.kr/learn/courses/30/lessons/49994

/*
<방문 길이>
주요: 구현
1. 4차원 배열을 활용해 지나갔던 길인지 판단한다.
  ex) [1][2][1][3] = true : (1,2) 에서 (1,3)으로 이동한 적이 있다.
2. 모든 입력값을 수행하면서 위 1번에 해당하는 값이 false 일때만 answer++를 해준다.
3. 최종 answer를 출력한다.

*/

int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
bool visitCheck[13][13][13][13];

int decideIdx(char a) {
    if (a == 'L')
        return 0;
    else if (a == 'U')
        return 1;
    else if (a == 'R')
        return 2;
    else
        return 3;
}

int solution(string dirs) {
    int answer = 0;

    int x = 5, y = 5;
    for (int i = 0; i < dirs.length(); i++) {
        int idx = decideIdx(dirs[i]);
        int nx = x + dx[idx];
        int ny = y + dy[idx];
        if (nx < 0 || ny < 0 || nx > 10 || ny > 10) continue;
        if (visitCheck[x][y][nx][ny] == false && visitCheck[nx][ny][x][y] == false) answer++;
        visitCheck[x][y][nx][ny] = true;
        visitCheck[nx][ny][x][y] = true;
        x = nx;
        y = ny;
    }

    return answer;
}

int main() {
    cout << solution("LULLLLLLU");
    return 0;
}