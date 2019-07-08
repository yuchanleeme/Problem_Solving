#include <iostream>
#include <vector>
using namespace std;
//https://www.acmicpc.net/problem/2839

/*
<설탕배달>
주요: DP
1. 배달할 수 있는 설탕의 그램수는 규칙적으로 증가한다.
  => 3g(3) -> 6g(3+3), 8g(3+5) -> 9g(3+3+3), 11g(3+3+5), 11g(3+5+3), 13g(3+5+5) ....
  => 5g(5) -> 8g(5+3), 10g(5+5) -> 11g(5+3+3), 13g(5+3+5), 13g(5+5+3), 15g(5+5+5) ....
2. 설탕봉지수를 하나씩 증가 시키며 저장하고 이미 값이 입력되어있다면 계속 진행해 중복 저장되는것을 방지한다.
3. 저장된 설탕봉지수가 0 이면 -1을 출력하고 아니면 설탕봉지수를 출력한다.

*/

int main() {

  int N;
  vector<int> sugar(5010, 0);
  cin >> N;

  //초기값
  sugar[3] = 1;
  sugar[5] = 1;

  // 1,2번
  for (int i = 0; i < N; i++) {
    if(sugar[i] != 0){
      if(sugar[i+3] == 0){ sugar[i+3] += sugar[i] + 1;}
      if(sugar[i+5] == 0){ sugar[i+5] += sugar[i] + 1;}
    }
  }

  // 3번
  if(sugar[N] == 0){ cout << "-1";}
  else{ cout << sugar[N];}

  return 0;
}
