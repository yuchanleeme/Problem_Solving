#include <bits/stdc++.h>
using namespace std;
//https://acmicpc.net/problem/20495

/*
<수열과 헌팅>
주요: 이분탐색
1. 우선 모든 원소의 범위의 최소(시작), 최댓값(끝)을 각각 분리해서 벡터로 만든다.
2. 분리된 벡터들을 각각 정렬한다.
3. 끝 벡터에 나의 시작값 보다 작은 값들이 몇개 있냐에 따라 인덱스의 최솟값이 결정된다.
4. 시작 벡터에 나의 끝 값보다 작거나 같은 값들이 몇개 있냐에 따라 인덱스의 최댓값이 결정된다.
5. 3,4 조건을 활용해 이분탬색을 한 뒤 값들을 찾아 출력한다.

*/

int N;
vector<int> st, ed;
vector<pair<int, int> > arr;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> N;
    for (int i = 0; i < N; i++) {
        int x, y;
        cin >> x >> y;
        st.push_back(x - y);
        ed.push_back(x + y);
        arr.push_back({x - y, x + y});
    }
    sort(st.begin(), st.end());
    sort(ed.begin(), ed.end());

    for (int i = 0; i < N; i++) {
        int start = arr[i].first;
        int end = arr[i].second;

        auto itr_st = lower_bound(ed.begin(), ed.end(), start);
        cout << itr_st - ed.begin() + 1 << " ";

        // ed는 기본적으로 나 자신보다는 뒤에 있으므로 +1 안해도 됨.
        auto itr_ed = upper_bound(st.begin(), st.end(), end);
        cout << itr_ed - st.begin() << "\n";
    }

    return 0;
}