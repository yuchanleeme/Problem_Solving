#include <bits/stdc++.h>
using namespace std;
//https://programmers.co.kr/learn/courses/30/lessons/1835

/*
<단체사진 찍기>
주요: DFS, 브루트 포스
1. 우선 캐릭터를 줄 세우는 총 경우의 수를 찾는다. (경우의 수 : 8!)
2. 각 경우의 수에서 data의 모든 조건을 만족하는지 찾는다.
3. 가능한 경우를 모두 구해서 결과값을 리턴한다.
==========
* 논리가 다 맞는데 계속 통과를 못했었다.
  => 전역변수를 사용할 시 함수 안에서 초기화를 해줘야한다.

*/

int answer;
vector<string> Data;
vector<char> seq;
char mem[8] = {'A', 'C', 'F', 'J', 'M', 'N', 'R', 'T'};
int visit[8];

void dfs(int level){

  if(seq.size() == 8){
    for (int i = 0; i < Data.size(); i++) {
      // 첫째, 둘째 캐릭터 위치 찾기
      int one = 0, two = 0;
      for (int j = 0; j < 8; j++) {
        if(Data[i][0] == seq[j]) one = j;
        if(Data[i][2] == seq[j]) two = j;
      }

      // 사이 간격과 dat의 target 값 설정
      int gap = abs(one-two)-1;
      int target = Data[i][4]-'0';

      // 조건에 맞지 않으면 리턴
      if(Data[i][3] == '='){
        if(gap != target) return;
      }
      else if(Data[i][3] == '>'){
        if(gap <= target) return;
      }
      else if(Data[i][3] == '<'){
        if(gap >= target) return;
      }
    }
    // 조건이 다맞아야 값 증가하고 리턴
    answer++;
    return;
  }

  // DFS
  for (int i = 0; i < 8; i++) {
    if(visit[i] == 0){
      visit[i] = 1;
      seq.push_back(mem[i]);
      dfs(level+1);
      visit[i] = 0;
      seq.pop_back();
    }
  }
}

int solution(int n, vector<string> data) {
  // 전역변수를 위한 초기화
  Data = data;
  answer = 0;
  for(int i = 0; i < 8; i++)
    visit[i] = 0;
  seq = vector<char>();

  dfs(0);

  return answer;
}
