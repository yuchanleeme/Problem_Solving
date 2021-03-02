#include <bits/stdc++.h>
using namespace std;
//https://www.acmicpc.net/problem/1026

/*
<보물>
주요: 정렬
1. 각각의 가장 작은 수와 가장 큰 수를 곱해서 더해나가면 된다.
2. A는 오름차순 정렬, B는 내림차순 정렬한다.
3. 두개를 idx별로 곱해서 더한다.
4. 더한 값을 출력한다.

*/

vector<int> A, B;

int main(int argc, char const *argv[]) {

  int N; cin >> N;
  for (int i = 0; i < N; i++) {
    int temp; cin >> temp;
    A.push_back(temp);
  }

  for (int i = 0; i < N; i++) {
    int temp; cin >> temp;
    B.push_back(temp);
  }

  sort(A.begin(),A.end());
  sort(B.rbegin(),B.rend());

  int answer = 0;
  for (int i = 0; i < N; i++) {
    answer += A[i]*B[i];
  }
  cout << answer;

  return 0;
}
