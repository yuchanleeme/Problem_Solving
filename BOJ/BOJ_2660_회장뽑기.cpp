#include <iostream>
#include <queue>
#include <vector>
using namespace std;
//https://www.acmicpc.net/problem/2660

/*
<회장뽑기>
주요: 
1.

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
    cnt++;// 연결되어있는 값 큐에 넣고 cnt 플러스
  }
  visit.assign(N+1, 0);
  return cnt;
}


int main() {

  // freopen("1aa.txt", "r", stdin);

  int a, b, val, temp = 50;
  vector<int> ans;
  cin >> N;
  // cout << a << b;

  while(true){
    cin >> a >> b;
    if(a == -1 || b == -1){ break;}
    member[a][b] = 1;
    member[b][a] = 1;
  }

  // for (int i = 1; i <= N; i++) {
  //   printf("i : %d , bfs : %d\n",i, bfs(i) );
  // }


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
