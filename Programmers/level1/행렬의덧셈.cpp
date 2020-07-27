#include <string>
#include <vector>
//https://programmers.co.kr/learn/courses/30/lessons/12950

/*
<행렬의 덧셈>
주요: 구현
1. 배열 두개를 더한다고 생각하면 된다.
2. 결과 배열의 N,M을 지정한 뒤 더해주면 된다.

*/

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
  int N = arr1.size();
  int M = arr1[0].size();
  vector<vector<int>> answer(N, vector<int>(M, 0));
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      answer[i][j] = arr1[i][j] + arr2[i][j];
    }
  }
  return answer;
}
