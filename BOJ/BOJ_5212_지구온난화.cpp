#include <bits/stdc++.h>
using namespace std;
//https://www.acmicpc.net/problem/5212

/*
<지구온난화>
주요: 구현
1. 가라앉는 땅들과 가라앉지 않는 땅들의 좌표를 먼저 찾는다.
2. 가라앉는 땅들은 . 표시로 초기화 해준다.
3. 새 직사각형의 row, col 값을 계산해 출력해준다.
  => 정렬을 이용한다.

*/

int R, C;
int board[15][15]; // 0 은 바다
int Rst, Red, Cst, Ced;
int tx[4] = {-1,0,1,0}, ty[4] = {0,1,0,-1};

vector<pair<int, int> > sink; // 가라앉는 섬 좌표
vector<pair<int, int> > land; // 남아있는 땅 좌표

// 가라앉을 지 판단
bool check_land(int row, int col){
  int count = 0;
  for (int i = 0; i < 4; i++) {
    if(board[row+tx[i]][col+ty[i]] == 0) count++;
  }
  if(count >= 3) return true;
  else return false;
}

// 출력할 직사각형의 행 알아낼 때
bool comp(const pair<int, int> &A, const pair<int, int> &B){
  return  A.second < B.second;
}

int main(int argc, char const *argv[]) {

  cin >> R >> C;
  // 편의를 위해 int 배열로 만들어 버림
  for (int i = 1; i <= R; i++) {
    string str;
    cin >> str;
    for (size_t j = 1; j <= str.length(); j++) {
      if(str[j-1] == 'X') board[i][j] = 1;
    }
  }

  // 가라앉을 지 판단해서 sink, land 넣기
  for (int i = 1; i <= R; i++) {
    for (int j = 1; j <= C; j++) {
      if(board[i][j] == 0) continue;
      if(check_land(i, j) == true){
        sink.push_back({i,j});
      }
      else{
        land.push_back({i,j});
      }
    }
  }

  // 가라앉는 땅 초기화
  for (size_t i = 0; i < sink.size(); i++) {
    board[sink[i].first][sink[i].second] = 0;
  }

  // 새 직사각형의 Row값 계산
  Rst = land[0].first;
  Red = land[land.size()-1].first;

  // 새 직사각형의 Col값 계산
  sort(land.begin(), land.end(),comp);
  Cst = land[0].second;
  Ced = land[land.size()-1].second;

  // 직사각형 출력
  for (int i = Rst; i <= Red; i++) {
    for (int j = Cst; j <= Ced; j++) {
      if(board[i][j] == 0) cout << ".";
      else cout << "X";
    }
    cout << "\n";
  }

  return 0;
}
