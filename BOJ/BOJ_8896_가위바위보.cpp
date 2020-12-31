#include <bits/stdc++.h>
using namespace std;
//https://www.acmicpc.net/problem/8896

/*
<가위 바위 보>
주요: 구현, 비트
1. 큐에 각 로봇의 가위바위보 정보를 넣고 게임에 진 로봇만 pop해주는 형식으로 구현한다.
2. 우선, 큐를 순회하며 현재 round의 각 로봇의 정보들을 갱신한다. (이 때 비트를 쓴다.)
  2-1. R(4) S(2) P(1)로 각 로봇이 해당 문자를 가지고 있다면 gameResult비트를 켜준다.
3. 이제 큐를 다시 순회하면서 gameResult결과에 따라 게임에 진 로봇을 pop해준다.
  3-1. R,S만 있음(4+2=6) : 로봇이 S을 냈으면 pop해준다.
  3-2. R,P만 있음(4+1=5) : 로봇이 R을 냈으면 pop해준다.
  3-3. S,P만 있음(2+1=3) : 로봇이 P을 냈으면 pop해준다.
  3-4. 나머지는 무승부
4. 승자만 남았을때는 승자 출력, 게임이 안 끝났을때는 무승부를 출력한다.

*/

queue<pair<string, int> > que; // 로봇 정보
int main(int argc, char const *argv[]) {
  int T;
  cin >> T;
  while (T--) {
    int N; cin >> N;
    while (!que.empty()) que.pop();

    for (int i = 1; i <= N; i++) {
      string temp; cin >> temp;
      que.push({temp, i});
    }

    // 가위 바위 보 시작
    int round = 0;
    while(true){

      // 2번
      int temp_size = que.size();
      int gameResult = 0;
      for (int i = 0; i < temp_size; i++) {
        char hand = que.front().first[round];
        if(hand == 'R') gameResult |= 4;
        else if(hand == 'S') gameResult |= 2;
        else if(hand == 'P') gameResult |= 1;
        que.push(que.front());
        que.pop();
      }

      // 3번
      for (int i = 0; i < temp_size; i++) {
        char hand = que.front().first[round];
        if(gameResult == 6 && hand == 'S') que.pop();
        else if(gameResult == 5 && hand == 'R') que.pop();
        else if(gameResult == 3 && hand == 'P') que.pop();
        else{
          que.push(que.front());
          que.pop();
        }
      }
      round++;

      // 4번
      if(que.size() == 1){
        cout << que.front().second << endl;
        break;
      }
      else if(round == que.front().first.length()){
        cout << 0 << endl;
        break;
      }
    }
  }
  return 0;
}
