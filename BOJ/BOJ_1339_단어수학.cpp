#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
//https://www.acmicpc.net/problem/1339

/*
<단어수학>
주요: 수학, 구현
1. 한가지 식을 달리 생각해보자.
  => ABC + BCA => (100A + 10B + C) + (100B + 10C + A) = 110B + 101A + 11C
  => 즉, B A C 순으로 큰값을 넣어주면 해결이 된다.
2. 알파벳 벡터를 미리 만들어준다. idx 는 input - 'A'
3. 마지막으로 정렬 해주고 9 부터 차례대로 값을 곱해 계산해준다.

=======
* 백트래킹으로 풀었더니 시간초과가 났다.
  => 좀더 효율적인 수학적인 접근을 이용했다.

*/

bool comp(const int& x, const int& y){
  return x > y;
}

int main() {

  int N, ans = 0;
  string input;
  cin >> N;
  vector<int> alpa(26,0);

  for (int i = 0; i < N; i++) {
    cin >> input;
    int mul = 1;
    for (int j = input.length()-1; j>=0 ; j--) {
      alpa[input[j] - 'A'] += mul;
      mul *= 10;
    }
  }
  sort(alpa.begin(),alpa.end(), comp);

  for (int i = 0; i <= 9; i++) {
    ans += (9-i) * alpa[i];
  }

  cout << ans;

  return 0;
}
