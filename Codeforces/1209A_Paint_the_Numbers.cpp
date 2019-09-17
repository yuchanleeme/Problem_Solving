#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int main() {

  int N, temp;
  vector<int> color;
  queue<int> remain;

  cin >> N;

  for (int i = 0; i < N; i++) {
    cin >> temp;
    color.push_back(temp);
    remain.push(temp);
  }
  sort(color.begin(),color.end());

  int ans = 0, idx = 0;
  bool color_trigger = false;
  while(!remain.empty()){
    color_trigger = false;
    if(idx == color.size()) break;

    int temp_size = remain.size();
    for (int i = 0; i < temp_size; i++) {
      if(remain.front() % color[idx] != 0){
        remain.push(remain.front());
      }
      else{
        color_trigger = true;
      }
      remain.pop();
    }
    idx++;
    if(color_trigger) ans++;
  }

  cout << ans;

  return 0;
}
