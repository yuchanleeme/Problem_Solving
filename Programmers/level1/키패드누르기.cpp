#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
//https://programmers.co.kr/learn/courses/30/lessons/67256

/*
<키패드 누르기>
주요: 구현
1. 각 번호의 위치를 배열화 한다. (loc[x] = x번의 위치)
2. numbers 배열을 돌면서 확인한다. (초기값 *,#의 위치)
  2-1. 1,4,7을 만나면 왼손이 이동하고 위치 갱신 및 answer에 추가
  2-2. 3,6,9를 만나면 오른손이 이동하고 위치 갱신 및 answer에 추가
  2-3. 2,5,8,0을 만나면 dist_length의 리턴값에 의해 손 이동하고 위치 갱신 및 answer에 추가
    => 길이 같을 시 각 손잡이에 의거해 손 이동
3. 최종 answer 리턴

*/

pair<int, int> loc[10] = {{3,1},{0,0},{0,1},{0,2},{1,0},{1,1},{1,2},{2,0},{2,1},{2,2}};
// 위치랑 누를 번호를 인자로 받아서 상대 거리 리턴
int dist_length(pair<int, int> H, int num){
  return abs(H.first - loc[num].first) + abs(H.second - loc[num].second);
}

string solution(vector<int> numbers, string hand) {
  string answer = "";
  pair<int, int> hd[2] = {{3,0}, {3,2}};  // hd[0] : 왼손, hd[1] : 오른손
  for (int i = 0; i < numbers.size(); i++) {
    if(numbers[i] == 1 || numbers[i] == 4 || numbers[i] == 7){
      hd[0] = loc[numbers[i]];
      answer += "L";
    }
    else if(numbers[i] == 3 || numbers[i] == 6 || numbers[i] == 9){
      hd[1] = loc[numbers[i]];
      answer += "R";
    }
    else{
      int L_dist = dist_length(hd[0], numbers[i]);
      int R_dist = dist_length(hd[1], numbers[i]);
      if(L_dist == R_dist){
        if(hand == "left"){
          hd[0] = loc[numbers[i]];
          answer += "L";
        }
        else if(hand == "right"){
          hd[1] = loc[numbers[i]];
          answer += "R";
        }
      }
      else if(L_dist < R_dist){
        hd[0] = loc[numbers[i]];
        answer += "L";
      }
      else if(R_dist < L_dist){
        hd[1] = loc[numbers[i]];
        answer += "R";
      }
    }
  }
  return answer;
}
