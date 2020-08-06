#include <vector>
#include <algorithm>
using namespace std;
//https://programmers.co.kr/learn/courses/30/lessons/42747

/*
<H-index>
주요: 아디이어 구현
1. 내림차순 정렬을 한다.
2. 이제 정렬된 배열을 순차적으로 탐색한다.
  2-1. 내림차순으로 정렬했기 때문에 조사하는 idx가 그 citations[idx]번 이상 인용된 논문의 개수를 가진다.
  2-2. idx가 0부터 시작하므로 i+1을 값으로 한다.
3. 최대값을 리턴한다.
==========
* 문제 해석이 너무 오래걸렸다.

*/

int solution(vector<int> citations) {
  int answer = 0;
  int n = citations.size();
  sort(citations.begin(), citations.end(),[](const int &A, const int &B){return A>B;});
  for (int i = 0; i < n; i++) {
    if(citations[i] > i) answer = i+1;
  }
  return answer;
}
