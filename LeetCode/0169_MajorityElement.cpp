/*
https://leetcode.com/problems/majority-element/submissions/

main : map
1. nums의 원소들에 접근할때마다 map에 추가해주고 값을 올려준다.
2. 올려주는 김에 member 벡터에 값을 삽입해준다.
3. mums의 원소들을 다 조사했으면 member들을 비교해서 가장 큰 값을 출력한다.
=========


*/

class Solution {
public:
  int majorityElement(vector<int>& nums) {
    map<int, int> m;
    vector<int> member;
    int ans, maxValue = 0;

    for (int i = 0; i < nums.size(); i++) {
      m[nums[i]]++;
      member.push_back(nums[i]);
    }

    for (int i = 0; i < member.size(); i++) {
      if(maxValue < m[member[i]])
      {
        ans = member[i];
        maxValue = m[member[i]];
      }
    }

    return ans;
  }
};
