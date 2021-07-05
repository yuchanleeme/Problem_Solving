#include <bits/stdc++.h>
using namespace std;
//https://acmicpc.net/problem/1039

/*
<교환>
주요: BFS, 방문체크
1. 해봤자 6자리이미로 그냥 BFS 탐색을 진행한다.
2. 맨 앞자리와 바꿀 자리의 숫자가 0인경우, "10" 처럼 불가능 한 경우 등 예외 처리를한다.
3. 그리고 맨 마지막 회차(K==0) 일때 최대값을 조사한다.
4. K==0일때 조사를 못했으면 불가능한 경우이므로 -1, 아니면 3번에서 조사한 최대값을 출력한다.
===========
* 계산의 편의를 위해 string으로 값을 다뤘다.

*/

string N;
int K;

int main() {
    cin >> N >> K;
    queue<string> que;
    que.push(N);

    int ans = -1;
    while (K--) {
        int temp_size = que.size();
        bool dp[1010101] = {
            0,
        };
        for (int i = 0; i < temp_size; i++) {
            string val = que.front();
            que.pop();

            for (int x = 0; x < val.length(); x++) {
                for (int y = x + 1; y < val.length(); y++) {
                    string temp = val;
                    char charTemp = temp[y];

                    // 앞자리랑 바꾸는데 0일때
                    if (x == 0 && charTemp == '0') continue;

                    // 아니면 값 바꾸기
                    temp[y] = temp[x];
                    temp[x] = charTemp;

                    int res = stoi(temp);
                    if (dp[res] == true) continue;
                    que.push(to_string(res));
                    dp[res] = true;
                    if (K == 0) {
                        ans = max(ans, res);
                    }
                }
            }
        }

        if (que.empty()) break;
    }
    cout << ans;

    return 0;
}
