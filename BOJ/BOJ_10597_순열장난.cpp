#include <bits/stdc++.h>
using namespace std;
//www.acimpc.net/problem/10597

/*
<순열장난>
주요: 백트래킹
1. 길이 수를 이용해 N의 값을 구한다.
2. 1,2자리수의 숫자를 이용해 백트래킹을 진행하여 순열을 찾아 seq 벡터에 넣는다.
3. seq 벡터를 출력한다.

*/

bool gameEnd = false;
int maxNum;
string str;
vector<int> seq;
int check[60];

void dfs(int level, int idx) {
    if (gameEnd) return;

    if (level == maxNum) {
        gameEnd = true;
        for (size_t i = 0; i < seq.size(); i++) {
            cout << seq[i] << " ";
        }
        return;
    }

    // 1개짜리
    int nx1 = stoi(str.substr(idx, 1));
    if (nx1 >= 1 && nx1 <= maxNum && check[nx1] == 0) {
        check[nx1] = 1;
        seq.push_back(nx1);
        dfs(level + 1, idx + 1);
        seq.pop_back();
        check[nx1] = 0;
    }

    // 2개짜린
    int nx2 = stoi(str.substr(idx, 2));
    if (nx2 >= 1 && nx2 <= maxNum && check[nx2] == 0) {
        check[nx2] = 1;
        seq.push_back(nx2);
        dfs(level + 1, idx + 2);
        seq.pop_back();
        check[nx2] = 0;
    }
}

int main() {
    cin >> str;

    // 길이 수로 maxNum 찾기
    if (str.length() <= 9) {
        maxNum = str.length();
    } else {
        maxNum = 9 + (str.length() - 9) / 2;
    }

    dfs(0, 0);

    return 0;
}
