#include <iostream>
using namespace std;
// https://www.acmicpc.net/problem/1072

/*
<게임> (2)
주요: 이분탐색
1. 함수 f 는 앞으로 이길 수를 인자로 받아 승률을 리턴해준다.
2. Z는 게임을 계속 진행하기전 현재 승률이다.
3. 이분탐색을 통해 Z승률이 나올 수 있는 최대 이긴 횟수를 lo에 저장시킨다.
4. lo와 hi는 1씩 차이나므로 hi값이 결국 승률을 넘어서는 최소 이긴 횟수이다.

*/

long long X, Y, Z;

long long f(long long win){

  long long percent;
  percent = (Y+win)*100 / (X+win);
  return percent;
}

int main() {

  scanf("%lld %lld", &X, &Y);
  Z = f(0);

  long long lo = 0, hi = 1e9+1;
  for (int i = 0; i < 40; i++) {
    long long mid = (lo+hi) / 2;
    if(f(mid) <= Z){
      lo = mid;
    }
    else{
      hi = mid;
    }
  }

  if(lo >= 1e9){
    printf("-1");
  }
  else{
    printf("%lld\n", hi);
  }

  return 0;
}
