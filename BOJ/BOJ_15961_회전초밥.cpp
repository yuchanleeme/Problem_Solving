#include <bits/stdc++.h>
using namespace std;
// https://acmicpc.net/problem/15961

/*
<회전 초밥>
주요: 투 포인터
1. 먹었는지를 체크하는 배열을 만든다.
2. 처음 K개를 조사한다.
3. 이제 시작 idx, 끝 idx를 지정하여 회전초밥의 경우의 수를 조사한다.
  3-1. 회전 초밥이므로 끝 idx가 N을 넘어가면 0부터로 만들어준다. (나머지 이용)
  3-2. 우선, K개중 처음 초밥을 먹은 종류를 빼준다. (st)
      => 뺐는데 st의 eatCheck배열값이 0 이면, 겹치는 초밥이 없는것이므로 -1 해준다. 
  3-3. 이제, K개의 다음 위치인 ed번째 초밥의 종류를 더해준다.
      => 더했는데 ed의 eatCheck배열값이 1이면, 처음 먹는것이므로 +1 해준다.
  3-4. 쿠폰을 사용하는 경우의 수도 생각해준다.
4. 모든 조사가 끝났을 때의 최대결과값을 출력한다.
==========
* 회전 초밥이므로 idx가 처음부터 다시 시작되는 점을 주의하자.

*/

int N, d, k, c, st, ed, ans;
vector<int> seq;
int eatCheck[3010];

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    cin >> N >> d >> k >> c;
    for (int i = 0; i < N; i++) {
        int temp;
        cin >> temp;
        seq.push_back(temp);
    }

    //초기
    for (int i = 0; i < k; i++) {
        eatCheck[seq[i]]++;
        if (eatCheck[seq[i]] == 1) {
            ans++;
        }
    }
    if (eatCheck[c] == 0) {
        ans++;
    }

    // 이제 조사
    int res = ans;
    for (ed = k; st < N; st++, ed++) {
        ed %= N;  // 회전 초밥이니까
        if (eatCheck[c] == 0) {
            res--;
        }

        eatCheck[seq[st]]--;
        if (eatCheck[seq[st]] == 0) res--;

        eatCheck[seq[ed]]++;
        if (eatCheck[seq[ed]] == 1) res++;

        // 쿠폰 여부
        if (eatCheck[c] == 0) {
            res++;
        }
        ans = max(ans, res);
    }
    cout << ans;
    return 0;
}