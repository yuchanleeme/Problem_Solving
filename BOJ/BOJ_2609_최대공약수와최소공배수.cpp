#include <iostream>
#include <vector>
using namespace std;
//https://www.acmicpc.net/problem/2609

/*
<최대공약수와 최소공배수>
주요: 유클리드 알고리즘
1. 유클리드 알고리즘을 구현한다.
2. 차례대로 최대공약수와 최소공배수를 출력한다.

*/

// 최대공약수
int gcd(int a, int b){

  if(b == 0){
    return a;
  }
  else{
    return gcd(b, a%b);
  }
}

// 최소공배수
long long lcm (int a, int b){
  int val = gcd(a, b);
  return val * (a/val) *(b/val);
}

int main() {

  int N, M;
  cin >> N >> M;
  cout << gcd(N,M) << '\n' << lcm(N,M);
  return 0;

}
