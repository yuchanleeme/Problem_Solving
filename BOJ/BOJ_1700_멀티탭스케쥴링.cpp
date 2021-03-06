#include <bits/stdc++.h>
using namespace std;
//www.acimpc.net/problem/1700

/*
<멀티탭 스케쥴링>
주요: 그리디
1. 일단 꽂혀져 있는지 먼저 확인한다.
2. 만약 꽂혀져 있지 않을 때,
    2-1. 빈 콘센트가 있다면 거기에 꽂는다.
    2-2. 꽂을데가 없으면 가장 나중에 사용할 전자기기가 꽂혀있는 콘센트를 뺀다.
3. 큐를 활용해 위치를 계속 갱신해준다.
==========
* 앞으로 가장 적게 사용하는 횟수를 기준으로 잡으면 안 된다.

*/

int N, K, answer;
int socket[110];
vector<int> electro;
unordered_map<int, queue<int>> mp;

int main() {
    cin >> N >> K;
    for (int i = 0; i < K; i++) {
        int temp;
        cin >> temp;
        electro.push_back(temp);
        mp[temp].push(i);
    }

    // 1번
    for (int i = 0; i < K; i++) {
        bool isUsed = false;
        for (int j = 0; j < N; j++) {
            if (socket[j] == electro[i]) {
                isUsed = true;
                mp[electro[i]].pop();
                break;
            }
        }

        // 2번
        if (isUsed == false) {
            // 2-1. 만약 빈 콘센트가 있으면 꽂는다.
            for (int j = 0; j < N; j++) {
                if (socket[j] == 0) {
                    socket[j] = electro[i];
                    mp[electro[i]].pop();
                    isUsed = true;
                    break;
                }
            }
            if (isUsed) continue;

            // 2-2. 꽂을데가 없으면 비교해본다.
            int changed = 0;
            for (int j = 0; j < N; j++) {
                if (mp[socket[j]].empty()) {
                    changed = j;
                    break;
                } else {
                    if (mp[socket[changed]].front() < mp[socket[j]].front()) {
                        changed = j;
                    }
                }
            }
            socket[changed] = electro[i];
            mp[electro[i]].pop();
            answer++;
        }
    }
    cout << answer;

    return 0;
}