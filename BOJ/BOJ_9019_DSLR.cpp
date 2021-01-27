#include <bits/stdc++.h>
using namespace std;
//https://www.acmicpc.net/problem/9019

/*
<DSLR>
주요: BFS
1. 조건에 맞게 DSLR 함수를 구한다.
2. 큐에 {결과값, 입력한 string}을 넣어 BFS를 한다.
3. B를 찾으면 결과값을 출력하고 리턴한다.
4. 모든 테스트케이스 동안 2~3과정을 반복한다.
==========
* L, R 쓰는 부분에서 아이디어를 잘 생각해야한다.
  => 정직하게 자리수를 구해서 회전시켰더니 500ms나 차이가 났다.
* 최솟값, 최단거리 문제는 대부분 BFS라는것을 생각하자.

*/

int T, A, B;

int DSLR(int num, int idx){
  if(idx == 0) return num*2 > 9999 ? num*2 % 10000 : num*2;
  else if(idx == 1) return num == 0 ? 9999 : num-1;
  else if(idx == 2) return (num % 1000)*10 + num/1000;
  else if(idx == 3) return (num % 10)*1000 + num/10;
}

void bfs(){

  int check[10010] = {0, };

  queue<pair<int, string> > que;
  que.push({A, ""});

  while (!que.empty()) {
    int temp_size = que.size();
    for (int i = 0; i < temp_size; i++) {
      int number = que.front().first;
      string str = que.front().second;
      for (int j = 0; j < 4; j++) {
        int res = DSLR(number, j);

        string tempStr = str;
        if(j == 0) tempStr += "D";
        else if(j == 1) tempStr += "S";
        else if(j == 2) tempStr += "L";
        else if(j == 3) tempStr += "R";

        if(check[res] == 0){
          if(res == B){
            cout << tempStr << "\n";
            return;
          }
          check[res] = 1;
          que.push({res, tempStr});
        }
      }

      que.pop();
    }
  }
}

int main(int argc, char const *argv[]) {

  cin.tie(NULL); ios::sync_with_stdio(false);

  cin >> T;
  while (T--) {
    cin >> A >> B;
    bfs();
  }

  return 0;
}
