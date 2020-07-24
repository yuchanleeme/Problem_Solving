#include <vector>
#include <algorithm>
using namespace std;
//https://programmers.co.kr/learn/courses/30/lessons/12935

/*
<제일 작은 수 제거하기>
주요: 구현
1. min_element를 이용해 제일 작은 수를 찾는다.
2. arr를 순회하면서 그 수가 아니라면 answer 벡터에 넣는다.
3. answer의 크기가 0이면 -1을 넣는다.
4. 최종 answer를 리턴한다.

*/

vector<int> solution(vector<int> arr) {
  vector<int> answer;
  int min_v = *min_element(arr.begin(),arr.end());
  for(int i = 0; i< arr.size(); i++){
    if(arr[i] != min_v) answer.push_back(arr[i]);
  }
  if(answer.size() == 0) answer.push_back(-1);
  return answer;
}
