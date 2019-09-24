#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
//https://www.acmicpc.net/problem/2210

/*
<숫자판 점프>
주요: 백트래킹
1. DFS로 입력받은 그래프를 탐색한다.
2. 백트래킹과 string의 성질을 활용해 중복되지 않은 6자리수를 구한다.
 => 시작지점 인자를 넘겨주어 백트래킹을 시작한다.
3. 중복되지 않은 6자리수를 구할때마다 res 벡터에 넣어준다.
4. 모두 탐색했을때 res의 사이즈를 출력한다.
==========
* 5*5 행렬꼴이라 시간초과가 안뜬것
* 좀 더 효율적인 풀이법을 한번 생각해 볼 필요도 있다.

*/

int dx[4] = {-1, 0, 1, 0}, dy[4] ={0, 1, 0, -1};
vector<string> graph[5];
string comp;
vector<string> res;

void back_tracking(int level, int x, int y) {

  if(level == 6){
    for (int i = 0; i < res.size(); i++) {
      if(comp == res[i]){
        return;
      }
    }
    res.push_back(comp);
    return;
  }

  for (int i = 0; i < 4; i++) {
    int tx = dx[i] + x;
    int ty = dy[i] + y;

    if(tx >= 0 && tx < 5 && ty >= 0 && ty < 5){
      comp += graph[tx][ty];
      back_tracking(level+1, tx, ty);
      comp.pop_back();
    }
  }
}

int main() {

  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
      string input;
      cin >> input;
      graph[i].push_back(input);
    }
  }

  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
      comp = "";
      comp += graph[i][j];
      back_tracking(1, i, j);
    }
  }

  cout << res.size();

  return 0;
}
