#include <bits/stdc++.h>
using namespace std;
//https://programmers.co.kr/learn/courses/30/lessons/43164

/*
<여행 경로>
주요: DFS, 정렬
1. 각 항공마다 idx를 부여해 그에 관한 인접 그래프를 만든다.
2. 이제 경로를 찾는데 이때 중복 여부는 티켓의 번호로 따진다.
3. 티켓들을 모두 썼다고 판단 되면 각 경로를 ans 벡터에 넣는다.
4. 이제 ans 벡터를 조건에 맞게 정렬하고 그 중 사전순인 ans[0]을 리턴한다.

*/

vector<pair<int, int> > graph[10101]; // first : 공항 idx, second: 티켓 번호
unordered_map<string, int> mp; // 공항 idx
int useTicket[10101];
vector<int> seq; // 티켓들 저장
vector<vector<string> > ans;

// 정렬
bool comp(const vector<string> &A, const vector<string> &B){

  for (int i = 0; i < A.size(); i++) {
    if(A[i] != B[i]) return A < B;
  }
}

// dfs
void dfs(int level, int start, vector<vector<string>> &tickets){

  if(level == tickets.size()){
    vector<string> res; // 각 경로 값을 저장한다.
    for (int i = 0; i < seq.size(); i++) {
      res.push_back(tickets[seq[i]][0]);
    }
    res.push_back(tickets[seq.back()][1]);
    ans.push_back(res);
    return;
  }

  for (int i = 0; i < graph[start].size(); i++) {
    int next = graph[start][i].first;
    int tckt = graph[start][i].second;

    if(useTicket[tckt] == 1) continue;
    useTicket[tckt] = 1;
    seq.push_back(tckt);
    dfs(level+1, next, tickets);
    seq.pop_back();
    useTicket[tckt] = 0;

  }
}

vector<string> solution(vector<vector<string>> tickets) {
  vector<string> answer;
  int idx = 0;

  // 각 항공마다 idx부여 및 인접 그래프 만들기
  for (int i = 0; i < tickets.size(); i++) {
    if(mp[tickets[i][0]] == 0) mp[tickets[i][0]] = ++idx;
    if(mp[tickets[i][1]] == 0) mp[tickets[i][1]] = ++idx;
    pair<int, int> pi = make_pair(mp[tickets[i][1]], i);
    graph[mp[tickets[i][0]]].push_back(pi);
  }

  // 인천공항에서 시작하는 경로 만들기
  for (int i = 0; i < tickets.size(); i++) {
    if(tickets[i][0] != "ICN") continue;
    seq.push_back(i);
    useTicket[i] = 1;
    dfs(1, mp[tickets[i][1]], tickets);
    useTicket[i] = 0;
    seq.pop_back();
  }

  // 경로 정렬
  sort(ans.begin(), ans.end(), comp);

  return ans[0];
}
