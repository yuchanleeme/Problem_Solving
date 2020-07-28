#include <bits/stdc++.h>
using namespace std;
//https://www.acmicpc.net/problem/19535

/*
<ㄷㄷㄷㅈ>
주요: 트리, 구현
1. 트리이므로 사이클이 없다.
2. G 모양은 자식트리가 3개 이상인 정점중, 자식트리를 3개 뽑는 경우의 수이다.
3. D 모양은 깊이가 4인 부분 트리를 중복없이 고르는 것이다.
  3-1. 가운데 2개의 정점을 커지는 순서로 픽스한다. x - a - b - y (a < b)
  3-2. 이제 a와 b의 자식트리의 개수들을 곱해 경우의수를 찾는다. (단, a와 b는 제외한다.)
4. D와 G를 구한 뒤, 각 조건에 맞게 출력한다.
==========
* 그래프를 다 찾는 방식으로는 시간초과를 받는다.

*/

int N;
long long D, G;
vector<int> graph[303030];
vector<int> seq;

int main(int argc, char const *argv[]) {
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  cin >> N;
  for (int i = 0; i < N-1; i++) {
    int x, y;
    cin >> x >> y;
    graph[x].push_back(y);
    graph[y].push_back(x);
  }

  for (int i = 1; i <= N ; i++) {
    long long res = graph[i].size();
    G += res*(res-1)*(res-2) / 6;
  }

  for (int i = 1; i <= N; i++) {
    for (int j = 0; j < graph[i].size(); j++) {
      int next = graph[i][j];
      if(i < next){
        D += (graph[next].size()-1) * (graph[i].size()-1);
      }
    }
  }
  if(D > 3*G){
    cout << "D" <<"\n";
  }
  else if(D < 3*G){
    cout << "G" << "\n";
  }
  else if(D == 3*G){
    cout << "DUDUDUNGA" << "\n";
  }
  return 0;
}
