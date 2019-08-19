#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
//https://www.acmicpc.net/problem/1759

/*
<암호 만들기>
주요: DFS, 백트래킹
1. 우선 비정렬로 받은 문자들을 알파벳순으로 정렬한다.
2. 백트래킹을 이용해 구현한다.
  -> 모음이면 vow, 자음이면 con 값을 증가시켜주어 개수를 세준다.
  -> DFS를 통해 L자리수의 암호를 만들었을때 vow가 1이상인지, con이 2이상인지 확인한다.
  -> 조건에 맞으면 출력한다.
3. 편의성을 위해 계산함수를 만들어 자음일때, 모음일때를 구분해 계산한다.
4. 모든 값들을 출력했으면 종료한다.

*/

void back_tracking(int,int);
void cal(int&, char, int, int);
int L, C, vow = 0, con = 0;
vector<char> code;
vector<char> ans;

void cal(int &value, char code, int level, int idx){
  value++;
  ans.push_back(code);
  back_tracking(level+1, idx+1);
  ans.pop_back();
  value--;
}

void back_tracking(int level, int idx){

  if(level == L){
    if(vow >= 1 && con >= 2){
      for (int i = 0; i < ans.size(); i++) {
        cout << ans[i];
      }
      cout << endl;
      return;
    }
    else{
      return;
    }
  }

  for (int i = idx; i < code.size(); i++) {
    if(code[i] == 'a' || code[i] == 'e' || code[i] == 'i' || code[i] == 'o' || code[i] == 'u'){
      cal(vow, code[i], level, i);
    }
    else{
      cal(con, code[i], level, i);
    }
  }
}

int main() {

  char input;
  cin >> L >> C;

  for (int i = 0; i < C; i++) {
    cin >> input;
    code.push_back(input);
  }

  sort(code.begin(),code.end());

  back_tracking(0, 0);

  return 0;
}
