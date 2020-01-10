#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
//https://www.acmicpc.net/problem/2467

/*
<두 용액>
주요: lower_bound, 이분 탐색
1. 입력받은 용액값을 sort함수로 정렬한다.
2. 정렬한 용액값들과 나머지 값들을 차례대로 비교를 해본다.
3. 두 용액의 합이 0에 가까워야 하므로 한 용액의 -값을 붙여서 비교를 해본다.
  3-1) lower_bound를 이용해 세 값을 비교한다.
  3-2) lower_bound보다 1 작은값, lower_bound값, lower_bound보다 1 큰 값
    => lower_bound보다 1 큰값은 용액의 합이 0이 됐을때를 고려한것이다.
4. 찾은 두 용액 값을 오름차순으로 출력한다.

==========
* 범위 설정을 잘해야한다. (용액의 idx 위치 및 중복 제거)
* lower_bound는 못 찾는다면 end()를 리턴한다.

*/

const int INF = 2140000000;

int main() {

  int N;
  cin >> N;

  vector<int> fluid;

  for (int i = 0; i < N; i++) {
    int input;
    cin >> input;
    fluid.push_back(input);
  }

  sort(fluid.begin(), fluid.end());

  int ans_x, ans_y, compV = INF;
  for (int i = 0; i < fluid.size(); i++) {

    vector<int>:: iterator a = lower_bound(fluid.begin(), fluid.end(), -fluid[i]);
    int val = a - fluid.begin();

    if(abs(compV) > abs(fluid[i] + fluid[val-1])){
      if(i != (val-1) && (val-1) < N && val-1 >= 0 ){
        compV = fluid[i] + fluid[val-1];
        ans_x = i;
        ans_y = val-1;
      }
    }

    if(abs(compV) > abs(fluid[i] + fluid[val])){
      if(i != (val) && val < N && val >=0){
        compV = fluid[i] + fluid[val];
        ans_x = i;
        ans_y = val;
      }
    }

    if(abs(compV) > abs(fluid[i] + fluid[val+1])){
      if(i != (val+1) && (val+1) < N && (val+1) >=0){
        compV = fluid[i] + fluid[val+1];
        ans_x = i;
        ans_y = val +1;
      }
    }
  }

  if(fluid[ans_x] < fluid[ans_y]){
    cout << fluid[ans_x]<< " " << fluid[ans_y];
  }
  else{
    cout << fluid[ans_y]<< " " << fluid[ans_x];
  }

  return 0;
}
