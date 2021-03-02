#include <bits/stdc++.h>
using namespace std;
//https://www.acmicpc.net/problem/1037

/*
<약수>
주요: 수학
1. 우선 입력 받은 약수를 오름차순으로 정렬한다.
2. 진짜 약수의 개수가 홀수, 짝수 일때를 주목한다.
3. 짝수면 양 끝 값을 곱해줘 출력한다.
4. 홀수이면 제곱수이기 때문에 가운데 값을 제곱해 출력한다.

*/

vector<int> nums;
int main(int argc, char const *argv[]) {

  int number; cin >> number;
  for (int i = 0; i < number; i++) {
    int temp; cin >> temp;
    nums.push_back(temp);
  }

  sort(nums.begin(), nums.end());

  if(number % 2 == 0){
    cout << nums[0]*nums.back();
  }
  else{
    cout << nums[(number-1)/2]*nums[(number-1)/2];
  }
  return 0;
}
