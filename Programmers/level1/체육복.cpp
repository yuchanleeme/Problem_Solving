#include <vector>
#include <algorithm>
using namespace std;
//https://programmers.co.kr/learn/courses/30/lessons/42862

/*
<체육복>
주요: 구현
1. 기본적으로 학생들은 체육복 하나를 가지고 있다고 하자.
2. 여벌을 가지고 있는 학생은 체육복 수를 늘린다.
3. 도둑맞은 학생은 체육복 수를 줄인다.
4. 이제 잃어버린 학생을 조사한다.
  4.1 만약 여벌이 있따면(1) 그냥 넘어간다.
  4.2 앞, 뒤 친구가 여벌이 2벌이면 한벌 빌린다.
5. 4번 과정을 모두 못했을 시 전체 n(answer)에서 1을 줄인다.
6. 조사가 끝났을때의 n(answer)를 리턴한다.
==========
* 본인이 잃어버렸을때는 남한테 먼저 안빌려준다.
  => TC 하나가 계속 틀리길래 반례 여러개 돌리다 찾았다.
*/

vector<int> haveClothes(33, 1); // 1번
int solution(int n, vector<int> lost, vector<int> reserve) {
  int answer = n;
  // 2번
  for (int i = 0; i < reserve.size(); i++)
    haveClothes[reserve[i]]++;

  // 3번
  for (int i = 0; i < lost.size(); i++)
    haveClothes[lost[i]]--;

  // 4번
  for (int i = 0; i < lost.size(); i++) {
    if(haveClothes[lost[i]] == 1) continue; // 4-1번
    // 4-2번
    if(haveClothes[lost[i]-1] == 2){
      haveClothes[lost[i]-1]--;
      continue;
    }else if(haveClothes[lost[i]+1] == 2){
      haveClothes[lost[i]+1]--;
      continue;
    }
    answer--; // 5번
  }
  return answer;  // 6번
}
