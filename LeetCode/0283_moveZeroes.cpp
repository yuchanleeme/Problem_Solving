/*
////////////////////////////////
main : 완전 탐색
1. 0을 차례대로 찾되, 0을 발견시 그 다음 idx들을 조사해 0이 아닌값과 swap해준다.
2. swap이 끝났으면 다음 진행을 위해 break 한다.  

////////////////////////////////
*/

class Solution {
public:
  void moveZeroes(vector<int>& nums) {

    for (int i = 0; i < nums.size(); i++) {
      if(nums[i] == 0){
        for (int j = i; j < nums.size(); j++) {
          if(nums[j] != 0){
            swap(nums[i], nums[j]);
            break;
          }
        }
      }
    }
};
