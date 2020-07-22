#include <vector>
#include <algorithm>
using namespace std;
//https://programmers.co.kr/learn/courses/30/lessons/42748

/*
<K번째 수>
주요: 정렬
1. 미리 array에 대한 배열을 복사해 놓는다.
2. sort 함수를 이용해 특정 구간만 정렬을 진행한다. O(nlogn)
3. 문제에서 요구하는 idx값을 answer에 넣어 리턴한다.
==========
* 미리 복사할 필요가 없이 temp 벡터를 만들어 두 번째 for문 안에서 끝내는 방법도 있다.

*/

vector<int> cparray[55];
vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    for (int i = 0; i < commands.size(); i++) {
      for (int j = 0; j < array.size(); j++) {
        cparray[i].push_back(array[j]);
      }
    }

    for (int i = 0; i < commands.size(); i++) {
      int st = commands[i][0];
      int ed = commands[i][1];
      sort(cparray[i].begin()+st-1, cparray[i].begin()+ed);
      answer.push_back(cparray[i][st-2+commands[i][2]]);
    }
    return answer;
}
