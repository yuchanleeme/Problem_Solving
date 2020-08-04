#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
//https://programmers.co.kr/learn/courses/30/lessons/42626

/*
<더 맵게>
주요: 우선순위 큐
1. 최소 원소를 계속 탐색하므로 우선순위 큐를 생각한다.
2. 새로운 스코빌 지수 규칙에 따라 두개의 스코빌 음식을 빼고 새로운 스코빌 음식의 값을 넣는다.
3. 따라서 모든 단계마다 1씩 전체 큐 크기가 줄어준다는 뜻이다.
4. 첫번째와, 두번째 top 원소를 pop 하여 que의 원소에 넣는다.
5. 따라서, 1,2,번째 top 원소 말고는 조건에 맞게 우선순위 큐에 넣어 비교한다.
6. 결과에 맞는 값을 리턴한다. 

*/

int solution(vector<int> scoville, int K) {

  int answer = 0;

  priority_queue<int, vector<int>, greater<int> > que;
  for(int i = 0; i < scoville.size(); i++){
    que.push(scoville[i]);
  }

  while(que.size() >= 1){
    int first = que.top();
    if(first >= K) return answer;
    else if(que.size() == 1) break;
    que.pop();
      
    int second = que.top();
    que.pop();
      
    int mix = first + second*2; 
    que.push(mix);

    answer++;
  }
  return -1;
}