#include <bits/stdc++.h>
using namespace std;
//https://programmers.co.kr/learn/courses/30/lessons/43163

/*
<단어 변환>
주요: DFS
1. 우선 words에 begin을 넣는다.
2. 이제 각 원소끼리 한글자 차이인지 조사해서 그 연결관계를 인전리스트로 만든다.
3. 이제 DFS탐색을 통해 target을 찾으면 해당 단계의 level+1과 answer를 비교한다.
4. 최종 answer를 출력한다.
==========
* max 값 설정 잘 하기

*/

vector<int> graph[52];
int visitWords[52];
int answer = 55;  // max 값

void dfs(int level, int prev, string &target, vector<string> &words) {
    for (int i = 0; i < graph[prev].size(); i++) {
        int next = graph[prev][i];
        if (visitWords[next] == 0) {
            if (words[next] == target) {
                answer = min(answer, level + 1);
                return;
            }
            visitWords[next] = 1;
            dfs(level + 1, next, target, words);
            visitWords[next] = 0;
        }
    }
}

int solution(string begin, string target, vector<string> words) {
    words.push_back(begin);  // begin의 idx는 맨마지막
    int begin_idx = words.size() - 1;

    for (int i = 0; i < words.size(); i++) {
        if (words[i].length() != begin.length()) continue;

        for (int j = i + 1; j < words.size(); j++) {
            if (words[j].length() != begin.length()) continue;

            int check = 0;
            for (int k = 0; k < begin.length(); k++) {
                if (words[i][k] == words[j][k]) check++;
            }
            if (check == begin.length() - 1) {
                graph[i].push_back(j);
                graph[j].push_back(i);
            }
        }
    }

    visitWords[begin_idx] = 1;
    dfs(0, begin_idx, target, words);

    if (answer == 55) return 0;
    return answer;
}