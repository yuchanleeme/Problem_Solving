#include <bits/stdc++.h>
using namespace std;
//https://programmers.co.kr/learn/courses/30/lessons/42578

/*
<위장>
주요: 해쉬맵, 아이디어 구현
1. 최대 크기로 생각하면 된다.
  ex) 5, 3, 2 의 각 옷의 종류가 있다면 0~6, 0~3, 0~2 조합이면 된다.
    => 0이면 안 입었다고 치면 된다.
    => 즉, (0~5), (0~3), (0~2) 이기에 총 조합 수는 (5+1)*(4+1)*(3+1) -1 이다.
    => 하나 빼는 이유는 (0,0,0) 조합일때이기 때문인다.
2. 1번 조건에 맞게 각 개수를 해쉬맵으로 세서 곱셉을 해주면 된다.    
==========
* 백트래킹으로 조합을 다 찾아서 구했지만 시간 초과가 떴다.
* 굳이 모든 조합을 구할 필요가 없었다.

*/

unordered_map<string, int> mp;
vector<int> seq;
int solution(vector<vector<string>> clothes) {
  int answer = 1;
  for(int i = 0; i < clothes.size(); i++){
    if(mp.find(clothes[i][1]) == mp.end()){
      mp.insert({clothes[i][1],seq.size()});
      seq.push_back(1);
    }
    else
      seq[mp.find(clothes[i][1])->second]++;
  }

  for(int i = 0; i < seq.size(); i++){
    answer *= (seq[i]+1);
  return answer-1;
}