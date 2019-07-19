#include <iostream>
#include <vector>
#include <queue>
using namespace std;
//https://www.acmicpc.net/problem/1697

/*
<숨바꼭질>
주요: BFS
1. 한 정점이 이동 할 수 있는 정점은 3군데다.
2. BFS를 통해 그래프를 탐색하되 이전에 조사했던 번호면 건너 뛴다.
3. 초 단위로 값을 카운트 해주고 타겟 값을 찾으면 초를 출력해준다.

*/

int N, K;
int visit[1000001] = {0,};
queue<int> que;

void bfs_cal(int num){
  if(num >= 0 && num <= 1000000){
    if(visit[num]==0){
      que.push(num);
      visit[num] = 1;
    }
  }
}

void bfs(int num){

  bfs_cal(num*2);
  bfs_cal(num-1);
  bfs_cal(num+1);

}

int main() {

  int temp_size, time = 0;
  bool target = false;
  cin >> N >> K;

  que.push(N);
  visit[N] = 1;

  while(!que.empty()){
  	temp_size = que.size();
  	for(int i = 0; i < temp_size; i++){
  		if(que.front()==K){
  			target = true;
  			break;
  		}
  		bfs(que.front());
  		que.pop();
  	}
  	if(target){
  		break;
    }
  	time++;
  }

	cout << time << endl;

  return 0;
}
