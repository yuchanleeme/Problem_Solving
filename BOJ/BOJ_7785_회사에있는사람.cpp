#include <iostream>
#include <vector>
#include <map>
#include <cstdlib>
#include <algorithm>
using namespace std;
//https://www.acmicpc.net/problem/7785

/*
<회사에 있는 사람>
주요: map
1. map에 각 사람과 상태를 저장한다.
  1-1) enter 했으면 상태를 1로해서 저장
  1-2) leave 했으면 map에서 삭제
2. 맵에 저장된 값들을 string 벡터에 저장한다.
3. 정렬 해서 출력한다.

*/

int main() {

  int N;
  cin >> N;

  map<string, int> M;

  // 1번
  for (int i = 0; i < N; i++) {
    string name, state;
    cin >> name >> state;
    if(M[name] == 0 && state == "enter"){
      M[name] = 1;
    }
    else if(M[name] == 1 && state == "leave"){
      M.erase(name);
    }
  }

  // 2번
  vector<string> res;
  for(auto it = M.begin(); it != M.end(); it++){
    res.push_back(it->first);
	}

  // 3번
  sort(res.begin(),res.end());
  for (int i = res.size()-1; i >= 0; i--) {
    cout << res[i] << '\n';
  }

  return 0;
}
