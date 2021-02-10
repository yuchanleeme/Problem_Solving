#include <bits/stdc++.h>
using namespace std;
//https://programmers.co.kr/learn/courses/30/lessons/12981

/*
<영어 끝말잇기>
주요: map
1. 먼저 끝말이 이어지는지 확인한다.
2. 중복으로 나오지는 않았는지 검사한다.
3. 각 결과를 출력한다.

*/

unordered_map<string, int> mp;
vector<int> solution(int n, vector<string> words) {
    vector<int> answer;

    for (int i = 0; i < words.size(); i++) {
        // 자리 검사
        if (i != 0) {
            if (words[i - 1].back() != words[i][0]) {
                answer.push_back(i % n + 1);
                answer.push_back(i / n + 1);
                return answer;
            }
        }

        // 중복 검사
        if (mp[words[i]] == 0) {
            mp[words[i]]++;
        } else {
            answer.push_back(i % n + 1);
            answer.push_back(i / n + 1);
            return answer;
        }
    }

    answer.push_back(0);
    answer.push_back(0);
    return answer;
}
