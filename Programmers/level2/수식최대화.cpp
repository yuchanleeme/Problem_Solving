#include <bits/stdc++.h>
using namespace std;
// https://programmers.co.kr/learn/courses/30/lessons/67257

/*
<수식 최대화>
주요: 구현, 스택
1. (+,-,*)의 우선순위를 정한다.
2. tok과 op에 숫자와 연산자를 분리해서 넣는다.
3. op를 연산자 우선순위에 맞게 큰 순서 부터 계산을 시작한다.
4. 값 두개를 계산해 다시 집어넣고, 계산했던 숫자와 연산자를 제거한다.
5. 모든 과정을 마치고 tok에 남은 숫자가 정답이다.
6. 6가지 우선순위 조합에 따라 절댓값이 가장 큰 값을 출력한다. 
==========
* 후위 연산식을 만들어 풀다가 실패했다. (한번 다시 시도 해보자.)

*/

unordered_map<char, int> mp;  // 우선순위
long long answer = 0;

void cal(string exp) {
    //token
    string temp = "";
    vector<long long> tok;
    vector<char> op;

    for (int i = 0; i < exp.length(); i++) {
        if (exp[i] == '+' || exp[i] == '-' || exp[i] == '*') {
            tok.push_back(stoll(temp));
            temp = "";
            op.push_back(exp[i]);
        } else {
            temp += exp[i];
        }
    }
    tok.push_back(stoll(temp));

    for (int i = 2; i >= 0; i--) {
        for (int j = 0; j < op.size(); j++) {
            if (mp[op[j]] == i) {
                long long x = tok[j];
                long long y = tok[j + 1];
                if (op[j] == '+') {
                    tok[j] = x + y;
                } else if (op[j] == '-') {
                    tok[j] = x - y;
                } else if (op[j] == '*') {
                    tok[j] = x * y;
                }
                tok.erase(tok.begin() + (j + 1));
                op.erase(op.begin() + j);
                j = -1;  // 다시 시작하기 위해 초기화
            }
        }
    }
    answer = max(answer, abs(tok[0]));
}

long long solution(string expression) {
    for (int a = 0; a < 3; a++) {
        mp['+'] = a;
        for (int b = 0; b < 3; b++) {
            mp['-'] = b;
            if (b == a) continue;
            for (int c = 0; c < 3; c++) {
                if (a == c || b == c) continue;
                mp['*'] = c;
                cal(expression);
            }
        }
    }

    return answer;
}
