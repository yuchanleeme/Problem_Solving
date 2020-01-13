#include <iostream>
#include <vector>
#include <queue>
using namespace std;
//https://www.acmicpc.net/problem/2841

/*
<외계인의 기타 연주>
주요: 우선순위 큐
1. 각 기타줄 마다 우선순위 큐를 만들어 개수를 세아린다.
2. 큐가 비어 있을 때
 2-1) 큐에 fret 삽입 및 ans++
3. 큐가 안 비어 있을 때
  3-1) 큐의 최대값보다 크다면 큐에 넣어주고 ans++
  3-2) 큐의 최대값보다 작다면 작거나 같은 값이 나올때까지 계속 pop 및 ans++
    => 같은 값이 나온다면 push 해주지 말고 작은 값이 나온다면 fret 큐에 삽입및 ans++
4. 각 조건에서 계산된 ans를 출력한다.

*/

int ans = 0;
priority_queue<int> line[7];

void play(int m, int fret){

  // 2번
  if(line[m].empty()){
    line[m].push(fret);
    ans++;
  }
  else{
    // 3번
    if(line[m].top() < fret){
      line[m].push(fret);
      ans++;
    }
    else if(line[m].top() > fret){
      while (!line[m].empty()) {
        if(line[m].top() <= fret){ break;}
        line[m].pop();
        ans++;
      }
      if(line[m].top() != fret){
        line[m].push(fret);
        ans++;
      }
    }
  }

}

int main() {

  int N, P;
  cin >> N >> P;

  for (int i = 0; i < N; i++) {
    int m, fret;
    cin >> m >> fret;
    play(m, fret);
  }

  cout << ans;

  return 0;
}
