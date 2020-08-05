#include <bits/stdc++.h>
using namespace std;
//https://programmers.co.kr/learn/courses/30/lessons/42885

/*
<구명보트>
주요: 그리디
1. 우선 들어갈 수 있는 제일 큰 친구 부터 보트에 태운다.
  => 이 과정을 진행하기 전에 편의를 위해 벡터 오름차순 정렬을 먼저 한다.
2. 그 뒤, 될 수 있는대로 작은 친구들을 우겨 넣는다.
3. 더 못태우면 새로운 보트를 데려온다.
4. 이렇게 1-3과정을 반복하고 보트 수를 센다.
==========
// 순서 역전은 생각하지 않는다. 어차피 앞에서 채워질거기 때문이다.
  : 1, 5, 94, 99 : (1,5,94) (99) 든, (1,99) (5,94) 든 두번으로 만족된다.
  => 처음 안 채워졌다면 다음 번에서 채워지기 때문에.

*/

int solution(vector<int> people, int limit) {
  int answer = 0;
  sort(people.begin(),people.end());

  int lo = 0, hi = people.size()-1;
  int w = 0;
  while (lo <= hi){
    answer++;
    w = people[hi];
    hi -= 1;

    for(int i = lo; i < people.size(); i++){
      if(w + people[i] <= limit){
        w += people[i];
        lo += 1;
      }
      else break;
    }
  }
  
  return answer;
}