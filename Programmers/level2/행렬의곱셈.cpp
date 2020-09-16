#include <bits/stdc++.h>
using namespace std;
//https://programmers.co.kr/learn/courses/30/lessons/12949

/*
<행렬의 곱셈>
주요: 수학
1. A x B 행렬과 B x C 행렬을 곱하면 A x C 행렬이 만들어지는 것을 이용한다.
2. A x C 행렬의 자리를 먼저 만들어준다. (벡터 배정)
3. 각 성분끼리의 곱을 answer의 행렬 각 위치의 누적으로 더해준다는 느낌으로 구현한다.

*/

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {

  int row1 = arr1.size(), col1 = arr1[0].size(), col2 = arr2[0].size();
  vector<vector<int>> answer(row1, vector<int>(col2, 0));

  for (int i = 0; i < row1; i++) {
    for (int j = 0; j < col1; j++) {
      for (int k = 0; k < col2; k++) {
        answer[i][k] += arr1[i][j] * arr2[j][k];
      }
    }
  }
  return answer;
}
