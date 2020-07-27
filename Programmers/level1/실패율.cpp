#include <vector>
#include <algorithm>
using namespace std;
//https://programmers.co.kr/learn/courses/30/lessons/42889

/*
<실패율>
주요: 구현
1. 레벨별로 그 레벨까지 머무는 플레이어의 수를 counting해서 배열로 저장한다.
2. 그 후 각 레벨까지 도달한 player를 구하고, 실패율을 구하여 새로운 벡터(pair)에 넣는다.
3. 실패율로 정렬하되, 문제 조건에 맞게 정렬하여 리턴한다.
===========
* 0으로 나누는 부분 예외처리를 꼭 생각해야한다.
  => 컴파일러들 중 일부는 이걸 자동 예외처리해줘서 IDE에서 풀면 모를 수 있음

*/

bool comp(const pair<double, int> &A, const pair<double, int> &B){
  if(A.first == B.first){
    return A.second < B.second;
  }
  return A.first > B.first;
}

vector<int> solution(int N, vector<int> stages) {
  vector<int> counting (N+2, 0);
  vector<pair<double,int> > res;
  vector<int> answer;
  for (int i = 0; i < stages.size(); i++) {
    counting[stages[i]]++;
  }

  int player = stages.size();
  for (int i = 1; i <= N ; i++) {
    player -= counting[i-1];
    double temp;
    if(player == 0) temp = 0;
    else temp = (double)counting[i]/player;
    res.push_back({temp, i});
  }
  sort(res.begin(), res.end(), comp);

  for (int i = 0; i < res.size(); i++) {
    answer.push_back(res[i].second);
  }
  return answer;
}
