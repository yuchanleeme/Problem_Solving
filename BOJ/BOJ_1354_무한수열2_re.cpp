#include <iostream>
#include <map>
using namespace std;
//https://www.acmicpc.net/problem/1354

/*
<무한 수열2>
주요: DP, 메모이제이션 방법 사용
1. 메모리와 시간관리를 위해 map을 사용한다.
2. 메모이제이션 방법을 이용해 불필요한 연산을 줄인다.
3. 계속된 시간 초과로 인해 코드 수정함.
4. 미리 n을 천만까지 계산해서 시간을 단축시킨다.

*/

long long N, P, Q, X, Y;
map<long long, long long> mp;

long long inf_seq(long long n){

  if(n <= 0){
    return 1;
  }
  else if(n == 1){
    return 2;
  }
  else if(n < 10000000 && n > 0){
    if (mp.find(n) != mp.end()){
      return mp[n];
    }
    else{
      return mp[n] = inf_seq(n/P - X) + inf_seq(n/Q - Y);
    }
  }

  return inf_seq(n/P - X) + inf_seq(n/Q - Y);

}

int main() {

  cin >> N >> P >> Q >> X >> Y;
  cout << inf_seq(N);

  return 0;
}
