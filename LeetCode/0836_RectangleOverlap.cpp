/*
https://leetcode.com/problems/rectangle-overlap

main : math
1. 겹치는 경우와 안 겹치는 경우 중 적은 경우의 수를 찾는다.
2. 안겹칠 때의 경우를 찾는게 더 적기에 안겹칠때 경우를 찾는다.
3. 안겹치는 경우:
  -> B직사각형의 x좌표가 A 직사각형보다 모두 작거나, 모두 클 때
  -> B직사각형의 y좌표가 A 직사각형보다 모두 작거나, 모두 클 때
4. 이 경우를 제외하고는 겹친다 생각하고 true, false를 상황에 맞게 리턴한다.
  
*/

class Solution {
public:
  bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {

    bool is_x = true, is_y = true;

    // x좌표의 위치
    if(rec2[2] <= rec1[0] || rec2[0] >= rec1[2]){
      is_x = false;
    }

    // y좌표의 위치
    if(rec2[3] <= rec1[1] || rec2[1] >= rec1[3]){
      is_y = false;
    }

    if(is_x && is_y){
      return true;
    }
    else{
      return false;
    }

  }
};
