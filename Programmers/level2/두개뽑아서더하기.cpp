#include <bits/stdc++.h>
using namespace std;
//https://programmers.co.kr/learn/courses/30/lessons/68644

/*
<두 개 뽑아서 더하기>
주요: set, 정렬
1. 일단 모든 경우의 수를 set에 넣는다. (중복 제거)
2. answer에 set의 원소를 모두 넣고 정렬한다.
3. answer를 리턴한다.

*/

vector<int> solution(vector<int> numbers) {
  vector<int> answer;
  set<int> temp;
  for(int i = 0; i < numbers.size(); i++){
    for(int j = i+1; j < numbers.size(); j++){
      temp.insert(numbers[i]+numbers[j]);
    }
  }
  for(auto it = temp.begin(); it != temp.end(); it++){
    answer.push_back(*it);
  }
  sort(answer.begin(), answer.end());

  return answer;
}
