/*
https://leetcode.com/problems/letter-combinations-of-a-phone-number/

main : 백트래킹
1. 백트래킹을 이용해 풀이한다.
2. ex) "23"이면 2가 입력받으면 3을 입력받는 방식을 이용 (백트래킹 함수 인자 : int x)
3. digits[i] - '0' 을 이용해서 digits의 idx를 하나씩 순서대로 지정 가능.

=========

*/

class Solution {
public:
  int number;
  string str;
  vector<string> ans;
  vector<string> base = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

  void back_tracking(int level, int x, string &digits){

    if(level == number){
      ans.push_back(str);
      return;
    }

    for (int i = x; i < digits.size(); i++) {
      for (int j = 0; j < base[digits[i] - '0'].size(); j++) {
        str += base[digits[i] - '0'][j];
        back_tracking(level+1, i+1, digits);
        str.pop_back();
      }
    }
  }

  vector<string> letterCombinations(string digits) {
    number = digits.size();
    if(number != 0){
      back_tracking(0, 0, digits);
    }
    return ans;
  }
};
