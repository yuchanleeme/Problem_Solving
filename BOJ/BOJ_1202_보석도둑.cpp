#include <bits/stdc++.h>
using namespace std;
//https://acmicpc.net/problem/1202

/*
<보석 도둑>
주요: 우선순위 큐
1. 먼저 가방의 무게를 기준으로 정렬한다.
2. 이제 보석도 무게를 기준으로 정렬한다.
3. 가방을 무게가 작은 순 부터 조사하한다.
  3-1. 우선순위 큐 하나를 만들어 가방의 무게보다 작거나 같은 모든 보석을 큐에 넣는다.
  3-2. 이제 우선순위 큐에서 가장 큰 가치의 값을 가지는 값을 가방에 넣고 그 수를 더한다.
  3-3. 계속 반복한다.
4. 최종 답을 출력한다.
===========
* 가방도 무게가 작은 순, 보석도 무게가 작은 순으로 조사하는게 포인트다.
* 우선순위 큐를 하나 만들어 관리하는 방법을 숙지하자.  

*/

int N, K;
long long res;
vector<pair<int, int> > jewerly;
vector<int> bag;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> K;
    for (int i = 0; i < N; i++) {
        int m, v;
        cin >> m >> v;
        jewerly.push_back({m, v});  // 무게, 가치 순
    }

    for (int i = 0; i < K; i++) {
        int c;
        cin >> c;
        bag.push_back(c);
    }
    // 가방 무게 정렬
    sort(bag.begin(), bag.end());
    sort(jewerly.begin(), jewerly.end());

    priority_queue<int> que;

    int j_idx = 0;
    for (int i = 0; i < K; i++) {
        int cur_bagWeight = bag[i];

        // 이 가방 무게보다 작은 무게의 보석 우선순위 큐 삽입
        while (j_idx < N && jewerly[j_idx].first <= cur_bagWeight) {
            que.push(jewerly[j_idx].second);
            j_idx++;
        }
        if (!que.empty()) {
            res += que.top();
            que.pop();
        }
    }
    cout << res;

    return 0;
}