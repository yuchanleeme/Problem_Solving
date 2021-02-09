#include <bits/stdc++.h>
using namespace std;
//hhttps://programmers.co.kr/learn/courses/30/lessons/70129

/*
<이진 변환 반복하기>
주요: 구현, 문자열
1. 0을 제거한다.
2. 2진수로 만든다. (reverse를 쓴다.)
3. 1을 만들면 해당 결과값을 리턴한다.

*/

vector<int> solution(string s) {
    vector<int> answer;
    int cnt = 0, zero = 0;
    while (true) {
        string temp = "";
        cnt++;
        for (int i = 0; i < s.length(); i++)
            if (s[i] == '1') temp += '1';
        zero += (s.length() - temp.length());
        if (temp == "1") break;

        int num = temp.length();
        s.clear();
        while (num != 0) {
            s += to_string(num % 2);
            num /= 2;
        }
        reverse(s.begin(), s.end());
    }
    answer.push_back(cnt);
    answer.push_back(zero);
    return answer;
}
