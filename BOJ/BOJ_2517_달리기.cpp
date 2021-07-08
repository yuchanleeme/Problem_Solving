#include <bits/stdc++.h>
using namespace std;
//https://acmicpc.net/problem/

/*
<달리기>
주요: 구간 트리
1. 입력받은 선수의 능력을 순서와 함께 벡터에 넣는다.
2. 먼저, 능력(power)을 기준으로 정렬을 하고 power를 다시 라벨링한다.
3. 이제 다시 입력받은 순서대로 정렬을 한다.
4. 이제 구간 트리를 이용해 입력받은 값을 기준으로 트리에서 해당 구간에서 나보다 능력이 약한 사람의 수를 센다.
    4-0. seg_sum(int node, int s, int e, int l, int r)
    4-1. node: 노드의 고유 인덱스 번호
    4-2. s, e: 해당 노드가 나타내는 범위
    4-3. l, r: 내가 조사하고 싶은 power의 범위
5. 이렇게 결과값을 찾았으면, 이제 Update를 해준다.
    5-0. update(int node, int s, int e, int idx, int v)
    5-1. node, s, e는 위와 동일
    5-2. idx: 내가 업데이트 할 power 값
    5-3. 여기서 v는 구간[idx~idx] = 1로 설정하기 위함
6. 최종결과를 출력한다.
==========
* 구간 트리 문제이다.
    -> 현재 update에서 v = 1이지만 조건에 따라 이 값은 변경이 가능하다.
* 세그먼트 트리 관련 문제를 더 풀어보자.
* 좌표 압축을 해야한다.

*/

typedef struct Info {
    int order;
    int pow;
} Info;

int N;
vector<Info> player;
int tr[1 << 20];

int seg_sum(int node, int s, int e, int l, int r) {
    if (r < s || e < l) return 0;
    if (l <= s && e <= r) {
        return tr[node];
    } else {
        return seg_sum(node * 2, s, (s + e) / 2, l, r) + seg_sum(node * 2 + 1, (s + e) / 2 + 1, e, l, r);
    }
}

void update(int node, int s, int e, int idx, int v) {
    if (idx < s || e < idx) return;
    if (s == e) {
        tr[node] = v;
    } else {
        update(node * 2, s, (s + e) / 2, idx, v);
        update(node * 2 + 1, (s + e) / 2 + 1, e, idx, v);
        tr[node] = tr[node * 2] + tr[node * 2 + 1];
    }
}

bool compP(Info &A, Info &B) {
    return A.pow < B.pow;
}

bool compO(Info &A, Info &B) {
    return A.order < B.order;
}

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        int pow;
        cin >> pow;
        player.push_back({i, pow});
    }
    sort(player.begin(), player.end(), compP);

    //re-labelling
    int num = 0;
    for (int i = 0; i < N; i++) {
        player[i].pow = i + 1;
    }
    // 순서대로 정렬
    sort(player.begin(), player.end(), compO);

    for (int i = 0; i < N; i++) {
        int curpower = player[i].pow;
        int cnt = 0;
        if (curpower > 1) {
            cnt = seg_sum(1, 1, N, 1, curpower - 1);
        }
        update(1, 1, N, curpower, 1);
        cout << i + 1 - cnt << "\n";
    }

    return 0;
}