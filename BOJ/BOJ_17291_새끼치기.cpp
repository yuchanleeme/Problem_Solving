#include <bits/stdc++.h>
using namespace std;
//https://www.acmicpc.net/problem/17291

/*
<새끼치기>
주요: 구현, 큐
1. 큐에 넣고 순회하면서 각 벌레들의 생존 및 분열을 확인힌다.
2. make_pair(태어난 연도, 남은 수명)을 분열 할 때마다 큐에 넣어준다.
3. 수명이 0이 되면 다시 큐에 넣지 않는다.
4. N년도 말의 큐의 사이즈가 곧 벌레들의 수이다.
==========
* N이 20이어서 그냥 큐로 계산했다.
* DP를 쓰면 N값이 커져도 메모리나 시간초과를 줄일 수 있을 것 같다.

*/

int N;
queue<pair<int, int>> bugs;
int main(int argc, char const *argv[]) {
  cin >> N;
  bugs.push({1,3});
  for (int year = 2; year <= N; year++) {
    int temp_size = bugs.size();
    for (int i = 0; i < temp_size; i++) {
      pair<int, int> now = bugs.front();
      if(year % 2 == 0) bugs.push({year, 4});
      else bugs.push({year, 3});

      if(now.second > 1){
        now.second--;
        bugs.push(now);
      }
      bugs.pop();
    }
  }
  cout << bugs.size() << endl;

  return 0;
}
