#include <bits/stdc++.h>
using namespace std;
//https://acmicpc.net/problem/9935

/*
<문자열 폭발>
주요: 스택
1. 스택에 문자열을 넣다가 폭탄의 끝문자가 나오면 조사한다.
2. 새롭게 temp라는 스택을 만들고 이제 기존 문자열에서 하나씩 빼서 넣는다.
3. 하나식 빼면서 폭탄 문자열이 맞는지 확인한다.
4. 폭탄 문자열이면 폭탄처리를 하고, 아니라면 temp 스택에 들어있는 값들로 원상복구 시킨다.
5. 최종으로 문자열 길이를 기준으로 FRULA이나 해당 문자열을 출력한다.

*/

string str, bomb;
stack<char> stk;

int main() {
    cin >> str >> bomb;

    for (int i = 0; i < str.length(); i++) {
        if (str[i] == bomb.back()) {
            int idx = bomb.length() - 2;
            stack<char> temp;
            while (idx >= 0) {
                if (!stk.empty() && (stk.top() == bomb[idx])) {
                    temp.push(stk.top());
                    stk.pop();
                } else {
                    while (!temp.empty()) {
                        stk.push(temp.top());
                        temp.pop();
                    }
                    stk.push(str[i]);
                    break;
                }
                idx--;
            }
        } else
            stk.push(str[i]);
    }

    string ans = "";
    while (!stk.empty()) {
        ans += stk.top();
        stk.pop();
    }

    if (ans.length() == 0)
        cout << "FRULA";
    else {
        reverse(ans.begin(), ans.end());
        cout << ans;
    }
    return 0;
}