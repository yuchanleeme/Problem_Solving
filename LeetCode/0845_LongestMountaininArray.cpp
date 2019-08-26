/*
https://leetcode.com/problems/longest-mountain-in-array

main : 구현
1. 증가하고 감소하는지를 확인한다.
2. 각 조건식에 맞게 분류를 한다.
  => 이전 값보다 현재 값이 크다면 증가, 반대면 감소하는 경우라 생각한다.
  => 산 한개 조사가 끝났을 때 up 과 down 둘다 했다면 ans와 크기를 비교한다.
  => 이외의 경우도 포함시켜 조사한다.

=========
* AC는 받았는데 조건식을 너무 까다롭게 세워 조금 가다듬을 필요가 있다.

*/

class Solution {
public:
  int longestMountain(vector<int>& A) {
    bool up = false, down = false;
    int ans = 0, sum = 0;
    if(A.size() < 3){
      return 0;
    }

    for (int i = 1; i < A.size(); i++) {
      if(A[i-1] < A[i]){
        // 증가(올라가는 중)
        if(up && down){
          ans = max(sum, ans);
          // 값 초기화
          sum = 0;
          down = false;
        }
        up = true;
        sum += 1;
      }
      else if(A[i-1] > A[i]){
        // 감소(내려가는 중)
        if(!up){ continue;} // 증가하지도 않았는데 감소하면 다시 진행(처음부분)
        down = true;
        sum += 1;
        if(i == A.size()-1 && (up && down)){ans = max(sum,ans);} // 마지막까지 조사했을 경우
      }
      else if(A[i-1] == A[i]){
        // 이전 값과 같을 경우
        if(up && down){ ans = max(sum, ans);} // 초기화 전까지 산의 길이
        // 값 초기화
        up = false;
        down = false;
        sum = 0;
      }
    }

    if(ans == 0){ return 0;} // ans가 0 이면 산이 없으므로
    else{ return ans +1;} // ans가 0이 아니면 초기 기준값 1 더해준다.
  }
};
