#include <bits/stdc++.h>
using namespace std;
//https://programmers.co.kr/learn/courses/30/lessons/17680

/*
<캐시>
주요: 큐
1. 우선 캐시에서 해당 문자가 있는지 찾는다.
2. 캐시에 있으면 그 값을 큐의 마지막으로 빼고 answer +=1 한다.
3. 캐시가 없으면 캐시의 총 크기에 따라 캐시에 넣고 answer += 5 해준다.
4. 마지막 answer를 리턴한다.
==========
* LRU 알고리즘을 정확히 알아야 한다.

*/

queue<string> que;
int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    for (int i = 0; i < cities.size(); i++) {
        transform(cities[i].begin(), cities[i].end(), cities[i].begin(), ::tolower);

        // 캐시에서 찾기
        string cache = "";
        bool findCahce = false;
        int temp_size = que.size();
        for (int j = 0; j < temp_size; j++) {
            string target = que.front();
            if (cities[i] == target) {
                findCahce = true;
                answer += 1;
                cache = target;
            } else {
                que.push(target);
            }
            que.pop();
        }

        // 캐시 찾았으면 계속 진행
        if (findCahce) {
            que.push(cache);
            continue;
        }

        // 캐시에 넣기
        answer += 5;
        if (cacheSize == 0)
            continue;

        if (cacheSize == que.size())
            que.pop();
        que.push(cities[i]);
    }

    return answer;
}
