#include <bits/stdc++.h>
using namespace std;
// https://programmers.co.kr/learn/courses/30/lessons/42890

/*
<후보키>
주요: DFS, set
1. DFS를 통해 모든 속성들의 조합을 찾는다.
2. 찾은 조합들로 후보키를 찾는다. (set)
3. 단, 조합을 찾을 때 해당 조합 안에 기존 후보키들이 있다면 그 조합은 제외하고 진행한다.
4. 조합을 찾을때 answer을 ++ 로 해주고 해당 값을 리턴한다.

*/

int answer;
vector<int> seq;
vector<vector<int>> cc;

// 후보키 찾기
void isPossible(vector<vector<string>> &relation) {
    set<vector<string>> x;
    // 각 조합에 해당하는 튜플들을 temp에 넣는다.
    for (int i = 0; i < relation.size(); i++) {
        vector<string> temp;
        for (int j = 0; j < seq.size(); j++) {
            temp.push_back(relation[i][seq[j]]);
        }
        x.insert(temp);  // 다 만들면 그 벡터 자체를 넣는다.
    }

    // 만약 set의 사이즈와 새로 만든 x의 size가 같다면 중복 없으므로 해당함
    if (x.size() == relation.size()) {
        answer++;
        cc.push_back(seq);
    }
}

void backtracking(int target, int level, int num, vector<vector<string>> &relation) {
    // 조합의 원소 개수마다 처리
    if (level == target) {
        // 기존 조합이 새로 만든 조합 안에 모두 한번에 포함되어 있는지 확인
        for (int i = 0; i < cc.size(); i++) {
            bool checkList = true;
            for (int j = 0; j < cc[i].size(); j++) {
                if (find(seq.begin(), seq.end(), cc[i][j]) == seq.end()) {
                    checkList = false;
                    break;
                }
            }
            if (checkList) return;  // 하나라도 있다면 리턴
        }

        isPossible(relation);
        return;
    }

    // 조합 만들기
    for (int i = num; i < relation[0].size(); i++) {
        seq.push_back(i);
        backtracking(target, level + 1, i + 1, relation);
        seq.pop_back();
    }
}

int solution(vector<vector<string>> relation) {
    for (int tc = 1; tc <= relation[0].size(); tc++) {
        backtracking(tc, 0, 0, relation);
    }
    return answer;
}