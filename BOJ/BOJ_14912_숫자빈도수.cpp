#include <bits/stdc++.h>
using namespace std;
//https://www.acmicpc.net/problem/14912

/*
<숫자 빈도수>
주요: 구현
1. N이 100,000밖에 안되므로 그냥 다 센다.
2. 자리수를 하나씩 세서 출력하면 된다.

*/

int N, target, cnt;
int main(int argc, char const *argv[]) {

  cin >> N >> target;
  for (int i = 1; i <= N; i++) {
    int temp = i;
    while (temp != 0) {
      if(temp % 10 == target) cnt++;
      temp /= 10;
    }
  }

  cout << cnt;

  return 0;
}
