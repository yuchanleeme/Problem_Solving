#include <bits/stdc++.h>
using namespace std;
//https://www.acmicpc.net/problem/1461

/*
<도서관>
주요: 그리디
1. 양수, 음수 위치의 도서들을 분류해서 벡터에 저장한다.
2. 각각의 양수, 음수 도서들을 큰 수로 정렬한다.
  => + - 위치의 도서들을 섞어서 가져다 놓으면, 0을 여러번 지나게 되므로 최솟값이 나올 수 없다.
3. 최대로 들 수 있는 책의 개수 만큼 각각 묶음을 짓는다.
  3.1 각 벡터의 앞에서부터 묶고, 각 묶음의 첫번째 원소를 기준으로 2배씩 총 거리에 더해준다.
    => 그래야 해당 묶음의 모든 책들을 가져다 놓고 원점으로 올 수 있다.
  3.2 가장 먼 위치의 책을 가장 나중에 가져다 놓아야 한다. (다시 0으로 돌아갈 필요 없기 때문에)
    => 따라서, 3.1을 계산하면 가장 먼 책이 있는 그룹은 중복으로 더해지므로 총 거리에서 가장 먼 위치의 거리를 빼준다.
4. 최종 거리를 출력한다.

*/

int N, M, ans;
vector<int> book_minus, book_plus;

int main(int argc, char const *argv[]) {

  cin >> N >> M;
  // 1번
  for (int i = 0; i < N; i++) {
    int temp; cin >> temp;
    if(temp < 0) book_minus.push_back(-temp);
    else book_plus.push_back(temp);
  }

  // 2번
  sort(book_minus.rbegin(), book_minus.rend());
  sort(book_plus.rbegin(), book_plus.rend());

  // 3.1번
  for (int i = 0; i < book_plus.size(); i++) {
    ans += book_plus[i]*2;
    i += (M-1);
  }
  for (int i = 0; i < book_minus.size(); i++) {
    ans += book_minus[i]*2;
    i += (M-1);
  }

  // 3.2번
  if(book_minus.size() == 0){
    ans -= book_plus[0];
  }else if(book_plus.size() == 0){
    ans -= book_minus[0];
  }
  else{
    ans -= book_plus[0] > book_minus[0] ? book_plus[0] : book_minus[0];
  }

  // 4번
  cout << ans;

  return 0;
}
