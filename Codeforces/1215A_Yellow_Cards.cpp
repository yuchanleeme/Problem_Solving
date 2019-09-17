#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
//http://codeforces.com/problemset/problem/1215/A

int main() {


  int a, b, k_1, k_2, n;
  cin >> a >> b >> k_1 >> k_2 >> n;

  vector<int> team_1;
  vector<int> team_2;
  for (int i = 0; i < a; i++) {
    team_1.push_back(k_1);
    team_2.push_back(k_1);
  }
  for (int i = 0; i < b; i++) {
    team_1.push_back(k_2);
    team_2.push_back(k_2);
  }

  int maxValue = 0 , minValue = 0;
  sort(team_1.begin(), team_1.end());

  int temp_n = n;
  for (int i = 0; i < team_1.size(); i++) {
    if(temp_n - team_1[i] < 0){break;}
    temp_n -= team_1[i];
    maxValue++;
  }

  queue<int> que;
  int temp_n2 = n;
  for (int i = team_1.size()-1; i >= 0; i--) {
    que.push(team_1[i]);
  }

  while (temp_n2 != 0) {
    if(minValue == (a+b)){ break;}
    if(que.front() == 1){
      temp_n2 -= 1;
      que.pop();
      minValue++;
    }
    else{
      int tempValue = que.front();
      for (int i = 1; i < que.front(); i++) {
        temp_n2 -= 1;
        if(temp_n2 == 0){ break;}
      }
      que.pop();
      que.push(1);
    }
  }

  cout << minValue << " " << maxValue;

  return 0;
}
