#include <bits/stdc++.h>
using namespace std;
//https://programmers.co.kr/learn/courses/30/lessons/42579

/*
<베스트앨범>
주요: unordered_map, stable_sort
1. 우선 곡들의 정보를 저장할 구조체를 선언한다.
2. 각 장르의 곡 수를 unodered_map에 넣으면서, 각 노래의 정보를 idx 포함해서 temp 벡터에 넣는다.
3. 조건에 맞게 temp벡터르 stable_sort한다.
4. 정렬된 temp 벡터에서 조건에 맞게 장르당 최대 2곡의 idx를 뽑아 answer 벡터에 넣고 리턴한다. 

*/

// Info 구조체
typedef struct info {
    string gen;
    int songs;
    int idx;
} Info;

unordered_map<string, int> mp;  // 장르별 노래 총 수 정보를 갖고 있는 맵

// 정렬을 위한 comp
bool comp(const Info &A, const Info &B) {
    if (A.gen == B.gen) {
        return A.songs > B.songs;
    } else {
        return mp[A.gen] > mp[B.gen];
    }
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<Info> temp;
    for (int i = 0; i < genres.size(); i++) {
        mp[genres[i]] += plays[i];  // 맵에 각 노래 수 세기
        temp.push_back({genres[i], plays[i], i});
    }

    stable_sort(temp.begin(), temp.end(), comp);  // stable_sort

    vector<int> answer;
    int cnt = 0;  // 최대 2곡 처리
    string prev_genre = "";

    for (auto info : temp) {
        if (cnt == 2 && prev_genre == info.gen) continue;  // 2곡 다 골랐는데 이전장르와 같다면 continue;
        if (prev_genre != info.gen) {                      // 현재장르 갱신
            cnt = 0;
            prev_genre = info.gen;
        }
        answer.push_back(info.idx);
        cnt++;
    }

    return answer;
}