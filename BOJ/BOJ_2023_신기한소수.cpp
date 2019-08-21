#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
//https://www.acmicpc.net/problem/2023

/*
<신기한 소수>
주요: 백트래킹 , 수학
1. 한자리수 소수는 2,3,5,7 이다.
2. N이 소수인지 판단하는 방법은 2 ~ N/2 사이 값들로 나누어 떨어지는지 확인하는것이다.
3.백트래킹으로 조사하면서 각 자리수까지가 소수인지 판단한다.
  => 1~9부터 홀수만 res에 추가해준다.(짝수는 어차피 소수가 아니다.)
  => 위의 이유 때문에 한지리수 소수를 먼저 만들어주고 시작한다.
4. N 자리까지 모두 조사했으면 res를 출력한다.

*/

int N;
string res;
vector<string> v = {"2","3","5","7"}; // 1자리수 소수

void back_tracking(int level){

  int num = stoi(res);

  // 2번
  for (int i = 3; i < num/2; i++) {
    if(num % i == 0){
      return; // 소수 아님
    }
  }

  // 4번
  if(level == N){
    cout << res << endl;
    return;
  }

  // 3번
  for (int i = 1; i <= 9; i+=2) {
    res += to_string(i);
    back_tracking(level+1);
    res.pop_back();
  }
}

int main() {

  cin >> N;

  for (int i = 0; i < 4; i++) {
    res.clear();
    res += v[i];
    back_tracking(1);
  }

  return 0;
}
