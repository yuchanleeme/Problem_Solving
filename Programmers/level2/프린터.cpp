#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;
//https://programmers.co.kr/learn/courses/30/lessons/42587

/*
<쇠막대기>
주요: 큐, 우선순위 큐
1. (중요도, 원래 위치)가 pair형태로 큐에 삽입된다.
2. 중요도만 따로 우선순위 큐에 넣는다.
3. 우선순위 큐의 top과 큐의 front 가 같을때까지 원형큐를 돌린다.
4. 이 방식으로 몇번째로 출력하는지 찾아 리턴한다.

*/

priority_queue<int> pr;
queue<pair<int, int> > que;
int visit[110];
int solution(vector<int> priorities, int location) {
  int answer = 0;

  // 1,2번
  for (int i = 0; i < priorities.size(); i++) {
    que.push({priorities[i], i});
    pr.push(priorities[i]);
  }
 
  // 3번
  while (!que.empty()){
    if(que.front().first != pr.top()){
      while(que.front().first != pr.top()){
        que.push(que.front());
        que.pop();
      }
    }
    answer++;
    if(que.front().second == location) return answer;
    que.pop(), pr.pop();
  }
}