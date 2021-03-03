#include <bits/stdc++.h>
using namespace std;
//https://www.acmicpc.net/problem/2003

/*
<수들의 합 2>
주요: 투 포인터
1. 시작과 끝을 정해놓고 값을 더한다.
2. 만약 더한 값이 M과 같으면 answer++를 한다.
3. 만약 더한 값이 M보다 크면 break한다.
  => A[x] 는 자연수이므로 계속 커지기만 한다.
4. 최종 answer를 출력한다.

*/

vector<int> seq;
int N, M, answer;

int main(int argc, char const *argv[]) {
  cin >> N >> M;

  for (size_t i = 0; i < N; i++) {
    int temp; cin >> temp;
    seq.push_back(temp);
  }
  for (int i = 0; i < N; i++) {
    int res = 0;
    for (int j = i; j < N; j++) {
      res += seq[j];
      if(res == M) answer++;
      else if(res > M) break;
    }
  }
  cout << answer;
  
  return 0;
}
