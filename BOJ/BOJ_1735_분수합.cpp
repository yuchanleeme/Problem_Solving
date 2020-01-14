#include <iostream>
#include <vector>
using namespace std;
//https://www.acmicpc.net/problem/1735

/*
<분수 합>
주요: 수학
1. 분모끼리 먼저 통분을 한다. (최소공배수)
2. 최소공배수에 맞게 각 분자를 바꿔주고 더해준다.
3. 기약분수로 만들기 위해 최대공약수로 다시 분모 분자를 다시 나눠준다.

===========
* 입력 받은 값이 무조건 기약분수가 아닐 수 있음을 유의

*/

int gcd(int a, int b){

  if(b == 0){
    return a;
  }
  else{
    return gcd(b, a%b);
  }
}

long long lcm (int a, int b){
  long long val = gcd(a, b);
  return val * (a/val) *(b/val);
}

int main() {

  int aP, aC, bP, bC;
  long long ansP, ansC;
  cin >> aC >> aP >> bC >> bP;

  ansP = lcm(aP, bP);
  ansC = aC*(ansP/aP) + bC*(ansP/bP);

  int divV = gcd(ansP, ansC);

  cout << ansC/divV << " " << ansP/divV;

  return 0;
}
