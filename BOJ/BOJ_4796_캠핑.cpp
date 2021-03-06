#include <bits/stdc++.h>
using namespace std;
//www.acimpc.net/problem/4796

/*
<캠핑>
주요: 수학
1. P일을 기준으로 나눈다.
2. P일은 최대 L일만 사용할 수 있으니까 L을 V에서 P로 나눈 몫 만큼 곱해준다.
3. 이제 나머지 일자를 비교하면서 최대 사용할 수 있는 날짜를 계산하여 각 케이스별로 출력한다.

*/

int main() {
    int TC = 1;
    while (true) {
        int L, P, V;
        scanf("%d %d %d", &L, &P, &V);
        if (L == 0 && P == 0 && V == 0) break;

        int res = (V / P) * L;
        if (V % P > L)
            res += L;
        else
            res += V % P;

        printf("Case %d: %d\n", TC, res);
        TC++;
    }

    return 0;
}