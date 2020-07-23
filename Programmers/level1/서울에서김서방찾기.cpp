#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;
//https://programmers.co.kr/learn/courses/30/lessons/12919

/*
<서울에서 김서방 찾기>
주요: 구현
1. 단순 for문 구현문제이다.
2. for문으로 kim을 찾으면 된다.
============
* vector의 find 함수를 이용하는 법도 있다.
* int값으로 바꾸는 법은 stringstream, to_string 등 여러 방법이 있다.

*/

string solution(vector<string> seoul) {
    for (int i = 0; i < seoul.size(); i++) {
      if (seoul[i] == "Kim") {
        return "김서방은 " + to_string(i) + "에 있다";
      }
    }
}
