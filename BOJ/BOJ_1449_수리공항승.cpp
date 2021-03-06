#include <bits/stdc++.h>
using namespace std;
//www.acimpc.net/problem/1449

/*
<수리공 항승>
주요: 정렬, 그리디
1. 입력받은 값들을 정렬한다.
2. 이제 앞에서 부터 테이프를 붙이고 테이프를 붙인 결과를 갱신해준다.(check)
3. 최소로 붙인 테이프 수를 출력한다.

*/

int N, L, answer;
int check[1010];
vector<int> seq;

int main() {
    cin >> N >> L;
    for (int i = 0; i < N; i++) {
        int loc;
        cin >> loc;
        seq.push_back(loc);
    }

    sort(seq.begin(), seq.end());

    for (int i = 0; i < N; i++) {
        int loc = seq[i];
        if (check[loc] == 1) continue;
        for (int i = loc; i < loc + L; i++) {
            if (i > 1000) break;
            check[i] = 1;
        }
        answer++;
    }

    cout << answer;

    return 0;
}