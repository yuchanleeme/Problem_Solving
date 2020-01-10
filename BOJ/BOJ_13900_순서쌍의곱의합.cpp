#include <iostream>
#include <vector>
using namespace std;
//https://www.acmicpc.net/problem/13900

/*
<순서쌍의 곱의 합>
주요: 수학
1. 그냥 단순히 순서쌍으 다 구하면 시간초과가 날것이라 판단했다.
2. 수학적 규칙을 찾아서 문제를 해결한다.
  2-1) 각 숫자는 다른 모든 숫자와 한번씩 만난다.
  2-2) 따라서 각 숫자를 제외한 모든 숫자들과의 곱을 더한다.
  2-3) 하지만 숫자가 2번 중복되므로 전체 값을 2로 나누어 준다.
3. 혹시 모르는 int 범위 초과를 고려해 long long으로 선언한다.

*/

int main() {

  int N;
  long long sum = 0, ans = 0;
  vector<int> num;
  cin >> N;

  for (int i = 0; i < N; i++) {
    int input;
    cin >> input;
    sum += input;
    num.push_back(input);
  }

  for (int i = 0; i < num.size(); i++) {
    ans += (sum-num[i]) * num[i];
  }

  cout << ans/2;

  return 0;
}
