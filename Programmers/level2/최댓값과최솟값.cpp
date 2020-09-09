#include <bits/stdc++.h>
using namespace std;
//https://programmers.co.kr/learn/courses/30/lessons/12939

/*
<최댓값과 최솟값>
주요: 문자열
1. -를 기준으로 문자열을 따로 split한다.
2. 해당 숫자를 벡터에 넣고 정렬한다.
3. 최대, 최솟값을 리턴한다.

*/

string solution(string s) {

  vector<int> nums;
  for (int i = 0; i < s.length(); i++) {
    if(s[i] == '-'){
      i++;
      int temp = 0;
      while(s[i] >= '0' && s[i] <= '9'){
        temp *= 10;
        temp += s[i] - '0';
        i++;
      }
      nums.push_back(temp*-1);
    }
    else{
      int temp = 0;
      while(s[i] >= '0' && s[i] <= '9'){
        temp *= 10;
        temp += s[i] - '0';
        i++;
      }
      nums.push_back(temp);
    }
  }
  sort(nums.begin(), nums.end());
  string answer = to_string(nums[0]) + " " + to_string(nums[nums.size()-1]);
  return answer;
}
