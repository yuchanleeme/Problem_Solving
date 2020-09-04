#include <bits/stdc++.h>
using namespace std;
//https://programmers.co.kr/learn/courses/30/lessons/43165

/*
<타겟 넘버<
주요 : DFS
1. 한 차례에서 필요한건 더하냐 빼냐 차이이다.
2. 즉, DFS 탐색을 돌면서 이전 번째에서 더해서 왔냐, 빼서 왔냐만 계산하면 되었다.
3. 벡터 총 경우의 수를 탐색하면서 target 번호만 탐색하면 되는 문제였다.

*/

int N, answer, tar;
vector<int> seq;
void dfs(int prev, int level, vector<int> numbers){

  if(level == N){
    if(prev == tar) answer++;
    return;
  }

  dfs(prev+ numbers[level], level+1, numbers);
  dfs(prev- numbers[level], level+1, numbers);

}

int solution(vector<int> numbers, int target) {
  N = numbers.size();
  tar = target;
  dfs(0, 0, numbers);
  return answer;
}
