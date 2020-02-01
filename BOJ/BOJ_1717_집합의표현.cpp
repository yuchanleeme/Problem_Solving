#include <iostream>
#include <vector>
using namespace std;
//https://www.acmicpc.net/problem/1717

/*
<집합의 표현>
주요: 유니온 파인드
1. 서로소 집합을 구현한다.
2. 각각의 명령어 (0,1)에 맞게 수행한다.
3. 출력 값이 많을것이 예상되므로 printf, scanf를 쓴다.

*/

const int MAX_N = 1e7;
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

  int N, M;
  scanf("%d %d", &N, &M);
  init(N);
  for (int i = 0; i < M; i++) {
    int op, x, y;
    scanf("%d %d %d", &op, &x, &y);
    if(op == 0){
      if(find(x) != find(y)){
        unite(x, y);
      }
    }
    else if(op == 1){
      if(find(x) == find(y)){
        printf("YES\n");
      }
      else{
        printf("NO\n");
      }
    }
  }
  return 0;
}
