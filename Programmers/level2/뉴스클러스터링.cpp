#include <bits/stdc++.h>
using namespace std;
//https://programmers.co.kr/learn/courses/30/lessons/17677

/*
<뉴스 클러스터링>
주요: 투포인터
1. 각 str1, str2를 temp1, temp2로 2알파벳씩 분류 한다.
2. idx1, idx2 를 활용해 교집합의 개수를 찾는다.
3. 최종 결과에 맞게 답을 리턴한다.
==========
* 26*26 조합을 아예 다 만들어서 하는 방법도 있다.

*/

vector<string> temp1, temp2;
int solution(string str1, string str2) {
    for (int i = 0; i < str1.length() - 1; i++) {
        str1[i] = tolower(str1[i]);
        if (str1[i] >= 'a' && str1[i] <= 'z') {
            str1[i + 1] = tolower(str1[i + 1]);
            if (str1[i + 1] >= 'a' && str1[i + 1] <= 'z') {
                temp1.push_back((str1.substr(i, 2)));
            }
        }
    }
    for (int i = 0; i < str2.length() - 1; i++) {
        str2[i] = tolower(str2[i]);
        if (str2[i] >= 'a' && str2[i] <= 'z') {
            str2[i + 1] = tolower(str2[i + 1]);
            if (str2[i + 1] >= 'a' && str2[i + 1] <= 'z') {
                temp2.push_back((str2.substr(i, 2)));
            }
        }
    }
    // 정렬
    sort(temp1.begin(), temp1.end());
    sort(temp2.begin(), temp2.end());
    int idx1 = 0, idx2 = 0, check = 0;

    while (true) {
        if (idx1 == temp1.size() || idx2 == temp2.size()) break;
        if (temp1[idx1] == temp2[idx2]) {
            idx1++;
            idx2++;
            check++;
        } else if (temp1[idx1] > temp2[idx2]) {
            idx2++;
        } else if (temp1[idx1] < temp2[idx2]) {
            idx1++;
        }
    }

    int total = (temp1.size() + temp2.size()) - check;
    if (total == 0 && check == 0) return 65536;
    if (check == 0) return 0;

    return check * 65536 / total;
}
