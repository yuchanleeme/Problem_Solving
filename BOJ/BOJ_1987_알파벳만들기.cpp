#include <iostream>
#include <queue>
#include <vector>
using namespace std;
//https://www.acmicpc.net/problem/1987

/*
<알파벳 만들기>
주요: 백트래킹

*/
typedef struct info{

  int x;
  int y;
  char word;

}Info;

int R, C;
vector<char> board[20];
vector<vector<int> > visit;
int alpha[26] = {0, };
int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, -1, 0, 1};
int ans = 0, res = 0;
queue<Info> que;

void back_tracking() {

  ans = max(ans, res);

  for (int i = 0; i < 4; i++) {
    int tx =  dx[i] + que.front().x;
    int ty =  dy[i] + que.front().y;
    char tword = que.front().word;

    if(tx >= 0 && tx < R && ty >= 0 && ty < C){
      if(visit[tx][ty] == 0 && alpha[tword - 'A'] == 0){
        alpha[tword - 'A'] = 1;
        visit[tx][ty] = 1;
        res++;
        que.push({tx,ty,tword});
        back_tracking();
        alpha[tword - 'A'] = 0;
        visit[tx][ty] = 0;
        res--;
      }
    }
  }
}

int main() {

  cin >> R >> C;
  visit = vector<vector<int> >(R, vector<int>(C,0));
  for (int i = 0; i < R; i++) {
    for (int j = 0; j < C; j++) {
      char temp;
      scanf("%1c", &temp);
      board[i].push_back(temp);
    }
  }

  que.push({0,0,board[0][0]});
  visit[0][0] = 1;
  alpha[que.front().word-'A'] = 1;

  back_tracking();

  printf("%d", ans);

  return 0;
}
