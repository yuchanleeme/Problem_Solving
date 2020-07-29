#include <vector>
using namespace std;
//https://programmers.co.kr/learn/courses/30/lessons/42586

/*
<기능 개발>
주요: 큐, 구현
1. 각 프로그램마다 만드는데 남은 기간을 구하는 벡터를 만든다.
  => 나누어 떨어지는 부분에서 날짜 계산을 달리한다.
2. 후속 프로그램 중에 개발 날짜가 자신보다 이른 프로그램을 순차적으로 찾는다.
  2.1 차례대로 개발되어야 하므로 연속적으로 개발이 진행 안되면 찾는것을 그만둔다.
  2.2 개발되었다고 판단하면 visit 배열을 -1로 초기화 시킨다.
3. 각 날짜별 개발되는 프로그램 수를 리턴한다.
===========
* 남은 날짜 계산하는 방법에서 나누어떨어지는 부분을 따로 안놓고도 처리가 가능했다.
  => 나머지 퍼센트에서 1을 빼고 나눈 뒤 1일을 더해주는 방법
  => 겨우 1차이기 때문에 나누어떨어지는 안떨어지는 1씩 더해주면 같은 답이 나온다. 

*/

int visit[110];
vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    vector<int> endDate;

    // 1번
    int totalProgram = progresses.size();
    for (int i = 0; i < totalProgram; i++){
        int date = 0;
        if((100-progresses[i])%speeds[i] == 0) date = (100-progresses[i])/speeds[i];
        else date = (100-progresses[i])/speeds[i] + 1;
        endDate.push_back(date);
    }

    // 2번
    for (int i = 0; i < totalProgram; i++){
        if(visit[i] == -1)  continue;
        int temp = 1;
        for (int j = i+1; j < totalProgram; j++){
            if(endDate[j] <= endDate[i]){
                temp++;
                visit[j] = -1;
            }else{
                break;
            }
        }
        visit[i] = -1;
        answer.push_back(temp);
    }
    return answer;
}