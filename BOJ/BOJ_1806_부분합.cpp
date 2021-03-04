#include <bits/stdc++.h>
using namespace std;
//www.acimpc.net/problem/1806

/*
<부분합>
주요: 투 포인터
1. 시작과 끝 idx를 지정한다.
2. sum이 S이상이면 start idx를 한칸 뒤로 이동하고 길이를 비교한다.
3. sum이 S보다 작으면 end idx를 한칸 뒤로 이동한다.
4. 포인터를 이동할 때마다 sum을 갱신한다.
5. 최종 길이를 출력한다.
==========
* 이중 for문 작성 시 O(N^2)으로 시간초과

*/

int N, S, answer = 101010;
vector<int> seq;

int main() {
    cin >> N >> S;
    for (int i = 0; i < N; i++) {
        int temp;
        cin >> temp;
        seq.push_back(temp);
    }

    int sum = seq[0], st = 0, ed = 0;
    while (true) {
        if (sum >= S) {
            answer = min(answer, ed - st + 1);
            sum -= seq[st];
            st += 1;
        } else if (sum < S) {
            ed += 1;
            sum += seq[ed];
        }
        if (st == N || ed == N) break;
    }
    if (answer == 101010)
        cout << 0;
    else
        cout << answer;
    return 0;
}