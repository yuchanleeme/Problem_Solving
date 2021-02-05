#include <bits/stdc++.h>
using namespace std;
// https://www.acmicpc.net/problem/9375

/*
<패션왕 신해빈>
주요: map
1. map을 이용해 각 의상의 종류의 개수를 센다.
2 해당 종류를 안 입는 경우 1개를 추가해 곱의 법칙으로 경우의 수를 구하고 다 안입는 1의 경우의 수를 빼준다.
  2.1 각 의상의 종류 + 1 을 각각 곱하고 1을 빼준 값을 출력한다.
  2.2 ex) 상의:2, 하의:3, 안경:1 => (2+1)x(3+1)x(1+1) - 1 = 23

*/

int T;
map<string, int> mp;

int main(){
  cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);

  cin >> T;
  for (int tc = 0; tc < T; tc++) {
    int N; cin >> N;
    int ans = 1;
    mp.clear();
    for (size_t i = 0; i < N; i++) {
      string name, part;
      cin >> name >> part;
      mp[part]++;
    }
    for(auto &item : mp){
      ans *= (item.second +1);
    }
    cout << ans - 1 << "\n";
  }
}
