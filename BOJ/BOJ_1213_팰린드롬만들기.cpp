#include <bits/stdc++.h>
using namespace std;
//https://acmicpc.net/problem/1213

/*
<팰린드롬 만들기>
주요: 문자열, 구현
1. 알파벳의 개수를 센다.
2. 알파벳의 개수가 홀수개인 것의 개수에 따라 판단한다.
3. 아래 주석에 맞게 조사한다.
4. 정답을 출력한다.

*/

int alp[27];
int main() {
    string temp;
    cin >> temp;
    for (int i = 0; i < temp.length(); i++) {
        alp[temp[i] - 'A']++;  // 알파벳 개수 세기
    }

    // 홀수 개인 알파벳 세기
    int cnt = 0, odd = -1;
    for (int i = 0; i < 26; i++) {
        if (alp[i] % 2 == 1) {
            cnt++;
            odd = i;
        }
    }
    if (cnt > 1)
        return !printf("I'm Sorry Hansoo");  // 홀수개가 여러개면 팰린드롬 불가

    // 짝수개수의 알파벳 종류를 조합해 팰린드롬 반판 만들기
    string res = "";
    for (int i = 0; i < 27; i++) {
        if (alp[i] == 0)
            continue;
        else if (alp[i] % 2 == 0) {
            for (int j = 0; j < alp[i] / 2; j++) {
                res += (char)(i + 65);
            }
        }
    }

    if (cnt == 1 && res != "") {
        // 홀수개의 알파벳이 1개있고 다를 알파벳도 존재할 때
        char odd_char = (char)(odd + 65);
        for (int i = 0; i < res.length(); i++) {
            if (res[i] > odd_char) {
                string tt = "";
                for (int j = 0; j < alp[odd] / 2; j++) {
                    tt += odd_char;
                }
                res.insert(i, tt);
                break;
            } else if (i == res.length() - 1) {
                for (int j = 0; j < alp[odd] / 2; j++) {
                    res += odd_char;
                }
                break;
            }
        }
        string ans = res;
        res += odd_char;
        reverse(res.begin(), res.end());
        cout << ans + res;
    } else if (cnt == 1 && res == "") {
        // 홀수개의 알파벳 1개만 존재할 때
        char odd_char = (char)(odd + 65);
        for (int j = 0; j < alp[odd]; j++) {
            res += odd_char;
        }
        cout << res;
    } else {
        // 홀수개의 알파벳이 존재하지 않을 때
        string ans = res;
        reverse(res.begin(), res.end());
        cout << ans + res;
    }

    return 0;
}