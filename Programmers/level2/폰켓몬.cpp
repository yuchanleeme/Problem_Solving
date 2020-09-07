#include <bits/stdc++.h>
using namespace std;
//http://programmers.co.kr/learn/courses/30/lessons/1845

/*
<폰켓몬>
주요: set(집합)
1. 집합의 원리를 요구하는 문제였다.
2. 중복 원소 없이 집합을 만든다.
3. 문제의 주어진 조건에 맞게 해당 값을 리턴하면 된다.
===========
* 중복 제거를 생각하면서 문제를 풀면 무난히 풀 수 있다.
* 만약 여기서 발상이 안된다면, 그림을 하나씩 그려서 bottom To up 으로 풀어보면 눈으로 확인 할 수 있다.

*/

int solution(vector<int> nums){
  int answer = 0;
  set<int> num;
  for (int i = 0; i < nums.size(); i++) {
    num.insert(nums[i]);
  }

  if(num.size() >= nums.size()/2) return nums.size()/2;
  else return num.size();
}
