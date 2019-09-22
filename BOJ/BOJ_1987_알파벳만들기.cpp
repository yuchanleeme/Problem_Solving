#include <iostream>
#include <stack>
#include <vector>
using namespace std;
//https://www.acmicpc.net/problem/1987

/*
<알파벳 만들기>
주요: 백트래킹, BFS
1. BFS로 주어진 그래프를 탐색하면서 각 경로들을 백트래킹한다.
2. 알파벳 벡터를 따로 만들어 중복여부를 확인한다.
3. 새로운 알파벳을 방문할때마다 res값을 ++ 해주고 ans와 크기비교를 해준다.
4. 계산된 ans를 마지막에 출력해준다.
==========
* 입력방식이 까다로우니 주의할것

*/
typedef struct info{

  int x;
  int y;

}Info;

int R, C;
vector<char> board[20];
vector<vector<int> > visit;
vector<int> alpha(26, 0);
int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, -1, 0, 1};
int ans = 0, res = 0;
stack<Info> stk;

void back_tracking() {

  ans = max(ans, res);

  for (int i = 0; i < 4; i++) {
    int tx = dx[i] + stk.top().x;
    int ty = dy[i] + stk.top().y;

    if(tx >= 0 && tx < R && ty >= 0 && ty < C){
      char tword = board[tx][ty];

      if(visit[tx][ty] == 0 && alpha[tword - 'A'] == 0){
        alpha[tword - 'A'] = 1;
        visit[tx][ty] = 1;
        res++;
        stk.push({tx,ty});
        back_tracking();
        alpha[tword - 'A'] = 0;
        visit[tx][ty] = 0;
        res--;
        stk.pop();
      }
    }
  }
}

int main() {

  scanf("%d %d", &R, &C);

  visit = vector<vector<int> >(R, vector<int>(C,0));

  for (int i = 0; i < R; i++) {
    for (int j = 0; j < C; j++) {
      char temp;
      // 한글자씩 받되 개행문자를 받으면 다시 받는다.
      while (scanf("%1c", &temp)) {
        if(temp != '\n'){ break;}
      }
      board[i].push_back(temp);
    }
  }

  // 초기값 설정
  stk.push({0,0});
  visit[0][0] = 1;
  alpha[board[0][0]-'A'] = 1;
  res++;

  back_tracking();

  printf("%d", ans);

  return 0;
}
