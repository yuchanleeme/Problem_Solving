#include <bits/stdc++.h>
using namespace std;
//https://programmers.co.kr/learn/courses/30/lessons/49191

/*
<순위>
주요: 플로이드 워셜 
1. 우선 플로이드 워셜 알고리즘으로 각 노드까지의 경로값이 존재하는지 전부 조사한다.
2. 이제 각각의 노드가 다른 노드 몇개까지 연결이 가능한지 판단한다.
  => 각각의 노드에서 이동을 통해 갈 수 있는 다른 노드들의 개수가 몇개인지
3. 이제 이 값들을 벡터에 넣고 정렬한다.
4. 정렬한 값을 작은값 부터 조사하면서 그 값이 자신의 idx와 일치함과 동시에 벡터내에서 유일한지 판단한다.
  => 정렬된 벡터의 값은 꼴등 부터 1등까지로 추측이 되는 선수가 이긴 횟수를 추측한것이다.
  => 예를 들어 n : 5, idx: 2인 벡터의 값이 2이라 하면 5명인 선수 중 3등을 한 선수로 추측되는 선수가 2명보다 우위에 있다 라는 뜻
  => 따라서 idx와 일치함과 동시에 벡터 안에서 유일하다면 그 값은 참이 되는 것이다.
5. 그런 값들만 세서 리턴한다.

*/
const int INF = 110;
vector<vector<int>> graph(110, vector<int>(110, INF));
vector<vector<int>> res(110, vector<int>(110, INF));

int solution(int n, vector<vector<int>> results) {
    for (int i = 1; i <= n; i++) {
        graph[i][i] = 0;
        res[i][i] = 0;
    }

    for (auto result : results) {
        graph[result[0]][result[1]] = 1;
        res[result[0]][result[1]] = 1;
    }

    // 플로이드 워셜
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            for (int k = 1; k <= n; k++) {
                if (res[j][i] + res[i][k] < res[j][k]) {
                    res[j][k] = res[j][i] + res[i][k];
                }
            }
        }
    }

    // 2번
    vector<int> ans;
    for (int i = 1; i <= n; i++) {
        int cnt = 0;
        for (int j = 1; j <= n; j++) {
            if (i == j) continue;
            if (res[i][j] != INF) cnt++;
        }
        ans.push_back(cnt);
    }
    sort(ans.begin(), ans.end());  // 3번

    // 4,5번
    int answer = 0;
    for (int i = 0; i < n; i++) {
        if (ans[i] == i) {
            if (i != n - 1) {
                if (ans[i] != ans[i + 1]) answer++;
            } else {
                answer++;
            }
        }
    }
    return answer;
}
