#include <bits/stdc++.h>
using namespace std;
//www.acimpc.net/problem/11000

/*
<강의실 배정>
주요: 그리디
1. 강의시간을 입력받고 시작시간이 빠르고, 끝나는 시간도 빠른 순으로 정렬한다.
2. 이제 끝나는 시간을 기준으로 우선순위큐를 통해 정렬한다.
3. 만약 강의실(큐)의 가장 빨리 끝나는 시간이 조사하는 강의의 시작시간보다 느리다면 새로운 강의실을 예약해야 하므로 큐에 추가한다.
4. 이렇게 계속 큐의 크기를 비교해 값을 찾는다.
==========
* 하나씩 찾는 느낌으로 했더니 시간 초과에 걸렸다.

*/

priority_queue<int, vector<int>, greater<int> > que;
vector<pair<int, int> > seq;
int answer;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        int st, ed;
        cin >> st >> ed;
        seq.push_back({st, ed});
    }

    sort(seq.begin(), seq.end());

    que.push(seq[0].second);

    for (int i = 1; i < N; i++) {
        int st = seq[i].first;
        int ed = seq[i].second;

        int time = que.top();
        if (time > st) {
            que.push(ed);
        } else {
            que.pop();
            que.push(ed);
        }
        answer = max(answer, (int)que.size());
    }
    cout << answer;

    return 0;
}