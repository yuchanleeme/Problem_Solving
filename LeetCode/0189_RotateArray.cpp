/*
////////////////////////////////
main : deque
1. 앞뒤에 값을 추가 할 수 있는 자료구조인 덱을 응용해서 문제를 풀었다.
2. 덱을 이용해 rotate를 돈 뒤 값을 다시 저장하는 방식을 이용했다.

////////////////////////////////
*/

class Solution {
public:
  void rotate(vector<int>& nums, int k) {

    int size = nums.size();
    deque<int> dq;

    for (int i = 0; i < size; i++) {
      dq.push_back(nums[i]);
    }

    for (int i = 0; i < k; i++) {
      dq.push_front(dq.back());
      dq.pop_back();
    }

    nums.clear();
    for (int i = 0; i < size; i++) {
      nums.push_back(dq.front());
      dq.pop_front();
    }
  }
};
