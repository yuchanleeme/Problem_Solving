#include <bits/stdc++.h>
using namespace std;
//https://programmers.co.kr/learn/courses/30/lessons/42888

/*
<오픈채팅방>
주요: map
1. 먼저 record에서 닉네임 변동여부를 한번 싹 결정해 map에 저장한다.
2. 그 다음 다시 record를 훑으면서 바뀐 닉네임에 따라 결과를 저장해 리턴한다.
*/

unordered_map<string, string> mp;
vector<string> solution(vector<string> record) {
    vector<string> answer;

    // 닉네임 결정
    string info, uid, name;
    for (int i = 0; i < record.size(); i++) {
        stringstream ss;
        ss.str(record[i]);
        ss >> info >> uid;
        if (info == "Enter" || info == "Change") {
            ss >> name;
            mp[uid] = name;
        }
    }
    // 닉네임 출력
    for (int i = 0; i < record.size(); i++) {
        stringstream ss;
        string info, uid, name;
        ss.str(record[i]);
        ss >> info >> uid;
        if (info == "Enter") {
            answer.push_back(mp[uid] + "님이 들어왔습니다.");
        } else if (info == "Leave") {
            answer.push_back(mp[uid] + "님이 나갔습니다.");
        }
    }

    return answer;
}