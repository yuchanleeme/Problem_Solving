#include <iostream>
#include <queue>
#include <vector>
using namespace std;
//https://www.acmicpc.net/problem/2660

/*
<회장뽑기>
주요: BFS
1. BFS를 이용해 하나씩 조사한다.
2. 그래프상 연결되어 있고 방문하지 않았다면 큐에 추가한다.
3. 더이상 그래프상 이어갈 정점이 없다면 cnt 값을 리턴한다.
4. 조건에 맞게 출력한다.

=========
* 플로이드 워셜을 써서 풀 수도 있다.

*/
int N;
vector<vector<int> > member(51, vector<int>(51, 0));
vector<int> visit(51, 0);

int bfs(int num){

  int temp_size, cnt = 0;
  queue<int> que;
  visit[num] = 1;

  que.push(num); // 큐 시작

  while (que.size() != 0) {
    temp_size = que.size();
    for (int k = 0; k < temp_size; k++) {
      for (int i = 1; i <= N; i++) {
        if(visit[i] == 0){
          if(member[que.front()][i] == 1){
            que.push(i);
            visit[i] = 1;
          }
        }
      }
      que.pop();
    }
    cnt++;
  }
  visit.assign(N+1, 0);
  return cnt;
}


int main() {

  int a, b, val, temp = 50;
  vector<int> ans;
  cin >> N;

  while(true){
    cin >> a >> b;
    if(a == -1 || b == -1){ break;}
    member[a][b] = 1;
    member[b][a] = 1;
  }

  for (int i = 1; i <= N; i++) {
    val = bfs(i);
    if(temp > val){
      ans.clear();
      ans.push_back(i);
      temp = val;
    }
    else if(temp == val){
      ans.push_back(i);
    }
  }

  cout << temp - 1 << " " << ans.size() << endl;
  for (int i = 0; i < ans.size(); i++) {
    cout << ans[i] << " ";
  }

  return 0;
}
