#include <bits/stdc++.h>
using namespace std;
//https://programmers.co.kr/learn/courses/30/lessons/17687

/*
<n진수 게임>
주요: 진법
1. 우선 대략적으로 100000 까지의 숫자를 각 진법으로 표현한 res 문자열을 만든다.
2. idx를 처음부터 설정해 해당 하는 위치의 값만 answer에 붙여준다.
3. 최종적으로 answer를 리턴한다.

*/

string solution(int n, int t, int m, int p) {
    string answer = "";
    string res = "0";
    for (int i = 0; i < 100000; i++) {
        int tempnum = i;
        string tempstr = "";
        while (tempnum != 0) {
            int pp = tempnum % n;
            if (pp == 10)
                tempstr += "A";
            else if (pp == 11)
                tempstr += "B";
            else if (pp == 12)
                tempstr += "C";
            else if (pp == 13)
                tempstr += "D";
            else if (pp == 14)
                tempstr += "E";
            else if (pp == 15)
                tempstr += "F";
            else
                tempstr += to_string(pp);
            tempnum /= n;
        }
        reverse(tempstr.begin(), tempstr.end());
        res += tempstr;
    }

    int idx = p - 1;
    while (answer.length() != t) {
        answer += res[idx];
        idx += m;
    }

    return answer;
}