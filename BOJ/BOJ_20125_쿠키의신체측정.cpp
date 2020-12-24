#include <bits/stdc++.h>
using namespace std;
//https://www.acmicpc.net/problem/20125

/*
<쿠키의 신체 측정>
주요: 구현
1. 심장의 좌표를 찾는다.
2. 심장 좌표를 중심으로 각 팔, 다리, 몸통의 길이를 센다.

*/

int N;
vector<string> str;
pair<int, int> heart;

int main(int argc, char const *argv[]) {

  cin >> N;
  for (int i = 0; i < N; i++) {
    string temp;
    cin >> temp;
    str.push_back(temp);
  }

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if(str[i][j] == '*'){
        heart.first = i+1;
        heart.second = j;
        i = N;
        break;
      }
    }
  }
  cout << heart.first+1 << " " << heart.second+1 << "\n";

  // left arm
  int cnt = 0;
  for (int idx = 0; idx < N; idx++) {
    if(idx == heart.second){
      cout << cnt << " ";
      break;
    }
    if(str[heart.first][idx] == '*'){
      cnt++;
    }
  }

  // right arm
  cnt = 0;
  for (int idx = heart.second+1; idx < N; idx++) {
    if(str[heart.first][idx] == '*'){
      cnt++;
    }
  }
  cout << cnt << " ";

  // back
  cnt = 0;
  for (int idx = heart.first+1; idx < N; idx++) {
    if(str[idx][heart.second] == '*'){
      cnt++;
    }
  }
  cout << cnt << " ";

  // left leg
  cnt = 0;
  for (int idx = heart.first+1; idx < N; idx++) {
    if(str[idx][heart.second-1] == '*'){
      cnt++;
    }
  }
  cout << cnt << " ";

  // right leg
  cnt = 0;
  for (int idx = heart.first+1; idx < N; idx++) {
    if(str[idx][heart.second+1] == '*'){
      cnt++;
    }
  }
  cout << cnt << " ";

  return 0;
}
