#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
//https://www.acmicpc.net/problem/1946

/*
<신입 사원>
주요: 정렬과 비교 알고리즘을 잘 짠다.
1. 서류점수의 등수가 좋은 순으로 오름차순 정렬한다.
2. 1등 부터 N등까지 비교한다.
  2-1)자신보다 높은 서류 등수를 가진 사람들의 면접등수 중에 나보다 높은 면접 등수를 가진 사람이 있나 찾는다.
  2-2) 한명이라도 있으면 채용에 실패한다. 실패 했다면 뽑을 수 있는 인원 N 에서 1씩 빼준다.
3. 위의 조건을 통과한 신입사원의 최대 인원수를 출력한다.
========
* 시간 초과를 줄이기 위해 위의 (2-1)에서 현재까지 확인한 사원들 중 가장 높은 면접 등수만 저장하여 비교해간다.

*/

int main() {

  int T, N, a, b, compare_value;

  scanf("%d", &T);

  for (int i = 0; i < T; i++) {
    scanf("%d", &N);

    vector<pair<int,int>> v;

    for (int j = 0; j < N; j++) {
      scanf("%d %d", a, b);
      v.push_back(pair<int, int>(a, b));
    }

    sort(v.begin(), v.end());

    compare_value = N;
    for (int k = 0; k < v.size(); k++) {
      if(v[k].second > compare_value){
        N -= 1;
      }
      else{
        compare_value = v[k].second;
      }
    }
    printf("%d\n", N);
  }

  return 0;
}
