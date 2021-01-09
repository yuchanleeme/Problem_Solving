#include <bits/stdc++.h>
using namespace std;
//https://www.acmicpc.net/problem/15686

/*
<치킨 배달>
주요: 순열, 브루트포스
1. 치킨집과 집의 위치를 각 벡터에 따로 저장시킨다.
2. 폐업시키지 않을 치킨집들의 idx를 seq 벡터에 저장시킨다.
3. 순열을 구하면 각 집들의 최소 치킨 거리를 구해 res 벡터에 넣는다.
4. res 벡터를 정렬하고, 가장 작은 값을 출력한다.

*/

int N, M;
vector<pair<int, int> > chicken;
vector<pair<int, int> > house;
vector<int> res;
vector<int> seq;

void backtracking(int num, int level){
  if(level == M){
    // 3번
    int sum = 0, ccheck;
    for (int i = 0; i < house.size(); i++) {
      int hx = house[i].first;
      int hy = house[i].second;
      ccheck = 200;
      for (int j = 0; j < seq.size(); j++) {
        int cx = chicken[seq[j]].first;
        int cy = chicken[seq[j]].second;
        ccheck = min(ccheck, abs(cx-hx) + abs(cy-hy));
      }
      sum += ccheck;
    }
    res.push_back(sum);
    return;
  }

  for (int i = num+1; i < chicken.size(); i++) {
    seq.push_back(i);
    backtracking(i, level+1);
    seq.pop_back();
  }
}

int main(int argc, char const *argv[]) {
  // 1번
  cin >> N >> M;
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= N; j++) {
      int temp;
      cin >> temp;
      if(temp == 1)  house.push_back({i,j});
      else if(temp == 2)  chicken.push_back({i,j});
    }
  }

  // 2번
  for (int i = 0; i < chicken.size(); i++) {
    seq.push_back(i);
    backtracking(i, 1);
    seq.pop_back();
  }

  // 4번
  sort(res.begin(), res.end());
  cout << res[0];

  return 0;
}
