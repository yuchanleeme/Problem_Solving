#include <iostream>
#include <vector>
using namespace std;
//https://www.acmicpc.net/problem/1654

/*
<랜선 자르기>
주요: 이분 탐섹
1. f의 값들을 그래프로 생각하면 감소함수이다.
2. 이분 탐색으로 lo, hi값을 좁혀주면 된다.
3. 이분 탐색의 if문에서 lo 값을 가능값으로 만들었으므로 lo값을 출력해주면 된다.
============
* f(h) : h를 길이로 했을때 생기는 랜선의 개수를 리턴

*/

int N, M;
long long lan[1010101];

int f(long long h){
  int sum = 0;
  for (int i = 0; i < N; i++) {
    long long tmp = lan[i];
    if(h > lan[i]){ continue;}
    while (tmp >= 0) {
      tmp -= h;
      if(tmp < 0){ break;}
      sum++;
    }
  }
  return sum;
}

int main() {

  scanf("%d %d", &N, &M);
  for (int i = 0; i < N; i++) {
    scanf("%lld", &lan[i]);
  }

  long long lo = 0, hi = 1e9*4;
  for (int i = 0; i < 40; i++) {
    long long mid = (lo+hi) / 2;
    if(f(mid) >= M){
      lo = mid;
    }
    else {
      hi = mid;
    }
  }

  printf("%lld\n", lo);

  return 0;
}
