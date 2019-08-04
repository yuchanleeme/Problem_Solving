#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
//https://www.acmicpc.net/problem/14889

/*
<스타트와 링크>
주요: DFS, 백트래킹
1. 중복을 막기 위해 1을 기준으로 1과 팀이 되는 명단을 찾아 team_a에 넣는다.
  => team 하나당 인원은 N/2 이므로 N/2만큼만 백트래킹해서 찾는다.
2. team_a 명단을 찾으면 자연스레 나머지 명단이 team_b이므로 그 명단을 team_b에 넣는다.
3. 조건에 맞게 각 팀의 점수를 계산하고 그 차이를 계산한다.
4. 그 중 최소값을 출력한다.

*/

int N, minValue;
vector<vector<int> > marks;
vector<int> team_a;
vector<int> visit;
bool first_value = true;

int cal_min(){

  int score_a = 0, score_b = 0;
  int idx = 0;
  vector<int> team_b;

  // 2번
  for (int i = 0; i < N; i++) {
    if(team_a[idx] == (i+1) ){
      idx++;
    }
    else{
      team_b.push_back(i+1);
    }
  }

  // 3번
  for (int i = 0; i < N/2; i++) {
    for (int j = 0; j < N/2; j++) {
      if(i != j){
        score_a += marks[team_a[i]][team_a[j]];
      }
    }
  }

  for (int i = 0; i < N/2; i++) {
    for (int j = 0; j < N/2; j++) {
      if(i != j){
        score_b += marks[team_b[i]][team_b[j]];
      }
    }
  }

  return abs(score_a - score_b);
}

void back_tracking(int level, int max){

  if(level == N/2){
    if(first_value){
      minValue = cal_min();
      first_value = false;
    }
    else{
      minValue = min(minValue, cal_min());
    }
    return;
  }

  for (int i = max; i <= N; i++) {
    if(visit[i] == 0){
      team_a.push_back(i);
      visit[i] = 1;
      back_tracking(level+1, i);
      visit[i] = 0;
      team_a.pop_back();
    }
  }
}

int main() {

  cin >> N;

  visit = vector<int>(N+1, 0);
  marks = vector<vector<int> >(N+1, vector<int>(N+1, 0));

  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= N; j++) {
      cin >> marks[i][j];
    }
  }

  team_a.push_back(1);
  back_tracking(1, 2);

  // 4번
  cout << minValue;

  return 0;
}
