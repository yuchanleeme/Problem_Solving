#include <iostream>
#include <vector>
using namespace std;
//https://programmers.co.kr/learn/courses/30/lessons/42883

/*
<큰 수 만들기>
주요: 구현
1. 규칙을 찾는게 제일 주요한 포인트였다.
2. 앞에서 부터 개수를 찾되, 만약에 더 큰 수가 있다면 앞 숫자들을 버린다.
  => ex) 41895841 , 4
        1.) 41772/52841 => 7이 젤 큰 수 "41772"에서 (7의 위치 idx[2])
          7이 제일 크기때문에 다음은 725 (4,1,두개빠진다는 가정)
        2. ) 725/2841 => 7 즁 젤 큰 수  "725"에서 (7의 위치 idx[0])
          7이 제일 크기때문에 다음은 "252".........
3. 각 조건에 맞게 최종 리턴값을 정해서 리턴한다.

*/

string solution(string number, int k) {
  string temp = number;
  string answer = "";
  int count = k+1;

  while(temp.length() != 0){
    string now = temp.substr(0,count);
    int idx = 0;
    for(int i=0; i< now.length();i++){
      if(now[i] > now[idx]) idx = i;
    }
    answer += now[idx];
    count -= idx;
    temp = temp.substr(idx+1);
    if(answer.length() == number.length()-k) break;
  }

  return answer;
}
