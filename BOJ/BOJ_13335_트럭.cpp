#include <bits/stdc++.h>
using namespace std;
// https://www.acmicpc.net/problem/13335

/*
<트럭>
주요: 구현, 큐
1. 큐를 통해 다리의 실시간 상황을 갱신한다.
2. 먼저, 현재 다리의 최신 현황을 갱신한다.
3. 그 다음 다리에 트럭이 들어갈 수 있으면 트럭을 넣는다.
4. 큐가 비었고, 모든 트럭이 지나갔을 때 그 시간을 출력한다.

*/

int N, W, L;
vector<int> truck;
int main(){

  cin >> N >> W >> L;

  for (size_t i = 0; i < N; i++) {
    int temp;
    cin >> temp;
    truck.push_back(temp);
  }

  int nowL = 0, idx = 0, ans = 0;
  queue<pair<int, int> > que;
  while (true) {
    int temp_size = que.size();
    for (int i = 0; i < temp_size; i++) {
      int truckWeight = que.front().first;
      int remainTime = que.front().second;

      if(remainTime == 1){
        nowL -= truckWeight;
      }
      else{
        que.push({truckWeight, remainTime-1});
      }
      que.pop();
    }

    if(que.size() <= W && idx < N && nowL+truck[idx] <= L){
      nowL += truck[idx];
      que.push({truck[idx++], W});
    }
    ans++;
    if(idx == N && que.empty()) break;
  }
  cout << ans;
  return 0;
}
