#include <stdio.h>
// https://www.acmicpc.net/problem/1924

/*
<2007년>
주요: 2007년의 요일을 출력한다.
1. 2007년 1월 1일은 월요일이다.
2. 따라서 2007년 1월 1일 이후 경과한 날을 구하고 7로 나눈다.
  => 각 월의 일수를 배열로 저장한다. / 요일 이름도 배열로 저장한다.
3. 그 나머지를 이용하여 요일을 출력한다.

*/

int main(int argc, char const *argv[]) {

  int NumberOfMonth[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  char DayOfWeek[7][4] = {"SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT"};
  int month, day;

  scanf("%d %d", &month, &day);

  for(int i = 0; i < month-1; i++){
    day += NumberOfMonth[i];
  }

  printf("%s", DayOfWeek[day%7]);

  return 0;
}
