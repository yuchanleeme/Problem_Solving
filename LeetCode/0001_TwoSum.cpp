/*
////////////////////////////////
main : Brute Force
1. 입력받은 벡터의 모든값들을 완전탐색하여 합이 target이 되는 idx를 찾는다.
2. 찾았으면 리턴할 벡터에 저장 후 for문을 탈출한다.

////////////////////////////////
*/

vector<int> twoSum(vector<int>& nums, int target) {

  int idx;
  vector<int> res;

  for(int i = 0; i < nums.size(); i++){
    for(int j = i+1; j < nums.size(); j++){
      if(nums[i] + nums[j] == target){
        res.push_back(i);
        res.push_back(j);
        i = nums.size();
        break;
      }
    }
  }
  return res;
}
