#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
//https://programmers.co.kr/learn/courses/30/lessons/42860

/*
<조이스틱>
주요: 구현
1. 각 위치에서 값이 이동되는 조건을 센다. (up_right)
2.오른쪽, 왼쪽으로 이동하는 조건은 4개 중에 하나다.
3. 조건 4개
  2-1) 왼쪽으로 계속 이동하여 값 조절
  2-2) 오른쪽으로 계속 이동하여 값 조절
  2-3) 왼쪽으로 갔다가 오른쪽으로 다시이동해서 값 조절 (방향 전환 1번)
  2-4) 오른쪽으로 갔다가 왼쪽으로 다시이동해서 값 조절 (방향 전환 1번)
  2-*) 겹치는 부분을 생각해서 계산한다.
4. 각 조건에 맞게 최소값을 더해서 계산을 리턴한다.
==========
* 알파벳에 대한  X -'A' 에 대한 자연스러움이 필요하다.
* 이 풀이에서 여러 비교 사항이 필요하지만 A~Z를 다루는 자료구조도 중요한거 같다.
* A~Z 의 아스키 값, visit 배열, - 'A', -'Z' 에 대한 이해를 해도 좋을 것 같다.

*/

int solution(string name) {
  int up_down = 0;
  vector<int> idx;
  for(int i = 0; i < name.length(); i++){
    up_down += min(name[i]-'A', 'Z'-name[i]+1);
    if(name[i] != 'A' && i != 0) idx.push_back(i);
  }
  int len = name.length();
  int left_right = 0;
  if(idx.size() >= 1){
    left_right = min(idx.back(), len - idx[0]);
    if(idx.size() != 1)
      for(int i = 0; i < idx.size()-1; i++)
        left_right = min(left_right, min(idx[i], len-idx[i+1]) + idx[i] + len-idx[i+1]);
  }
  return up_down + left_right;
}
