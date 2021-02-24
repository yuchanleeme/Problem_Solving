#include <bits/stdc++.h>
using namespace std;
//www.acimpc.net/problem/1316

/*
<그룹 단어 체커>
주요: 구현
1. 알파벳들이 등장했는지 여부를 alpha 배열을 통해 체크한다.
2. 만약 바로 이전 글자랑 같지 않는데 이미 등장한 알파벳이 있다면 조사를 중지한다.
3. 모든 길이를 조사했을 때 2번에 해당하지 않는다면 answer++를 한다.
4. 최종 answer값을 출력한다.

*/

int T, answer;

int main() {
    cin >> T;

    while (T--) {
        string temp;
        cin >> temp;
        bool alpha[27] = {
            false,
        };

        for (int i = 0; i < temp.length(); i++) {
            int check = temp[i] - 'a';
            if (alpha[check] != true)
                alpha[check] = true;
            else {
                if (temp[i - 1] != temp[i]) break;
            }
            if (i == temp.length() - 1) answer++;
        }
    }
    cout << answer;
    return 0;
}