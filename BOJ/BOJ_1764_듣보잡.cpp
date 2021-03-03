#include <bits/stdc++.h>
using namespace std;
//https://www.acmicpc.net/problem/1764

/*
<듣보잡>
주요: map
1. 듣도 못한 사람의 명단을 map을 통해 만들고 값을 1으로 지정한다.
2. 보도 못한 사람의 명단을 map을 통해 1을 증가시킨다.
3. 이제 map을 순회하면서 그 값이 2인사람을 찾아 vector에 넣는다.
4. vector을 사전순으로 정렬하고 문제의 답을 출력한다.

*/

int N, M;
unordered_map<string, int> mp;
int main(int argc, char const *argv[]) {
  cin.tie(0); ios_base::sync_with_stdio(false);
  cin >> N >> M;
  for (int i = 0; i < N; i++) {
    string temp; cin >> temp;
    mp[temp]++;
  }

  for (int i = 0; i < M; i++) {
    string temp; cin >> temp;
    mp[temp]++;
  }

  vector<string> res;
  for(auto item: mp){
    if(item.second == 2) res.push_back(item.first);
  }

  sort(res.begin(), res.end());
  cout << res.size() << "\n";
  for (string item : res){
    cout << item << "\n";
  }
  return 0;
}
