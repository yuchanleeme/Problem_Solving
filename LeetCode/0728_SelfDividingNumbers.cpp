/*
https://leetcode.com/problems/self-dividing-numbers/

main : mod
1. 각 자리수를 digit로 갱신하면서 나눈 나머지가 0인지 확인한다.
2. 만약에 자리수가 0 이거나(0으로 나눌수 없으므로) 나눈 나머지가 0 이아니면 insert_trigger 를 false처리한다.
3. insert_trigger가 true인 i 값만 결과 벡터에 삽입한다.
4. i가 left~right 까지 조사하고 완성된 벡터를 리턴한다.

*/

class Solution {
public:
  vector<int> selfDividingNumbers(int left, int right) {

    int value, digit;
    bool insert_trigger;
    vector<int> ans;

    for (int i = left; i <= right; i++) {
      value = i;
      insert_trigger = true;
      while(value != 0){
        digit = value % 10;
        value /= 10;
        if(digit == 0 || (i % digit) != 0){
          insert_trigger = false;
          break;
        }
      }
      if(insert_trigger){
        ans.push_back(i);
      }
    }

    return ans;
  }
};
