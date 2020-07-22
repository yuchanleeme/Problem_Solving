#include <string>
#include <vector>
using namespace std;
//https://programmers.co.kr/learn/courses/30/lessons/12906

/*
<같은 숫자는 싫어>
주요: 구현
1. prev를 저장시키면서 연속된 숫자를 무시하고 진행한다.
2. 새로운 숫자가 나타나면 answer에 넣고 prev를 갱신하다.
*/

vector<int> solution(vector<int> arr)
{
    vector<int> answer;
    int prev = -1;
    for (int i = 0; i < arr.size(); i++) {
      if(prev == arr[i]) continue;
      else{
        answer.push_back(arr[i]);
        prev = arr[i];
      }
    }
    return answer;
}
