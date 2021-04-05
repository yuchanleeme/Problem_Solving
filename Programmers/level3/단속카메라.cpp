#include <bits/stdc++.h>
using namespace std;
//https://programmers.co.kr/learn/courses/30/lessons/42884

/*
<단속카메라>
주요: 투 포인터, 그리디
1. 우선 진입이 빠른 순, 진출이 빠른 순으로 차량의 경로를 정렬한다.
2. 시작(st)과 끝(ed)을 지정하고, 이 값을 기준으로 카메라를 세울지 안 세울지 판단한다.
  2-1. 단속카메라의 가동 범위보다 다음 자동차 경로의 진입 시간이 느리다면 새롭게 단속카메라를 단다.
  2-2. 새롭게 단속카메라를 달때, 시작(st), 끝(ed)값은 다음 경로의 진입, 진출 시점으로 바꾼다.
  2-3. 만약 단속카메라 가동 범위 안에 있다면, st, ed를 차량의 진입,진출 시점을 기반으로 최신화한다.
3. 최종 카메라 개수를 리턴한다.

*/

int solution(vector<vector<int>> routes) {
    int answer = 0;
    sort(routes.begin(), routes.end());
    int st = 300010, ed = -300010;  // 시작을 위해 값을 이렇게 초기화
    for (int i = 0; i < routes.size(); i++) {
        int nst = routes[i][0];  // 차량의 진입시점
        int ned = routes[i][1];  // 차량의 진출시점

        if (ed < nst) {
            // 새롭게 단속카메라
            answer++;
            st = nst, ed = ned;
            continue;
        } else {
            // 진입, 진출 시점을 기준으로 st, ed값 최신화
            if (st <= nst) st = nst;
            ed = min(ed, ned);
        }
    }
    return answer;
}