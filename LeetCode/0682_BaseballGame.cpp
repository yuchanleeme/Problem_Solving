/*
https://leetcode.com/problems/baseball-game

main : 구현, 스택
1. 숫자 : 포인트를 스택에 넣는다.
2. "+" : 유효한 이전 2개의 포인트 값을 더해준다.
3. "D" : 유효한 바로 이전 포인트값을 2배해서 더해준다.
4. "C" : 이전 더했던 유효했던 포인트값을 비유효하게한다.

*/

class Solution {
public:
  int calPoints(vector<string>& ops) {
    int sum = 0 ,firstValue = 0, secondValue = 0;
    int temp;
    stack<int> stk;
    for (int i = 0; i < ops.size(); i++) {
      if(ops[i] == "+"){
        secondValue = stk.top();
        stk.pop();
        firstValue = stk.top();
        stk.pop();
        temp = firstValue + secondValue;
        sum += temp;
        stk.push(firstValue);
        stk.push(secondValue);
        stk.push(temp);
      }
      else if(ops[i] == "C"){
        sum -= stk.top();
        stk.pop();
      }
      else if(ops[i] == "D"){
        temp = stk.top() * 2;
        sum += temp;
        stk.push(temp);
      }
      else{
        stk.push(stoi(ops[i]));
        sum += stk.top();
      }
    }
    return sum;
  }
};
