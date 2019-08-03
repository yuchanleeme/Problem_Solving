#include <iostream>
#include <vector>
using namespace std;
//https://www.acmicpc.net/problem/14888

/*
<연산자 끼워넣기>
주요: DFS, 백트래킹
1. 연산자를 중복 없이 조합을 만들어 계산을 한다.
  1-1. ex) +,-,x,÷(0123)/ +,+,-,-(0011)/ x,÷,x,÷(2323)
  1-2. 위의 예처럼 하나의 순열을 만들어 res벡터에 삽입한다.
  1-3. 이과정에서 백 트래킹을 이용한다.
2. cal 함수를 호출해 위의 저장된 res벡터의 연산자에 따라 nums의 숫자들을 계산한다.
3. 연산자를 N-1개 저장했으면 계산을 한다.
  3-1. 계산된 결과값이 처음 입력받는 것이면 max, min 둘 다에 저장한다.
  3-2. 나머지 경우는 최소, 최대 비교해서 각 값에 저장한다.
4. 모든 순열을 조사한 뒤 maxValue, minValue를 출력한다.

*/

int N, maxValue, minValue;
bool first_value = true;
vector<int> num;
vector<int> op;
vector<int> res;
vector<int> visit;

// 2번
int cal(){

  int result = num[0];

  for (int i = 0; i < N-1; i++) {
    if(res[i] == 0){ result += num[i+1];}
    else if(res[i] == 1){ result -= num[i+1];}
    else if(res[i] == 2){ result *= num[i+1];}
    else if(res[i] == 3){ result /= num[i+1];}
  }

  return result;
}

void dfs(int level){

  if(level == N-1){
    int ans = cal();

    // 3-1번
    if(first_value){
      maxValue = ans;
      minValue = ans;
      first_value = false;
      return;
    }

    // 3-2번
    if(ans > maxValue){
      maxValue = ans;
    }
    else if(ans < minValue){
      minValue = ans;
    }
    return;
  }

  // 1-2번, 1-3번
  for (int j = 0; j < op.size(); j++) {
    if(visit[j] == 0){
      res.push_back(op[j]);
      visit[j] = 1;
      dfs(level + 1);
      visit[j] = 0;
      res.pop_back();
    }
  }
}

int main(){

	cin >> N;

  int input;
  for (int i = 0; i < N; i++) {
    cin >> input;
    num.push_back(input);
  }

  // 1-1번
  for (int i = 0; i < 4; i++) {
    cin >> input;
    for (int j = 0; j < input; j++) {
      op.push_back(i);
    }
  }

  visit = vector<int>(op.size(), 0);

  dfs(0);

  // 4번
  cout << maxValue << endl << minValue;
}
