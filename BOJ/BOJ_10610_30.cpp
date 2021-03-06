#include <bits/stdc++.h>
using namespace std;
//www.acimpc.net/problem/10610

/*
<30>
주요: 수학
1. 입력받은 수를 큰 순으로 정렬한다.
2. 각 자리수를 다 더한다.
3. 그 더한 숫자가 3의배수이고 끝자리가 0인 숫자만 출력한다.
4. 아니면 -1을 출력한다.

*/

string str;

int main() {
    cin >> str;
    sort(str.rbegin(), str.rend());

    int res = 0;
    for (int i = 0; i < str.length(); i++) {
        res += str[i] - '0';
    }
    if (res % 3 == 0 && str.back() == '0')
        cout << str;
    else
        cout << -1;

    return 0;
}