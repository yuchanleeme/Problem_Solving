#include <bits/stdc++.h>
using namespace std;
//https://www.acmicpc.net/problem/1182

/*
<부분수열의 합>
주요: DFS
1. 백트래킹을 통해 모든 경우의 수를 찾는다.
2. 해당하는 숫자가 나오면 ans++ 해준다.
3. 최종 ans를 출력한다.

*/

int N, S, ans;
vector<int> seq;
vector<int> x;

void dfs(int level, int num, int sum){
  if(level > N) return;
  if(sum == S && level != 0) ans++;

  for (int i = num; i < N; i++) {
    dfs(level+1, i+1, sum+seq[i]);
  }
}

int main(int argc, char const *argv[]) {
  cin >> N >> S;
  for (int i = 0; i < N; i++) {
    int temp; cin >> temp;
    seq.push_back(temp);
  }
  dfs(0, 0, 0);
  cout << ans;
  return 0;
}
