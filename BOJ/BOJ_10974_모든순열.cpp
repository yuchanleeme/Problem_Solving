#include <bits/stdc++.h>
using namespace std;
//https://www.acmicpc.net/problem/10974

/*
<모든 순열>
주요: DFS
1. DFS탐색을 통해 모든 순열을 찾는다.
2. 해당 결과를 출력한다.

*/

int N;
vector<int> seq;
bool check[10];

void dfs(){

  if(seq.size() == N){
    for(int item : seq){
      printf("%d ", item);
    }
    printf("\n");
    return;
  }

  for (int i = 1; i <= N; i++) {
    if(check[i] == true) continue;
    check[i] = true;
    seq.push_back(i);
    dfs();
    seq.pop_back();
    check[i] = false;
  }
}

int main(int argc, char const *argv[]) {
  cin >> N;
  dfs();
  return 0;
}
