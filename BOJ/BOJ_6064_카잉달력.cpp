#include <iostream>
using namespace std;
//https://www.acmicpc.net/problem/6064

/*
<카잉 달력>
주요: 계산
1. 규칙을 생각해보자.
 => ex) M = 10 , N = 12 : <1:1> , <2:2> .... <10:10>, <1,11>, <2:12>, <3:1> ...

*/
int lcm(int a, int b){

  int ans = 1, val = 2;
  while(true){
    if(a % val == 0 && b % val == 0){
      ans *= val;
      a/=val, b/=val;
    }
    else{
      val++;
      if(val > max(a,b)){ return ans*a*b;}
    }
  }
}



int main() {
  freopen("1aa.txt", "r", stdin);
  int T, M, N, x, ym max_year;

  cin >> T;

  for (int testcase = 0; testcase < T; testcase++) {

    cin >> M >> N >> x >> y;

    max_year = lcm(M,N);
    while (true) {

    }

  }
  return 0;
}
