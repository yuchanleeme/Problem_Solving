#include <string>
#include <vector>
#include <queue>
using namespace std;
//https://programmers.co.kr/learn/courses/30/lessons/42583

/*
<다리를 지나는 트럭>
주요: 큐, 구현
1. 현재 다리에 위치한 트럭들의 정보가 담긴 pair 큐를 하나 만든다.
2. 각 초마다 다리에 있는 트럭들의 정보 갱신 및 새로 트럭을 넣을지 정한다.
3. 트럭들의 정보 갱신
  3-1. 원형 큐 방식으로 큐를 탐색한다.
  3-2. 1초가 지나고 다리를 벗어난다면 sum에서 빼주고 큐에도 pop 해주고 out을 증가시킨다.
  3-3. 이외의 경우, 1초를 줄이고 다시 큐에 넣는다.
4. 새로 트럭을 넣을지 정한다.
  4-1. 트럭의 무게와 현재 다리위 무게들(sum)의 합이 중량을 견디면 트럭을 새로 넣는다.
  4-2. 트럭의 무게와, 다리의 길이를 pair로 삽입한다.
5. 모든 차가 빠져 나갈 경우의 시간 answer을 리턴한다.
===========
* 최악의 경우가 1e4 * 1e4 근처에서 루프가 돌것이기 때문에 위 풀이가 가능하다.
* 특정 알고리즘 구현을 계속 생각하다 보니까 일일이 날짜를 계산해 줄 생각을 못했다.
* 시간복잡도를 유추해서 단순하게 생각도 해보는 습관을 들이자.

*/

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0, now = 0, sum = 0, out = 0;
    queue<pair<int, int> > que; // 1번
    
    // 2번
    while(out != truck_weights.size()){
        answer++;   // 초 증가
        
        // 3번
        int temp_size = que.size(); // 현재 큐 사이즈 (이 만큼만 큐를 돌아 탐색한다는 의미)
        for (int i = 0; i < temp_size; i++){
            int sec = que.front().first;
            if(sec-1 > 0) que.push({sec-1,que.front().second}); 
            else{
                out++;
                sum -= que.front().second;
            } 
            que.pop();
        }

        // 4번
        if(que.empty() || (sum + truck_weights[now]) <= weight){
            sum += truck_weights[now];
            que.push({bridge_length,truck_weights[now++]});
        }
    }
    return answer;
}