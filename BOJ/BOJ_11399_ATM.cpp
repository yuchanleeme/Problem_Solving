#include <iostream>
#include <algorithm>
using namespace std;
//https://www.acmicpc.net/problem/1139

/*
<ATM>
주요: 가장 큰 숫자는 가장 적게 더해져야 한다.
1. 인출시간이 가장 긴 사람의 시간이 제일 적게 더해져야 최솟값이 나온다.
2. 오름차순으로 정렬 하고 더했을 때, atm[0]값이 n번, atm[1]값이 n-1번 ... atm[n-1] 이 1번 더해진다는 사실을 이용한다.
3. 오름차순 정렬 후 -> 인덱스 0부터 n~1까지 곱해준다. -> 값 출력

*/

int main() {

  int n, atm[1010], sum = 0;

  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> atm[i];
  }

  sort(atm,atm+n);

  for (int i = 0; i <= n; i++) {
    sum += (n-i) * atm[i];
  }

  cout << sum;

  return 0;
}
