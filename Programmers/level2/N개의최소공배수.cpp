#include <bits/stdc++.h>
using namespace std;
//https://programmers.co.kr/learn/courses/30/lessons/12953

/*
<N개의 최소 공배수>
주요: 수학
1. 2~50으로 계속 나누고 나누어 떨어진다면 그 몫을 arr에 다시 저장시킨다.
2. 나누어 떨어진다면 answer에 그 값을 계속 곱해준다.
3. 최종적으로 arr값들을 answer에 곱하고 그 값을 리턴한다.

*/
int solution(vector<int> arr) {
  int answer = 1;

  while (true) {
    bool gameEnd = false;

    for (int i = 2; i <= 50; i++) {
      bool check = false;

      for (int j = 0; j < arr.size(); j++) {
        if(arr[j] % i == 0){
          check = true;
          arr[j] /= i;
        }
      }
      if(check){
        answer *= i;
        break;
      }
      if(i == 50) gameEnd = true;
    }
    if(gameEnd) break;
  }

  for (int i = 0; i < arr.size(); i++) {
    answer *= arr[i];
  }
  return answer;
}
