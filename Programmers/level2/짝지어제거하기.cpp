#include <bits/stdc++.h>
using namespace std;
//https://programmers.co.kr/learn/courses/30/lessons/12973

/*
<짝지어 제거하기>
주요: 스택
1. 스택에 값을 하나씩 넣고 만약 top 값과 같다면 pop을 해준다.
2. 모든 작업을 끝내고 스택이 비어있으면 다 지워진것이므로 1을 리턴, 아니면 0을 리턴한다.

*/

int solution(string s) {
    stack<char> stk;

    stk.push(s[0]);
    for (int i = 1; i < s.length(); i++) {
        if (stk.size() != 0) {
            if (stk.top() == s[i])
                stk.pop();
            else
                stk.push(s[i]);
        } else {
            stk.push(s[i]);
        }
    }

    if (stk.size() == 0)
        return 1;
    else
        return 0;
}