#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
//https://www.acmicpc.net/problem/10814

/*
<나이순 정렬>
주요: stable sort, copare 함수
1. member 벡터에 나이와 이름을 하나의 pair로 저장한다.
2. stable_sort로 정렬 후 순서가 뒤바뀌지 않게 한다.
  => compare 함수로 나이만 비교한다.
3. 정렬 된 member 벡터를 출력한다.

==========
* algorithm 라이브러리의 sort는 unstable sort이다.

*/

bool compare(const pair<int, string> &a, const pair<int, string> &b){
  return a.first < b.first;
}

int main() {

  int N;
  cin >> N;

  vector<pair<int, string> > member;

  for (int i = 0; i < N; i++) {
    int age;
    string name;
    cin >> age >> name;
    member.push_back({age, name});
  }

  stable_sort(member.begin(), member.end(), compare);

  for (int i = 0; i < N; i++) {
    cout << member[i].first << " " << member[i].second << '\n';
  }

  return 0;
}
