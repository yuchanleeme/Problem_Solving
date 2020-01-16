#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
//https://www.acmicpc.net/problem/2643

/*
<가장 긴 바이토닉 부분 수열>
주요: DP
1. 앞에서 부터 뒤로 가면서 증가하는 부분 수열의 개수를 센다.
2. 뒤에서 부터 앞으로 오면서 증가하는 부분 수열의 개수를 센다.
  => 계산된 값은 앞에서 본다면 감소하는 부분 수열이 됨
3. 각자 계산된 수열의 값을 idx 단위로 합한다.
4. 중복되는 값 1을 제외한 것중 제일 큰 것이 가장 긴 바이토닉 부분 수열이다.

*/

int dp_L[1001];
int dp_R[1001];
int arr[1001];

int main() {

  int N;
  cin >> N;

  for (int i = 0; i < N; i++) {
    cin >> arr[i];
  }

  // 1번
  for (int i = 0; i < N; i++) {
    dp_L[i] = 1;

    for (int j = 0; j < i; j++) {
      if(arr[j] < arr[i]){
        dp_L[i] = max(dp_L[i], dp_L[j]+1);
      }
    }
  }

  // 2번
  for (int i = N-1; i >= 0; i--) {
    dp_R[i] = 1;

    for (int j = i-1; j < N; j++) {
      if(arr[j] < arr[i]){
        dp_R[i] = max(dp_R[i], dp_R[j]+1);
      }
    }
  }

  int res = 0;

  for (int i = 0; i < N; i++) {
    res = max(res, dp_L[i]+dp_R[i]);
  }
  cout << res -1;

  return 0;
}
