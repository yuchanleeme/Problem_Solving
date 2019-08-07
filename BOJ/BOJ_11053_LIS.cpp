#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
//https://www.acmicpc.net/problem/11053

int main() {

  int N, M, last = 0, ans = 0, temp = 0;
  vector<int> v;
  cin >> N;

  for (int i = 0; i < N; i++) {
    cin >> M;
    v.push_back(M);
  }

  for (int j = 0; j < N; j++) {
    last = 0;
    temp = 0;
    for (int i = 0; i < j; i++) {
      if(last < v[i]){
        last = v[i];
        temp++;
      }
    }
    ans = max(ans, temp);
  }

  cout << ans;

  return 0;
}
