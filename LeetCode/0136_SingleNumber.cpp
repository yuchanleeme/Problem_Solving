/*
https://leetcode.com/problems/single-number/

main : 순차검색
1. 리스트에서 자기와 다른 idx의 리스트들과 비교한다.
1. 자기와 같은 값을 찾는다면 break를한다.
2. 만약 리스트의 마지막까지 같은 값을 못찾으면 혼자만 다른 값이므로 그 값을 리턴한다.

*/

class Solution {
public:
  int singleNumber(vector<int>& nums) {
     int res = 0;
    for (int i = 0; i < nums.size(); i++) {
      for (int j = 0; j < nums.size(); j++) {
        if(i != j && nums[i] == nums[j]){ break;}
        if(j == nums.size()-1){ res = nums[i];}
      }
    }
      return res;
  }
};
