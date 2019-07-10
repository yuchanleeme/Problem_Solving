#include <iostream>
#include <vector>
using namespace std;
//https://www.acmicpc.net/problem/2798

/*
<블랙잭>
주요: 브루트 포스
1. 카드의 조합을 하나씩 다 찾아본다.
2. 3중 for문을 이용해 중복없이 차례대로 카드의 값들을 문제의 조건에 맞게 조사한다.

*/

int main() {

  int N, M, num, temp, ans = 0;
  vector<int> card;

  cin >> N >> M;

  for (int i = 0; i < N; i++) {
    cin >> num;
    card.push_back(num);
  }

  // 1,2번
  for (int a = 0; a < N; a++) {
    for (int b = a + 1; b < N; b++) {
      for (int c = b + 1; c < N; c++) {
        temp = card[a] + card[b] + card[c];
        if(temp <= M){
          ans = max(ans, temp);
        }
      }
    }
  }

  cout << ans;

  return 0;
}
