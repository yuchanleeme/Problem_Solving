#include <iostream>
#include <string>
#include <vector>
using namespace std;
//https://programmers.co.kr/learn/courses/30/lessons/12901

/*
<2016년>
주요: 구현
1. 각 월의 일자를 day 배열에 저장한다.
2. 각 요일이름을 wday 배열에 저장한다.
3. 1월 1일로 부터 총 몇일이 지났는지 계산하고 7로 나누어 나머지를 구한다.
4. 1월 1일이 금요일이므로 나머지만큼 떨어진 값을 생각해서 계산해 리턴한다.
===========
* 불규칙적인 변수들을 배열화 해서 진행한다는 아이디어가 주요 포인트다.
*/

int day[13] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
string wday[7] = {"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};
string solution(int a, int b) {
    string answer = "";
    int sumDay = b;
    for (int i = 1; i < a; i++)
      sumDay += day[i];

    answer = wday[(sumDay+3)%7];
    return answer;
}
