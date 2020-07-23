#include <algorithm>
#include <vector>
using namespace std;
//https://programmers.co.kr/learn/courses/30/lessons/12922

/*
<수박수박수박수박수박수?>
주요: 나머지
1. 짝수이면 "수박"을 n/2 번 출력한다.
2. 홀수이면 "수박"을 n/2 번 출력하고, "수"를 추가로 출력한다.
*/

string solution(int n) {
  string answer = "";
  for (int i = 0; i < n/2; i++)
    answer += "수박";
  if(n % 2 == 1) answer += "수";
  return answer;
}
