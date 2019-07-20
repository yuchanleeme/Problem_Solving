#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
//https://www.acmicpc.net/problem/7562

/*
<나이트의 이동>
주요: BFS
1. 체스말이 이동 할 수 있는 정점은 6군데다.
2. BFS를 통해 그래프를 탐색하되 이전에 조사했던 좌표면 건너 뛴다.
3. 이동한 횟수를 단위로 값을 카운트 해주고 타겟 값을 찾으면 횟수를 출력해준다.

*/

int l;
int visit[301][301];
int loc_x[8] = {-1, -2, -2, -1, 1, 2, 2, 1};
int loc_y[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
queue<pair<int, int> > que;

void bfs_cal(int x, int y){
  if(x >= 0 && x < l && y >= 0 && y < l){
    if(visit[x][y] == 0){
      que.push(pair<int, int>(x, y));
      visit[x][y] = 1;
    }
  }
}

void bfs(int x, int y){
  for (int i = 0; i < 8; i++) {
    bfs_cal(x + loc_x[i], y + loc_y[i]);
  }
}

int main() {

  int temp_size, ans, T, start_x, start_y, end_x, end_y;
  bool target = false;
  cin >> T;

  for (int testcase = 0; testcase < T; testcase++) {
    cin >> l;
    cin >> start_x >> start_y;
    cin >> end_x >> end_y;

    memset(visit, 0, sizeof(visit));
    ans = 0;
    target = false;
    while(!que.empty()){ que.pop();}

    que.push(pair<int,int>(start_x, start_y));
    visit[start_x][start_y] = 1;

    while(!que.empty()){
    	temp_size = que.size();
    	for(int i = 0; i < temp_size; i++){
    		if(que.front().first == end_x && que.front().second == end_y){
    			target = true;
          break;
    		}
    		bfs(que.front().first, que.front().second);
    		que.pop();
    	}
    	if(target){
    		break;
      }
    	ans++;
    }
  	cout << ans << endl;
  }
  return 0;
}
