#include <iostream>
#include <vector>
using namespace std;
//https://www.acmicpc.net/problem/1676

/*
<팩토리얼 0의 개수>
주요: 수학
1. 5가 나온다면 그 전에 2는 충분히 존재한다. (전체 팩토리얼에서 2의수 > 5의 수)
2. 즉 1~N 까지 5가 얼마나 나오는지 찾으면 된다.

*/

int main() {

  int N, num_5 = 0;
  cin >> N;

  for (int i = 1; i <= N; i++) {
    int tmp = i;

    if(tmp % 5 == 0){
      while (tmp % 5 == 0) {
        num_5++;
        tmp /= 5;
      }
    }
  }

  cout << num_5;

  return 0;
}
