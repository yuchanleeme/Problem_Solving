#include <bits/stdc++.h>
using namespace std;
//https://www.acmicpc.net/problem/16113

/*
<반지>
주요: 구현
1. 반지 글자를 연속으로 두번 이어 붙인다.
2. 이어 붙인 글자를 처음 idx부터 차례대로 조사한다.

*/

int N, idx, ans;
string target;
int main(int argc, char const *argv[]) {
  cin >> target;
  cin >> N;
  for (int i = 0; i < N; i++) {
    idx = 0;
    string temp;
    cin >> temp;
    temp += temp;
    for (int j = 0; j < temp.length()-target.length(); j++) {
      idx = 0;
      for (int k = 0; k < target.length(); k++) {
        if(temp[j+k] == target[idx]) idx++;
        else break;
      }
      if(idx == target.length()){
        ans++;
        break;
      }
    }
  }
  cout << ans;
  return 0;
}
