#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
//https://www.acmicpc.net/problem/4153

/*
<직각삼각형>
주요: 수학
1. 단순 수학 문제이다.
2. 입력 받은 값들을 정렬해 크기를 비교 한다.
3. 가장 큰 값의 제곱이 다른 값들의 제곱의 합과 같은지 비교한다.
4. 직각삼각형 조건에 맞게 right, wrong 출력한다.

*/

int main() {

  int a, b, c;

  while(cin >> a >> b >> c){
    if(a == 0 && b == 0 && c == 0){ break;}
      int cal[3] = {a,b,c};
      sort(cal, cal+3);

      if(cal[0]*cal[0] + cal[1]*cal[1] == cal[2]*cal[2]){
        cout << "right" << endl;
      }
      else{
        cout << "wrong" << endl;
      }
  }

  return 0;
}
