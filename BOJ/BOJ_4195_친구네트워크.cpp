#include <iostream>
#include <vector>
#include <map>
using namespace std;
//https://www.acmicpc.net/problem/4195

/*
<집합의 표현>
주요: 유니온 파인드
1. 유니온 파인드를 이용해 문제를 풀이한다.
2. map을 통해 각각의 친구 번호를 저장한다.
  => 새로운 이름의 string값이 주어질 때 friend_idx++해준다.
3. 네트워크 만들기 전 초기 값은 본인 혼자인 1이다.
4. 서로소 집합을 합칠 때 흡수되는 트리의 친구수를 더해준다.

===========
* 부모의 friends_num을 참조해야한다.
  => 아니면 트리안에 모든 값들을 동기화시켜야 한다.

*/

const int MAX_N = 1e6+1;
map<string, int> mp;
int par[MAX_N], friends_num[MAX_N];

void init(){
  for (int i = 1; i <= MAX_N; i++) {
    par[i] = i;
    friends_num[i] = 1;
  }
}

int find(int x){

  if(par[x] == x){
    return x;
  }
  else{
    return par[x] = find(par[x]);
  }
}

void unite(int x, int y){

  x = find(x), y = find(y);
  if(x == y){
    return;
  }
  par[x] = y;
  friends_num[y] += friends_num[x];
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int T;
  cin >> T;

  for (int testcase = 0; testcase < T; testcase++) {
    int F;
    cin >> F;
    init();
    mp.clear();
    int friend_idx = 1;
    for (int i = 0; i < F; i++) {
      string aa, bb;
      cin >> aa >> bb;
      if(mp[aa] == 0){
        mp[aa] = friend_idx++;
      }
      if(mp[bb] == 0){
        mp[bb] = friend_idx++;
      }

      if(find(mp[aa]) != find(mp[bb])){
        unite(mp[aa], mp[bb]);
      }
      cout << friends_num[find(mp[aa])] << '\n';
    }
  }

  return 0;
}
