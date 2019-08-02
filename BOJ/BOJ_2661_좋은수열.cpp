#include <iostream>
#include <vector>
using namespace std;
//https://www.acmicpc.net/problem/2661

/*
<좋은 수열>
주요: DFS, 백트래킹
1. 길이가 1부터 N이 될때까지 하나씩 숫자를 대입해보면서 좋은 수열을 찾는다. (백트래킹)
2. 규칙을 찾아서 비교한다.
  => ex) seq.size():7, idx:3 -> 5 6 / 34 56 / 123 456 비교한다.
        앞에서 부터 차례대로 서로의 비교대상과 1, 2, 3씩 차이남을 알 수 있다.
3. check_num을 통과한 원소들을 seq배열에 삽입한다.
4. seq의 size가 N이된다면 seq를 출력하고 함수를 종료시킨다.

*/

int N;
vector<int> seq;
bool end_func = false;

bool check_num(int num){

  seq.push_back(num); // 초기값을 넣어줘 비교를 편하게
  vector<int> temp;
  int idx = seq.size() / 2; // 몇개 조사해야하는지

  for (int i = 1; i <= idx; i++) {

    // 2번
    for (int j = 0; j < i; j++) {
      int cal = seq.size() - (2*i) + j; //
      if(seq[cal] == seq[cal+i]){ temp.push_back(cal);}
    }

    // temp의 size와 i가 일치하면 바로 위의 for문에서 수열이 다 일치했다는 뜻
    if(temp.size() == i){
      seq.pop_back(); // 초기값 pop
      return false;
    }
    temp.clear();

  }

  seq.pop_back(); // 초기값 pop
  return true;
}

void back_tracking(int level){

  if(end_func){ return;}

  if(level == N){
    for (int i = 0; i < N; i++) {
      cout << seq[i];
    }
    cout << endl;
    end_func = true;
    return;
  }

  for (int i = 1; i <= 3; i++) {
    if(check_num(i)){
      seq.push_back(i);
      back_tracking(level+1);
      seq.pop_back();
    }
  }
}

int main() {

  cin >> N;

  back_tracking(0);

  return 0;
}
