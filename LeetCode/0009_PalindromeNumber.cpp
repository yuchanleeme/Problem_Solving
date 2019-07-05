/*
////////////////////////////////
main : 조건에 맞게 조사한다.
1. 입력 받은 값이 음수이면 false 리턴, 1자리수 이면 true 리턴
2. 각 자리수를 digit 벡터에 저장
3. digit 벡터 안에 대칭되는 idx값들을 비교해서 회문인지 조사한다.
  => 시간 효율을 높이기 위해 총 idx의 반만 조사한다.
  
////////////////////////////////
*/

class Solution {
public:
  bool isPalindrome(int x) {

    vector<int> digit;
    bool trigger = true;

    if(x < 0){ return false;}
    else if(x < 10){ return true;}

    while (x != 0) {
      digit.push_back(x % 10);
      x /= 10;
    }

    for (int i = digit.size()-1; i >= digit.size()/2; i--) {
      if(digit[i] != digit[digit.size()-(i+1)]){
        trigger = false;
      }
    }

    return trigger;
  }
};
