#include <algorithm>
#include <vector>
using namespace std;
//https://programmers.co.kr/learn/courses/30/lessons/12925

/*
<문자열을 정수로 바꾸기>
주요: stoi
1. 방법은 여러가지가 있다.
2. 직접 숫자 구현하는 법, sstream을 쓰는법 등
3. 제일 간단한 stoi를 썼다.
*/

int solution(string s) {
  return stoi(s);
}
