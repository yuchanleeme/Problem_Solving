#include <vector>
#include <algorithm>
using namespace std;
//https://programmers.co.kr/learn/courses/30/lessons/12944

/*
<평균 구하기>
주요: 구현
1. arr 내 모든 원소를 다 더한다.
2. 더한 결과를 double형으로 캐스팅 후, arr의 원소 개수로 나눈다.
3. 그 결과값을 리턴한다.
==========
* 처음부터 double형에다가 넣어서 하는 방법도 있었다.
*/

double solution(vector<int> arr) {
  int sum = 0;
  for(int i = 0; i < arr.size(); i++){
    sum += arr[i];
  }
  return (double)sum / arr.size();
}
