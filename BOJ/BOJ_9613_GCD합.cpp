#include <iostream>
#include <vector>
using namespace std;
//https://www.acmicpc.net/problem/9613

/*
<GCD 합>
주요: 최대공약수
1. 모든 쌍의 최대공약수를 구해서 더한다.
2. 최대공약수 구하는 것은 유클리드 알고리즘을 이용한다.

*/

int gcd(int a, int b){

  if(b == 0){
    return a;
  }
  else{
    return gcd(b, a%b);
  }
}

int main() {

  int T;
  cin >> T;

  for (int testcase = 0; testcase < T; testcase++) {
    int N;
    cin >> N;

    vector<int> nums;
    for (int i = 0; i < N; i++) {
      int input;
      cin >> input;
      nums.push_back(input);
    }

    long long ans = 0;
    for (int i = 0; i < N; i++) {
      for (int j = i+1; j < N; j++) {
        ans += gcd(nums[i],nums[j]);
      }
    }
    cout << ans << '\n';
  }
  return 0;
}
