#include <iostream>
#include <vector>
#include <map>
using namespace std;
//https://www.acmicpc.net/problem/4195

/*
<여행가자>
주요: 유니온 파인드
1. 서로소 집합을 구현한다.
2. 연결이 되어 있다면 각각 find 했을때 리턴하는 값이 같아야 한다.
  => 즉, find값이 모두 같아야만 여행 일정을 소화 가능하다.
3. isPossible 값에 맞춰 정답을 출력한다.

*/

const int MAX_N = 201;
int travel[1001];
int par[MAX_N];

void init(int N){
  for (int i = 1; i <= N; i++) {
    par[i] = i;
  }
}

int find(int x){

  if(par[x] == x){
    return x;
  }
  else{
    return par[x] = find(par[x]);
  }
}

void unite(int x, int y){

  x = find(x), y = find(y);
  if(x == y){
    return;
  }
  par[x] = y;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int N, M;
  cin >> N >> M;

  init(N);
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= N; j++) {
      int input;
      cin >> input;
      if(input == 1){
        unite(i, j);
      }
    }
  }

  for (int i = 1; i <= M; i++) {
    cin >> travel[i];
  }

  bool isPossible = true;
  int parTrg = find(travel[1]);
  for (int i = 1; i <= M; i++) {
    if(find(travel[i]) != parTrg){
      isPossible = false;
      break;
    }
  }

  if(isPossible){
    cout << "YES";
  }
  else{
    cout << "NO";
  }

  return 0;
}
