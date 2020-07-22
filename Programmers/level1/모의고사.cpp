#include <vector>
using namespace std;
//https://programmers.co.kr/learn/courses/30/lessons/42840

/*
<모의고사>
주요: 브루트 포스
1. 정답 배열을 미리 만들어 놓고 for문을 돌면서 정답의 개수를 찾는다.
2. 정답의 개수가 다른 두 값의 개수보다 같거나 클 때 answer 벡터에 삽입한다.
3. 오름차순으로 리턴하라 했으니까 a,b,c 순으로 비교한다.
===========
* 비교할때, a,b,c 중 max 값을 먼저 찾고 for문으로 비교해 그 번호만 answer에 넣는 방법도 있다.

*/

int student[3][11] = {
  {1,2,3,4,5},
  {2,1,2,3,2,4,2,5},
  {3,3,1,1,2,2,4,4,5,5}
};
int a, b, c;
vector<int> solution(vector<int> answers) {
    vector<int> answer;

    for (int i = 0; i < answers.size(); i++) {
      int now = answers[i];
      if(now == student[0][i%5]) a++;
      if(now == student[1][i%8]) b++;
      if(now == student[2][i%10]) c++;
    }

    if(a >= b && a >= c)
      answer.push_back(1);
    if(b >= a && b >= c)
      answer.push_back(2);
    if(c >= a && c >= b)
      answer.push_back(3);
    return answer;
}
