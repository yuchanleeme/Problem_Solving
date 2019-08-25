/*
https://leetcode.com/problems/maximum-product-of-three-numbers

main : 정렬
1. sort함수를 이용해 nums를 정렬한다.
2. 정렬된 nums 안에서 2가지값을 비교한다.
  2-1) 가장 큰 수, 두번째 큰수 ,세번째 큰수를 곱한 값 (+ + +)
  2-2) 음수가 포함될수 있으므로 가장 작은수, 그 다음 작은수, 가장 큰수 를 곱해야 절댓값이 가장 큰 양수가 된다.(- - +)
3. 두 값중에 큰 수를 리턴한다.
=========
* 백트래킹, 3중for문을 썼는데 시간초과가 떠서 정렬을 이용해 풀었다.

*/

class Solution {
public:
  int maximumProduct(vector<int>& nums) {
    sort(nums.begin(),nums.end());
    int idx = nums.size()-1;
    int max_value = max(nums[idx] * nums[idx-1] * nums[idx-2], nums[0] * nums[1] * nums[idx]);
    return max_value;
  }
};
