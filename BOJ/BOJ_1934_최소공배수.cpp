#include <bits/stdc++.h>
using namespace std;
//https://www.acmicpc.net/problem/1934

/*
<최소공배수>
주요: 수학, 유클리드 호제법
1. 최대공약수를 구한다. (유클리드 호제법)
2. 최소공배수를 구한다. (공식 이용)
==========
* 최소공배수 계산 할 때 나눗셈 주의

*/
int T;

int gcd(int a, int b){
  if(b == 0) return a;
  else return gcd(b, a%b);
}

int lcm(int a, int b){
  int G = gcd(a,b);
  return a/G * b/G * G;
}

int main(int argc, char const *argv[]) {
  cin >> T;
  while (T--) {
    int A, B;
    cin >> A >> B;
    cout << lcm(A,B) << endl;
  }
  return 0;
}
