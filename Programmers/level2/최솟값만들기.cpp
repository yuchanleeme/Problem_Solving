#include <bits/stdc++.h>
using namespace std;
//https://programmers.co.kr/learn/courses/30/lessons/12941

/*
<최솟값 만들기>
주요: 정렬
1. A의 최솟값과 B의 최댓값을 연속해서 곱하면 된다.
2. 최종 결과를 리턴한다.

*/

bool comp(const int &A, const int &B){
  return A > B;
}

int solution(vector<int> A, vector<int> B){

  int answer = 0;

  sort(A.begin(), A.end());
  sort(B.begin(), B.end(), comp);

  for (int i = 0; i < A.size(); i++) {
    answer += A[i] * B[i];
  }

  return answer;
}
