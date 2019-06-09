#include <iostream>
#include <algorithm>
using namespace std;
//https://www.acmicpc.net/problem/11047

/*
<회의실 배정> - 기존 코드 수정
주요: 그리디 알고리즘을 활용한다.
1. 끝나는 시간이 가장 빠른순으로 정렬한다.
2. 끝나는 시간을 compare_value로 저장한다.
3. 정렬된 구조체 배열을 compare_value와 조건에 맞춰 비교하면서 count를 해준다.
  => 회의 시작 시간 compare_value보다 크거나 같은 경우 compare_value를 회의 끝나는 시간으로 지정하고 count 해준다.
  => 이 이외의 경우는 패스해준다.
4. 계산된 count값을 출력한다.

*/

typedef struct Conf{
  int start;
  int end;
}Conf;

bool cmp(const Conf &c1, const Conf &c2){
  if(c1.end < c2.end){
    return true;
  }
  else if(c1.end == c2.end){
    return c1.start < c2.start;
  }
  else{
    return false;
  }
}

int main() {

  int N, compare_value, temp, count = 0;
  Conf conf[100001];
  cin >> N;

  for (int i = 0; i < N; i++) {
    cin >> conf[i].start >> conf[i].end;
  }

  sort(conf, conf+N, cmp);

  compare_value = 0;
  for (int i = 0; i < N; i++) {
    if(conf[i].end >= compare_value){
      if(conf[i].start >= compare_value){
        compare_value = conf[i].end;
        count++;
      }
    }
  }

  cout << count;

  return 0;
}
