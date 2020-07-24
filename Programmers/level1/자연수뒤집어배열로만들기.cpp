#include <vector>
#include <algorithm>
using namespace std;
//https://programmers.co.kr/learn/courses/30/lessons/12932

/*
<자연수 뒤집어 배열로 만들기>
주요: 구현
1. 10으로 나눈 나머지를 벡터에 넣고 그 후에 10으로 나눈다.
2. n이 0이 될때까지 반복한다.
3. 1의자리부터 answer에 들어가므로 자동적으로 뒤집은 꼴이 된다.

*/

vector<int> solution(long long n) {
  vector<int> answer;
  while(n != 0){
    answer.push_back(n%10);
    n /= 10;
  }
  return answer;
}
