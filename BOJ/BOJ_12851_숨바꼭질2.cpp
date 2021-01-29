#include <bits/stdc++.h>
using namespace std;
//https://www.acmicpc.net/problem/12851

/*
<숨바꼭질 2>
주요: BFS
1. BFS 탐색을 통해 최소 횟수를 구한다.
2. 값이 유효하고 방문한 숫자의 visitHere 값이 현재 싸이클 번호 보다 클 때만 큐에 넣어준다.
3. K 를 찾으면 ans 벡터에 넣고 최종으로 정답을 출력한다.
==========
* 그냥 방문처리를 해버리면 같은 사이클에서 접근했을 때의 값을 무시하는 경우가 생긴다.
  (ex 1 4 => 2 2 여야 하는데 1 4 => 2 1) 이렇게 뜸

*/

int N, K;
queue<int> que;
vector<int> ans;
vector<int> visitHere(101010, 101010);
int main(int argc, char const *argv[]) {

  cin >> N >> K;
  if(N == K) return !printf("0\n1");
  int cnt = 0;

  visitHere[N] = 0;
  que.push(N);

  while (!que.empty()) {
    int temp_size = que.size();
    cnt++;

    for (int i = 0; i < temp_size; i++) {
      int num = que.front();
      if(num-1 >= 0 && visitHere[num-1] >= cnt){
        if(num-1 == K) ans.push_back(num-1);
        else{
          visitHere[num-1] = cnt;
          que.push(num-1);
        }
      }
      if(num+1 <= 100000 && visitHere[num+1] >= cnt){
        if(num+1 == K) ans.push_back(num+1);
        else{
          visitHere[num+1] = cnt;
          que.push(num+1);
        }
      }
      if(num*2 <= 100000 && visitHere[num*2] >= cnt){
        if(num*2 == K) ans.push_back(num*2);
        else{
          visitHere[num*2] = cnt;
          que.push(num*2);
        }
      }
      que.pop();
    }
    if(ans.size() != 0){
      cout << cnt << "\n" << ans.size();
      break;
    }
  }
  return 0;
}
