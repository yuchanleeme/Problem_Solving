#include <iostream>
#include <set>
using namespace std;
//https://www.acmicpc.net/problem/7662

/*
<이중 우선순위 큐>
주요: multiset
1. 멀티셋의 성질을 이용해서 푼다.
2. 입출력에 주의한다.

==========
* set에서의 erase 활용법 주의
* 우선순위큐 두개 만들어서 check 배열 쓰는 방법도 있다.

*/

int main() {

  int T, k;
  cin >> T;

  for (int testcase = 0; testcase < T; testcase++) {
    cin >> k;

    multiset<int> set_num;
    for (int order = 0; order < k; order++) {
      string op;
      int num;
      cin >> op >> num;
      if(op[0] == 'I'){
        set_num.insert(num);
      }
      else if(op[0] == 'D' && !set_num.empty()){
        if(num == 1){
          set_num.erase(--set_num.end());
        }
        else if(num == -1){
          set_num.erase(set_num.begin());
        }
      }
    }
    
    if(!set_num.empty()){
      cout << *(--set_num.end()) << " " << *set_num.begin() << '\n';
    }
    else{
      cout << "EMPTY" << '\n';
    }
  }

  return 0;
}
