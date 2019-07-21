/*
https://leetcode.com/problems/house-robber

main : dp
1. dp를 이용하여 푼다.
2. 1,2번 째집은 따로 분류해준다.
3. 해당하는집 한칸전까지 rob했을때의 가치와 두칸전까지 rob했을때의 가치 + 해당하는 집의 가치 중 큰값을 비교한다.
4. 저장되어있는 배열 값을 출력한다.

=========
* 런타임에러가 계속 나서 배열로 선언 및 길이를 변수로 지정함

*/

class Solution {
public:
  int rob(vector<int>& nums) {
    int len = nums.size();

    if(len == 0){ return 0;}

    int dp[len];
    if(len >= 1){
      dp[0] = nums[0];
    }
    if(len >= 2){
      dp[1] = max(nums[0], nums[1]);
    }
    for(int i = 2; i < len; i++){
      dp[i] = max(dp[i-1], dp[i-2] + nums[i]);
    }

    return dp[len-1];
  }
