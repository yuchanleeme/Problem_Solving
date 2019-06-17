#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
//https://www.acmicpc.net/problem/4963

/*
<섬의 개수>
주요: 그래프, 큐
1. 모든 배열울 탐색하면서 아직 방문하지 않았고 섬이면 탐색한다. (배열 값 1인 곳)
2. 해당 값에서 갈 수 있는 모든 방향을 탐색하고 발을 디딜곳이 있으면 그 섬의 좌표를 큐에 삽입한다.
3. 큐가 빌 때까지 큐에 있는 값들을 탐색하며 발 디딘 곳의 배열 값을 0으로 만든다.
3. 큐가 비게 되면 섬의 개수를 추가해주고 다시 1~3번 과정을 반복한다.

*/

typedef pair<int,int> pii;
queue<pii> que;
int square[55][55];

// 2번
void is_island(int a, int b){

  for (int i = -1; i < 2; i++) {
    for (int j = -1; j < 2; j++) {
      if((a + i) >= 0 && (b + j) >= 0){
        if(square[a+i][b+j] == 1){
          square[a+i][b+j] = 0;
          que.push(pii(a+i,b+j));
        }
      }
    }
  }
}

// 3번
void check(){
  while(!que.empty()){
      is_island(que.front().first, que.front().second);
      que.pop();
  }
}


int main() {

  int w, h, count;

  while(true){

    count = 0;
    cin >> w >> h;

    if(w == 0 & h == 0){
      break;
    }

    for (int i = 0; i < h; i++) {
      for (int j = 0; j < w; j++) {
        cin >> square[i][j];
      }
    }

    // 1번
    for (int i = 0; i < h; i++) {
      for (int j = 0; j < w; j++) {
        if(square[i][j] == 1){
          queue<pii> empty;
          swap(que, empty); // 빈 큐와 바꿔치기

          square[i][j] = 0;
          que.push(pii(i,j));
          check();

          count++;
        }
      }
    }
    cout << count << endl;
  }

  return 0;
}
