#include <vector>
#include <algorithm>
using namespace std;
//https://programmers.co.kr/learn/courses/30/lessons/12940

/*
<최대공약수와 최소공배수>
주요: 구현, 유클리드 호제법
1. 유클리드 호제법을 이용해 최대공약수를 구한다.
2. 구한 최대공약수로 최소 공배수를 구한다. (A: Ga, B: Gb, L: Gab)
3. 두 값을 벡터에 넣고 리턴한다.

*/

int gcd(int a, int b){
  if(b == 0) return a;
  else return gcd(b, a%b);
}

vector<int> solution(int n, int m) {
  vector<int> answer;
  int G = gcd(n,m);
  int L = n * m / G;
  answer.push_back(G);
  answer.push_back(L);
  return answer;
}
