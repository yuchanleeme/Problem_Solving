#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
//https://www.acmicpc.net/problem/2643

/*
<색종이 올려 놓기>
주요: DP
1. 넓이가 큰 순서대로 색종이를 정렬 한다.
2. isInside 함수로 앞에 색종이가 색종이 안에 들어 가는지 판단한다.
  2-1) 가로, 세로 길이가 모두 A > B인지 조사한다.
  2-2) 90도 돌렸을 때도 고려한다.
3. isInside 함수로 조건을 판단하며 DP를 쓴다.
4. dp[i] : i번째 색종이를 마지막으로 선택했을때까지의 제일 많이 올려 놓을 수 있는 색종이의 수
5. dp 배열중 최대값을 출력한다.  

*/

vector<pair<int, int> > paper;
int dp[101];

bool comp(const pair<int, int> &A, const pair<int, int> &B){

  return A.first*A.second > B.first*B.second;
}

bool isInside(pair<int, int> A, pair<int, int> B){

  if(A.first >= B.first && A.second >= B.second){
    return true;
  }
  else if(A.first >= B.second && A.second >= B.first){
    return true;
  }
  else{
    return false;
  }

}

int main() {

  int N;
  cin >> N;

  for (int i = 0; i < N; i++) {
    int a, b;
    cin >> a >> b;
    paper.push_back({a,b});
  }

  sort(paper.begin(), paper.end(), comp);

  int res = 0;
  for (int i = 0; i < N; i++) {
    dp[i] = 1;
    for (int j = 0; j < i; j++) {
      if(isInside(paper[j], paper[i])){
        dp[i] = max(dp[i], dp[j]+1);
      }
    }
    res = max(res, dp[i]);
  }
  cout << res;

  return 0;
}
