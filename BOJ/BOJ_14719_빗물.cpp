#include <bits/stdc++.h>
using namespace std;
//https://www.acmicpc.net/problem/14719

/*
<빗물>
주요: 구현
1. 오른쪽, 벽과 왼쪽 벽을 하나씩 조사해서 각각 가장 큰 값을 조사한다.
  1-1. 단, 비교값으로 현재 벽의 높이를 쓴다.
2. 이 두 값이 현재 벽의 크기와 같은것이 있다면 물이 고일 수 없다.
3. 2번조건에 해당되지 않은 두 값들 중에 작은값에서 현재 벽의 높이를 빼면 현재 벽에 고이는 물의 양이다.

*/

int H, W, ans;
vector<int> arr;

int main(int argc, char const *argv[]) {

  cin >> H >> W;
  for (int i = 0; i < W; i++) {
    int input;
    cin >> input;
    arr.push_back(input);
  }

  for (int i = 1; i < arr.size(); i++) {
    int L = arr[i], R = arr[i];
    for (int j = 0; j < i; j++) {
      if(L < arr[j]) L = arr[j];
    }

    for (int j = i+1; j < arr.size(); j++) {
      if(R < arr[j]) R = arr[j];
    }

    if(L == arr[i] || R == arr[i]) continue;
    ans += min(L,R) - arr[i];
  }

  cout << ans;

  return 0;
}
