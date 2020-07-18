#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/*
https://leetcode.com/problems/sort-integers-by-the-power-value/

main : dp, 구현
1. 단순하게 읻단 조건식에 맞게 power value를 찾아나간다. (while문 이용)
2. 계산된 res 값을 dp배열에 저장하고, 이미 저장되어있다면 그값을 더해주고 while문을 나간다.
3. 루프를 돌면서 power value와 idx를 새로운 벡터에 저장시키고 정렬한다.
4. 그 벡터의 k번째 idx 원소 중 idx 값을 리턴한다.
=========
* 사실 dp로 안풀어도 AC 받는다. 그냥 하나씩 다 계산해줘도 시간 초과는 안 뜬다.
* 오히려 DP로 푸려고 하다가 dp 배열 런타임에러가 계속 떴다.

*/

class Solution {
public:
  int dp[401010] = {0,};
  int getKth(int lo, int hi, int k) {
    vector<pair<int, int> > ans;
    for (int i = lo; i <= hi; i++) {
      int res = 0;
      int num = i;
      while(num != 1){
        if(num > 201000) cout << i;
        if(dp[num]){
          res += dp[num];
          break;
        }
        if(num % 2 == 0){
          num /= 2;
          res++;
        }
        else{
          num = num*3 + 1;
          res++;
        }
      }
      dp[i] = res;
      ans.push_back({dp[i], i});
    }
    sort(ans.begin(), ans.end());

    return ans[k-1].second;
  }
};
