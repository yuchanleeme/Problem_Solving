#include <iostream>
using namespace std;
//https://www.acmicpc.net/problem/13171

/*
<A>
주요: 분할 정복(Divide-and-conquer), DP
1. 문제의 조건에 충실히 따른다.
2. 이진법으로 X값을 계산하여 해당하는 수를 multiple함수로 곱해주어 계산한다.
3. mod (A X B) = mod(A) X mod(B) 임을 이용해 곱셈함수를 만든다.

*/

typedef long long ll;
const ll D = 1000000007;
ll bin[64];
ll A, X, res = 1;

ll multiple(int num){

  if(num == 0){
    return 1;
  }
  else if(num == 1){
    return bin[num] = A % D;
  }
  else if(bin[num]){
    return bin[num];
  }
  else{
    return bin[num] = (multiple(num-1) * multiple(num-1)) % D;
  }
}

int main() {

  int idx = 1;
  cin >> A >> X;

  while(X != 0){
    if(X % 2 == 1){
      res *= multiple(idx);
      res = res % D;
    }
    X /= 2;
    idx++;
  }

  cout << res;

  return 0;
}
