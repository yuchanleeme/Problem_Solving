#include <bits/stdc++.h>
using namespace std;
//https://www.acmicpc.net/problem/10819

/*
<차이를 최대로>
주요: DFS
1. 순열의 idx를 조합형태로 경우의수를 구한다.
2. 해당하는 조합의 형태로 배열의 값을 가져와 식을 계산한다.
3. 그 중 최댓값을 출력한다.

*/

int N, answer = -2000;
bool check[10];
vector<int> seq;
vector<int> com;

void dfs(){
  if(com.size() == N){
    int res = 0;
    for (size_t i = 1; i < N; i++) {
      res += abs(seq[com[i-1]] - seq[com[i]]);
    }
    answer = max(answer, res);
  }

  for (size_t i = 0; i < N; i++) {
    if(check[i] == true) continue;
    else{
      check[i] = true;
      com.push_back(i);
      dfs();
      com.pop_back();
      check[i] = false;
    }
  }
}

int main(int argc, char const *argv[]) {
  cin >> N;
  for (size_t i = 0; i < N; i++) {
    int temp; cin >> temp;
    seq.push_back(temp);
  }
  dfs();
  cout << answer;
  return 0;
}
