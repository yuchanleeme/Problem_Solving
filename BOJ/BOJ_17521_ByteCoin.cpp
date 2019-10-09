#include <iostream>
#include <vector>
#include <queue>
using namespace std;
//https://www.acmicpc.net/problem/17521

/*
<Byte Coin>
주요: BFS
==========
* 모든 경우의 수를 큐에 넣어서 계산하는 방법을 썼는데 계속 런타임 에러가 나왔다.

*/

typedef struct info{

  long long day;
  long long coin;
  long long rest_price;

}Info;

int N, W;
vector<int> price;

queue<Info> que;

long long bfs(){

  long long res = 0;

  que.push({0, 0, W});

  while (!que.empty()) {

    long long d = que.front().day;
    long long c = que.front().coin;
    long long p = que.front().rest_price;
    que.pop();

    if(d == N){
      res = max(res, (long long)p);
      que.pop();
      continue;
    }

    // 매수
    if(price[d] <= p){
      long long extra_coin = p/price[d];
      long long rest = p % price[d];
      que.push({d+1, c+ extra_coin, rest});
    }
    // 매도
    que.push({d+1, 0, p + (c*price[d])});

    // 아무행동도 안했을 때
    que.push({d+1, c, p});
  }

  return res;
}

int main() {

  cin >> N >> W;

  for (int i = 0; i < N; i++) {
    int input;
    cin >> input;
    price.push_back(input);
  }

  cout << bfs();

  return 0;
}
