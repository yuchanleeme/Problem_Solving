#include <bits/stdc++.h>
using namespace std;
// https://www.acmicpc.net/problem/2437

/*
<저울>
주요: 그리디, 정렬
1. 저울추를 오름차순으로 정렬한다.
2. 정렬한 저울추의 첫 원소가 1이 아니면 1을 리턴한다.
3. 현재까지 만들 수 있는 최대 추의 무게를 X라 하고 이때의 idx를 num이라 하자.
  3.1 X는 weigth[num-1]까지의 추를 사용했을 때, 1~X까지의 무게를 모두 만들 수 있다는 뜻이다.
  3.2 이제, weight[num]과 X를 비교한다.
  3.3 예를 들어 X가 10이고 weight[num]가 7이면, 이미 1~10까지는 만들 수 있고 여기에 Y만큼 더한 수를 더 만들 수 있다는 뜻이다.
    => (7+0), (7+1), (7+2), (7+3) .... (7+10)이므로, 중복되는 값 제외하고 1~17까지 되는것이므로 즉 X값이 X+weight[num] (17)이 되는 것이다.
  3.4 이를 이용하면 X+1 < weight[num]이면 딱 X+1만 불가능하게 되는 것이다.
    ex) X:10 weight[num]:12
      => (1~10), (12+0) (12+1) ... (12+10) ==> 1~10, 12~22 이므로 11(X+1)은 불가능하다.
4. 3번의 원리를 이용해 정답을 출력한다.

*/

int N;
vector<int> weight;

int main(){

  cin >> N;
  for (size_t i = 0; i < N; i++) {
    int temp; cin >> temp;
    weight.push_back(temp);
  }

  sort(weight.begin(), weight.end());

  if(weight[0] != 1) return !printf("1");

  int res = 0; // 최대 값
  for (int i = 1; i < N; i++) {
    res += weight[i-1];
    if(res+1 < weight[i]){
      return !printf("%d", res+1);
    }
  }

  cout << res+weight.back()+1;

}
