/*
https://leetcode.com/problems/binary-search/

main : 이분탐색
1. 이분탐색을 구현하자
2. 범위의 left, right를 지정해놓고 mid를 기준으로 target을 비교한다.
  => mid와 같은값 : mid의 idx 리턴한다.
  => mid보다 큰 값 : left를 mid+1로 설정해 범위를 축소시킨다.
  => mid보다 작은 값 : right를 mid-1로 설정해 범위를 축소시킨다.
3. left가 right보다 작거나 같을 때까지 조건문 중단한다. (범위 뒤집힘)
  => 이러면 찾는 값이 없음로 -1을 리턴한다.

*/

class Solution {
public:
  int search(vector<int>& nums, int target) {
    int mid, left = 0, right = nums.size() - 1;
    while (left <= right) {
      mid = (left + right) / 2;
      if(nums[mid] == target){
        return mid;
      }
      else if(nums[mid] < target){
        left = mid+1;
      }
      else if(nums[mid] > target){
        right = mid-1;
      }
    }
    return -1;
  }
};
