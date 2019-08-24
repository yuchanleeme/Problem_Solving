/*
https://leetcode.com/problems/unique-paths/

main : 수학, DP
1. 길찾기를 이용해서 푼다.
2. 임의의 칸에 도달하려면 위에서내려오는 경우, 왼쪽에서 이동하는 경우 두가지이다.
3. 위의 조건에 맞게 배열을 채워주고 마지막에 square[n-1][m-1]을 리턴한다.

*/

class Solution {
public:
  int uniquePaths(int m, int n) {
    int square[n][m];

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if(i == 0 || j == 0){
          square[i][j] = 1;
        }
        else{
          square[i][j] = square[i-1][j] + square[i][j-1];
        }
      }
    }
    return square[n-1][m-1];
  }
};
