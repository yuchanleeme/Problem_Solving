/*
////////////////////////////////
main : Brute Force
1.

////////////////////////////////
*/

class Solution {
public:
  int reverse(int x) {

    int trigger, ans = 0, num = 0, idx = 0;
    int INT_MAX = 2147483647;
    int multiple = 1;

    while (x != 0) {
      digit[idx] = x % 10;
      x /= 10;
      idx++;
    }

    for (int i = idx-1; i >= 0; i--) {
      if(ans > )
      ans += digit[i] * multiple;
      multiple *= 10;
    }

    return ans * trigger;
  }
};
