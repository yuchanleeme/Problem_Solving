#include <vector>
#include <algorithm>
using namespace std;
//https://programmers.co.kr/learn/courses/30/lessons/12982

/*
<예산>
주요: 그리디
1. 오름 차순으로 정렬한다.
2. idx 0부터 시작해서 최대로 가지게 되었을때 그때의 idx를 리턴한다.

*/

int solution(vector<int> d, int budget) {
  int answer = 0;
  int sum = 0;
  sort(d.begin(),d.end());
  for (int i = 0; i < d.size(); i++) {
    if(sum + d[i] > budget) return i;
    sum += d[i];
  }
  return d.size();
}
