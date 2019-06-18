#include <iostream>
#include <algorithm>
using namespace std;
//https://www.acmicpc.net/problem/11404

/*
<플로이드>
주요: 그래프 - 플로이드 워셜 알고리즘
1. 플로이드 워셜알고리즘을 이용한다.
2. 문제 조건에 맞게 배열을 초기화 해준다.
3. 입력 간선이 중복 되었을 시 그 중 최솟값을 저장한다.
4. ans[i][j] > ans[i][p] + ans[p][j]
  => i에서 다이렉트로 j로 가는 경우와 p라는 경유지를 거쳐서 가는 경우를 비교한다. (최솟값 저장)
  => 모든 경유지(P)의 경우에 대해 조사한다.

*/
const int MAX = 100001;

int main() {

  int n, m, start, goal, price;

  cin >> n >> m;

  int ans[110][110];

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if(i != j){
        ans[i][j] = MAX;
      }
    }
  }

  for (int i = 0; i < m; i++) {
    cin >> start >> goal >> price;
    if(!ans[start-1][goal-1]){
      ans[start-1][goal-1] = price;
    }
    else{
      ans[start-1][goal-1] = min(ans[start-1][goal-1], price);
    }
  }

  for (int p = 0; p < n; p++) {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if(ans[i][j] > ans[i][p] + ans[p][j]){
          ans[i][j] = ans[i][p] + ans[p][j];
        }
      }
    }
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if(ans[i][j] == MAX){
        cout << "0" << " ";
      }
      else{
        cout << ans[i][j] << " ";
      }
    }
    cout << endl;
  }

  return 0;
}
