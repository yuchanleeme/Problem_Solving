#include <bits/stdc++.h>
using namespace std;
//https://programmers.co.kr/learn/courses/30/lessons/42842

/*
<카펫>
주요: 구현
1. 노란 사각형 밖을 갈색 사각형이 테두리로 감싸는 모양이다.
2. 전체 사각형에서 노란 사각형의 개수를 빼면 갈색 사각형의 개수임을 이용한다.
3. 노란 사각형의 가로 세로를 x,y라 할때 전체 사각형의 개수는 (x+2) * (y+2)이다.
4. 즉 3번의 식을 이용해 2번 조건을 만족하는지 확인한다.
5. 가로가 더 길다 했으므로 더 큰 y+2를 먼저 넣고 x+2를 넣는다.
*/

vector<int> solution(int brown, int yellow) {
  vector<int> answer;

  for(int i = 1; i <= yellow; i++){
    if(yellow % i == 0){
      int x = i, y = yellow/i;
      int big_square = (x+2) * (y+2);
      if(big_square - yellow == brown){
        answer.push_back(y+2);
        answer.push_back(x+2);
        return answer;
      }
    }
  }
}
