#include <bits/stdc++.h>
using namespace std;
//https://www.acmicpc.net/problem/17952

/*
<과제는 끝나지 않아>
주요: 구현, 스택
1. 가장 최근에 했던 과제를 기억한다고 했으니 스택을 쓴다.
  => 처음 스택에 과제가 없을 때도 {0,0}을 넣어준다.
  => {0,0} 을 넣기 때문에 결과에는 영향을 안끼친다.
2. 조건에 맞게 구현한다.
3. 최종 점수를 출력한다.

*/

int N, ans;
int remainTime, score;
stack<pair<int, int> > stk;
pair<int, int> now;

int main(int argc, char const *argv[]) {
  cin.tie(NULL);
  ios::sync_with_stdio(false);
  cin >> N;

  // 학기 시작
  while (N--) {
    int num, A, T;
    cin >> num;
    if(num == 1){
      cin >> A >> T;
      stk.push({score, remainTime}); // 현재 과제 정보
      score = A;
      remainTime = --T;
    }
    else{
      remainTime--;
    }

    // 과제 끝났으면 점수및 다음 과제 최신화
    if(remainTime <= 0){
      ans += score;
      score = 0;
      if(!stk.empty()){
        score = stk.top().first;
        remainTime = stk.top().second;
        stk.pop();
      }
    }
  }

  cout << ans;

  return 0;
}
