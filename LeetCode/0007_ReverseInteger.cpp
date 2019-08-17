/*
https://leetcode.com/problems/reverse-integer/

main : 구현
1. 10으로 나눈 나머지와 현재 ans값을 더한다.
2. x를 10으로 나눈다.
3. ans 값에 10을 곱합값과 10으로 x를 나눈 나머지를 더한다.
4. x가 0이 될 때까지 1~3번 반복한다.
5. 마지막에 INT 범위를 넘어서면 0을 리턴하고 아니면 ans를 리턴한다.
=========
* 계산값이 오버플로우가 떠서 long long 변수를 새로 선언해서 비교했더니 AC받았다.

*/

class Solution {
public:
  int reverse(int x) {

    long long ans = 0, temp;

    while (x != 0) {
      temp = x % 10;
      ans *= 10;
      ans += temp
      x /= 10;
    }

    if(ans > INT_MAX || ans < INT_MIN){
      return 0;
    }
    else{
      return ans;
    }

  }
};
