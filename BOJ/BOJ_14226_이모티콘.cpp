#include <bits/stdc++.h>
using namespace std;
// https://www.acmicpc.net/problem/14226

/*
<이모티콘>
주요: BFS
1. 자식 트리가 3개인 노드들의 그래프를 만든다.
  => pair {현재 이모티콘 수, 클립보드 이모티콘 수}
2. 노드를 큐에 넣을 수 있는 지 판단 한다.
  => 한 번도 방문한 적 없어야 하며 클립보드에 값이 있어야 한다.
  => idx 범위를 벗어날 시에는 큐에 넣지 않는다.
3. 노드에 넣으면서 원하는 값 S를 찾으면 2중 for문을 탈출하고 값을 출력한다.
===========
* visit 배열 처리가 중요
* 배열 idx 중요
*/

int S, ans;
int visit[1010][1010];
queue<pair<int, int> > que;
int main(int argc, char const *argv[]) {

  cin >> S;

  que.push({1, 0}); // 초기 노드
  for (int i = 0; i < 1000; i++) {
    ans++;  // 각 레벨
    int temp_size = que.size();
    for (int j = 0; j < temp_size; j++) {
      bool gameOver = false;
      pair<int, int> now = que.front();
      pair<int, int> num[3];  // 후보 노드들
      num[0] = {now.first, now.first};
      num[1] = {now.first + now.second, now.second};
      num[2] = {now.first-1, now.second};

      // 노드 체크
      for (int k = 0; k < 3; k++) {
        if(num[k].first > 1000 || num[k].second > 1000) continue;
        if(num[k].first < 0 || num[k].second < 0) continue;
        if(visit[num[k].first][num[k].second] == 0 && num[k].second > 0){
          que.push(num[k]);
          visit[num[k].first][num[k].second] = 1;
          if(num[k].first == S){
            j = temp_size;  // 찾았으니 2중 for문 탈출
            i = 1000;
            break;
          }
        }
      }
      que.pop();
    }
  }
  cout << ans;

  return 0;
}
