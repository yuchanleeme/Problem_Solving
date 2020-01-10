#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
//https://www.acmicpc.net/problem/11931

/*
<수 정렬하기 4>
주요: 정렬
1. nums에 값들을 입력받는다.
2. compare 함수를 만들어 내림차순 정렬을 할수 있게 한다.
3. sort 함수와 compare 함수를 이용해 nums 벡터를 정렬한다.

*/

bool compare(const int &a, const int &b){
  return b < a;
}

int main() {

  int N;
  cin >> N;

  vector<int> nums;

  for (int i = 0; i < N; i++) {
    int input;
    cin >> input;
    nums.push_back(input);
  }

  sort(nums.begin(), nums.end(), compare);

  for (int i = 0; i < N; i++) {
    cout << nums[i] << '\n';
  }

  return 0;
}
