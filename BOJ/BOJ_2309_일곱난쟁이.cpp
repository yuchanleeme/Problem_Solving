#include <iostream>
#include <algorithm>
using namespace std;
//https://www.acmicpc.net/problem/2309

/*
<일곱 난쟁이>
주요: 합이 100임을 이용한다.
1. 100이되는 7명을 찾는것보다 100을 못만드는 2명을 찾는게 더 빠르다.
2. 9명의 키의 합 - 100 = 다른 두 난쟁이의 키의 합
3. 두 난쟁이를 찾았으면 해당 인덱스 배열 값을 0으로 만들고 오름차순 정렬한다.
4. 배열의 2번째값부터 출력하면 된다.

*/


int main() {

  int n[9], temp, a, b, sum = 0;
  bool flag = false;

  for (int i = 0; i < 9; i++) {
    scanf("%d", &n[i]);
    sum += n[i];
  }

  temp = sum - 100;

  // n[i], n[j]를 0으로 만들고 2중 for문을 나간다. (0이되는 경우는 딱 1쌍이어야기 때문)
  for (int i = 0; i < 9; i++) {
    for (int j = i+1; j < 9; j++) {
      if(temp - n[i] == n[j]){
        n[i] = 0;
        n[j] = 0;
        flag = true;
        break;
      }
    }
    if(flag){ break;}
  }

  sort(n, n+9);
  for (int k = 2; k < 9; k++) {
    printf("%d\n", n[k]);
  }

  return 0;
}
