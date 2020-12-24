#include <bits/stdc++.h>
using namespace std;
//https://www.acmicpc.net/problem/3048

/*
<개미>
주요: 구현, 시뮬레이션
1. 시뮬레이션하듯이 1초씩 최신화를 시킨다.
2. 시뮬레이션
  2-1. 앞에서 부터 최신화를 시킨다.
  2-2. 다음 차례의 개미가 다른 값을 가진다면 자리를 바꾸고 idx를 증가시킨다.
  2-3. 나머지 경우는 현재 상태 그대로 유지한다.

*/

int N1, N2, T;
string x, y;
pair<string, int> res[60][30];
int main(int argc, char const *argv[]) {

  cin >> N1 >> N2 >> x >> y >> T;

  for (int i = 0; i < N1; i++) {
    res[0][N1-(i+1)].first = x[i];
    res[0][i].second = 1;
  }

  for (int i = 0; i < N2; i++) {
    res[0][N1+i].first = y[i];
    res[0][N1+i].second = 2;
  }

  for (int i = 0; i <= T; i++) {
    for (int j = 0; j < N1+N2; j++) {

      if(j == N1+N2-1){
        res[i+1][j].first = res[i][j].first;
        res[i+1][j].second = res[i][j].second;
      }
      else if(res[i][j].second == 1 && res[i][j].second != res[i][j+1].second){
        res[i+1][j+1].first = res[i][j].first;
        res[i+1][j].first = res[i][j+1].first;
        res[i+1][j+1].second = res[i][j].second;
        res[i+1][j].second = res[i][j+1].second;
        j++;
      }
      else{
        res[i+1][j].first = res[i][j].first;
        res[i+1][j].second = res[i][j].second;
      }
    }
  }
  for (int k = 0; k < N1+N2; k++) {
    cout << res[T][k].first;
  }
  return 0;
}
