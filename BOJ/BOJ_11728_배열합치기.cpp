#include <bits/stdc++.h>
using namespace std;
//https://acmicpc.net/problem/11728

/*
<배열 합치기>
주요: 투 포인터
1. A의 idx와 B의 idx를 따로 두어 A, B 배열을 C 배열로 모아 넣는다.
2. 비교가 다 끝나면 반대편 배열의 남은 값을 C 배열에 다 넣는다.
3. C를 출력한다.
==========
* N+M 으로 받아서 정렬써도 되지만 투포인터 연습겸 투포인터로 풀었다.

*/

int N, M, Aidx, Bidx;
vector<int> A, B, C;
int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        int temp;
        cin >> temp;
        A.push_back(temp);
    }

    for (int i = 0; i < M; i++) {
        int temp;
        cin >> temp;
        B.push_back(temp);
    }

    int cnt = N + M;
    while (cnt--) {
        if (Aidx == N || Bidx == M) {
            if (Aidx == N) {
                for (int i = Bidx; i < M; i++) {
                    C.push_back(B[i]);
                }
            } else {
                for (int i = Aidx; i < N; i++) {
                    C.push_back(A[i]);
                }
            }
            break;
        }
        if (A[Aidx] < B[Bidx]) {
            C.push_back(A[Aidx++]);
        } else {
            C.push_back(B[Bidx++]);
        }
    }

    for (auto item : C) {
        cout << item << " ";
    }

    return 0;
}