#include <bits/stdc++.h>
using namespace std;
//https://www.acmicpc.net/problem/17281

/*
<야구공>
주요: 구현, 백트래킹
1. 백트래킹을 이용해 순서를 정한다.
2. 순서에 맞게 야구게임을 시작해 점수의 최댓값을 갱신한다.
3. 해당 최댓값을 출력한다.
==========
* 배열 이름 visit -> gameVisit (컴파일 에러)
* baseball[10] -> baseball[100] (런타임 에러)
  => 야구길래 당연히 9이닝인줄 알아서 틀렸다.
  => 문제 입력 정보를 자세히 보자.

*/

int N, ans;
vector<int> baseball[100]; // N은 50까지이다.
vector<int> seq;
int gameVisit[11];

// 야구 시작
void gameStart() {
  int gameScore = 0, nowHitter = 0; // game점수, 현재 타자 고유 번호
  queue<int> baseInfo; // 베이스에 있는 주자들 정보

  // 이닝별 게임 시작
  for (int inning = 1; inning <= N; inning++) {
    int out = 0;
    while (true) {
      int hitRes = baseball[inning][seq[nowHitter]]; // 현재 타자 정보
      int remainBase = baseInfo.size();

      if(hitRes == 1){  //안타
        for (int qs = 0; qs < remainBase; qs++) {
          int now = baseInfo.front();
          if(now >= 3) gameScore++;
          else baseInfo.push(now+1);
          baseInfo.pop();
        }
        baseInfo.push(1);
      }
      else if(hitRes == 2){ // 2루타
        for (int qs = 0; qs < remainBase; qs++) {
          int now = baseInfo.front();
          if(now >= 2) gameScore++;
          else baseInfo.push(now+2);
          baseInfo.pop();
        }
        baseInfo.push(2);
      }
      else if(hitRes == 3){ // 3루타
        for (int qs = 0; qs < remainBase; qs++) {
          int now = baseInfo.front();
          if(now >= 1) gameScore++;
          else baseInfo.push(now+3);
          baseInfo.pop();
        }
        baseInfo.push(3);
      }
      else if(hitRes == 4){ // 홈런
        gameScore += baseInfo.size()+1;
        while (!baseInfo.empty()) baseInfo.pop();
      }
      else if(hitRes == 0){
        out++;
      }

      // 타순 교체 (seq 0~8 이므로)
      if(nowHitter == 8) nowHitter = 0;
      else nowHitter++;

      // 3out 체인지
      if(out == 3) {
        while (!baseInfo.empty()) baseInfo.pop();
        break;
      }
    }
  }
  // 최대값 갱신
  ans = max(ans, gameScore);
}

// 순서 백트래킹
void backtracking(int level){

  // 1번 선수는 4번타자
  if(level == 3){
    gameVisit[1] = 1;
    seq.push_back(1);
    backtracking(seq.size());
    seq.pop_back();
    gameVisit[1] = 0;
  }

  // 순서 정해지면 야구 시작
  if(level == 9){
    gameStart();
    return;
  }

  for (int i = 2; i <= 9; i++) {
    if(gameVisit[i] == 1) continue;
    gameVisit[i] = 1;
    seq.push_back(i);
    backtracking(seq.size());
    seq.pop_back();
    gameVisit[i] = 0;
  }
}


int main(int argc, char const *argv[]) {
  cin >> N;

  for (int i = 1; i <= N; i++) {
    baseball[i].push_back(-1); // idx 맞추기 위해 일부러 0 idx 집어넣음
    for (int j = 0; j < 9; j++) {
      int temp;
      cin >> temp;
      baseball[i].push_back(temp);
    }
  }

  // 순서 정하기
  for (int i = 2; i <= 9; i++) {
    seq.push_back(i);
    gameVisit[i] = 1;
    backtracking(seq.size());
    gameVisit[i] = 0;
    seq.pop_back();
  }

  cout << ans;

  return 0;
}
