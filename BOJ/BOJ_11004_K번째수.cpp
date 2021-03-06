#include <bits/stdc++.h>
using namespace std;
//www.acimpc.net/problem/11004

/*
<K번째 수>
주요: 정렬
1. 입력 받은 수들을 정렬한다.
2. 정렬한 뒤 K번째 수를 출력한다.
==========
* 입출력 코드를 써줘야 한다.

*/

vector<int> seq;
int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    int N, K;
    cin >> N >> K;
    for (int i = 0; i < N; i++) {
        int temp;
        cin >> temp;
        seq.push_back(temp);
    }
    sort(seq.begin(), seq.end());
    cout << seq[K - 1];

    return 0;
}