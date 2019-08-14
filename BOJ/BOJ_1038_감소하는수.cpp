#include <iostream>
#include <vector>
using namespace std;
//https://www.acmicpc.net/problem/1038

/*
<감소하는 수>
주요: dfs, 백트래킹
1. 최대 감소하는 수는 9876543210임을 참고하자.
  => 감소하는 수를 세봤자 10자리 숫자 내임을 알 수 있다.
2. 최소 1자리수 부터 10자리수 까지 될 수 있는 감소하는 수를 백트래킹을 이용해 다 찾는다.
3. 하나씩 찾을 때마다 count를 올려주고 N번째를 찾으면 출력한다.
4. N이 0이거나 N을 못찾았을 경우의 예외사항도 출력한다.

*/

int N, count = 0;
vector<int> abc;
bool end_game = false;

void dfs(int level, int num, int x){

  // 3번
  if(level == num){
    count++;
    if(count == N){
      for (int i = 0; i < abc.size(); i++) {
        cout << abc[i];
      }
      end_game = true;
    }
    return;
  }

  for (int i = 0; i <= 9; i++) {
    if(abc.empty()){
      if(i != 0){
        abc.push_back(i);
        dfs(level+1, num, i);
        abc.pop_back();
      }
    }
    else{
      if(abc.back() > i){
        abc.push_back(i);
        dfs(level+1, num, i);
        abc.pop_back();
      }
    }
  }
}

int main() {

  cin >> N;

  // 2번
  for (int i = 1; i <= 10; i++) {
    dfs(0, i, 0);
    if(end_game){ break;}
  }

  // 4번
  if(N == 0){
    cout << "0";
  }
  else if(!end_game){
    cout << "-1";
  }

  return 0;
}
