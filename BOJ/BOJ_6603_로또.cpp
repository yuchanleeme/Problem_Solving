#include <iostream>
#include <vector>
using namespace std;
//https://www.acmicpc.net/problem/6603

/*
<로또>
주요:
1.

*/

int main() {

  int k, num;
  vector<int> lotto;
  vector<int> possibility(6, 1);
  vector<int> ans;

  while (cin >> k && k != 0) {
    for (int i = 0; i < k; i++) {
      cin >> num;
      lotto.push_back(num);
      if(i > 6){
        possibility.push_back(0);
      }
    }

    int last_idx, fix_idx = ;
    for (int i = 0; i < k; i++) {
      if(possibility[i] == 1){
        last_idx = i;
        cout << lotto[i] << " ";
      }
    }
    if(last_idx < k-1){
      possibility[last_idx] = 0;
      possibility[last_idx + 1] = 1;
    }
    else{

    }


  }



  return 0;
}
