#include <iostream>
#include <map>
using namespace std;
//https://www.acmicpc.net/problem/1351

/*
<무한 수열>
주요: DP, 메모이제이션 방법 사용
1. 메모리와 시간관리를 위해 map을 사용한다.
2. 메모이제이션 방법을 이용해 불필요한 연산을 줄인다.

*/

long long N, P, Q;
map<long long, long long> mp;

long long inf_seq(long long n){

  if(n == 0){
    return 1;
  }
  else if (mp[n]){
    return mp[n];
  }
  else{
    mp[n] = inf_seq(n/P) + inf_seq(n/Q);
    return mp[n];
  }
}

int main() {

  cin >> N >> P >> Q;

  cout << inf_seq(N);

  return 0;
}
