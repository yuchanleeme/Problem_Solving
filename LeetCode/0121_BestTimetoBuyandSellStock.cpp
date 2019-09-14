/*
https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

main : 브르투포스
1. 벡터에서 순차적으로 두개의 값을 골라 차를 구한다.(뒤 - 앞)
2. 모든 경우를 해보았을때 0보다 큰 값들 중 가장 큰 값을 구한다.

=========
* 시간복잡도가 높은 풀이법이므로 재풀이 예정

*/

class Solution {
public:
  int maxProfit(vector<int>& prices) {
    int ans = 0;
    for(int i = 0; i < prices.size(); i++){
      for (int j = i+1; j < prices.size(); j++) {
        ans = max(ans, prices[j]-prices[i]);
      }
    }
    return ans;
  }
};
