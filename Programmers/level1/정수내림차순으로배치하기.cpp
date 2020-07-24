#include <vector>
#include <algorithm>
using namespace std;
//https://programmers.co.kr/learn/courses/30/lessons/12933

/*
<정수 내림차순으로 배치하기>
주요: 구현, 정렬
1. seq에 각 자릿수 값을 넣는다.
2. 내림차순 정렬 한다.
3. answer에 seq[x]를 더하면서 10씩 곱해준다. 
4. 마지막으로 seq의 마지막 값을 더한다.
==========
* n을 string으로 변환 한 뒤에 sorting 하고 stoll을 이용해 출력하는 방법도 있다.

*/

long long solution(long long n) {
  long long answer = 0;
  vector<int> seq;
  while(n != 0){
    seq.push_back(n%10);
    n /= 10;
  }
  sort(seq.rbegin(),seq.rend());
  for (int i = 0; i < seq.size()-1; i++) {
    answer+= seq[i];
    answer *= 10;
  }
  answer += seq.back();
  return answer;
}
