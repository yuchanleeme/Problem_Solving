#include <iostream>
#include <vector>
using namespace std;
//https://www.acmicpc.net/problem/1248

/*
<맞춰봐>
주요: 백트래킹
1. 백트래킹해서 모든 조합을 찾아본다.
2. 단, seq 에 들어갈 때 가능한지 한번에 조사한 뒤 삽입한다. (시간 줄이기)
  => ex)4개라면 D vs S[3][3], D+C vs S[2][3], D+C+B vs S[1][3], D+C+B+A vs S[0][3]
3. 가능한 조합 하나만 출력하고 전체 리턴해서 함수를 끝낸다.
==========
* idx 구현에 애를 먹었던 문제.
* 배열 자료구조 만들 때 2차원 이상 꼭 꼭 생각해서 구현
  => 배열 참조 idx 구현이 애매하다 싶으면 바로 2차원 이상으로 늘려서 생각해보기.
*

*/
int N;
int S[12][12];
vector<int> seq;
bool gameOver = false;
bool isRight(int num, int level){
  int sum = 0;
  for (int i = level; i >= 0; i--) {
    sum += seq[i];
    if(S[i][level] > 0 && sum <= 0) return false;
    else if(S[i][level] == 0 && sum != 0) return false;
    else if(S[i][level] < 0 && sum >= 0) return false;
  }
  return true;
}

void backtracking(int level){

  if(gameOver) return;
  if(level == N){
    for (int i = 0; i < seq.size(); i++) {
      cout << seq[i] << " ";
    }
    cout << "\n";
    gameOver = true;
    return;
  }

  for (int num = -10; num <= 10; num++) {
    seq.push_back(num);
    bool res = isRight(num, level);
    if(res) backtracking(level+1);
    seq.pop_back();
  }
}

int main(int argc, char const *argv[]) {

  cin >> N;

  for (int i = 0; i < N; i++) {
    for (int j = i; j < N; j++) {
      char input;
      cin >> input;
      if(input == '+') S[i][j] = 1;
      else if(input == '-') S[i][j] = -1;
      else S[i][j] = 0;
    }
  }

  backtracking(0);

  return 0;
}
