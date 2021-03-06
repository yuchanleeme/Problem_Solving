#include <bits/stdc++.h>
using namespace std;
//www.acimpc.net/problem/17590

/*
<And the Winner Is... Ourselves!>
주요: 정렬, 그리디
1. 페널티는 따로 계산한다 했으므로, 일단 가장 푸는 시간이 짧은 순서로 일단 정렬한다.
2. 정렬한 순서대로 시간을 계산해서 페널티 점수에 더한다.
3. 이제 틀린 횟수에 20을 곱해서 페널티 점수에 더해서 출력한다.

*/

vector<pair<int, int> > seq;

int main() {
    int answer = 0;
    for (int i = 0; i < 11; i++) {
        int D, V;
        cin >> D >> V;
        seq.push_back({D, V});
    }

    sort(seq.begin(), seq.end());

    int time = 0;
    for (int i = 0; i < 11; i++) {
        time += seq[i].first;
        answer += time + seq[i].second * 20;
    }
    cout << answer;

    return 0;
}