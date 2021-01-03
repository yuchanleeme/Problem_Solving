#include <bits/stdc++.h>
#include <string>
using namespace std;
//https://www.acmicpc.net/problem/1662

/*
<압축>
주요: 재귀
1. 재귀를 돌면서 괄호 단위로 문자열의 길이를 조사한다.
2. func()의 리턴값은 괄호 안 문자열의 길이이다.

*/

string s;
int now_idx; // 조사하고 있는 idx

int func(){
  int temp_size = 0;

  for (int i = now_idx; i < s.length(); i++) {
    if(s[i] == '('){
      int round = s[i-1] - '0'; // 몇번 반복 되는지 K(Q) 의 K
      temp_size--; // round 값 제외
      now_idx = i+1;  // '(' 다음으로 now_idx 갱신

      temp_size += func()* round; // 가져온 서브 괄호의 길이 세기

      i = now_idx; // i 값 now_idx값으로 갱신
    }
    else if(s[i] == ')'){
      now_idx = i;  // now_idx 갱신
      return temp_size; // 현재 까지의 길이 리턴
    }
    else{
      temp_size++; // 현재 괄호 내의 길이 세기
    }
  }
  return temp_size; // 마지막 리턴
}

int main(int argc, char const *argv[]) {

  cin >> s;
  cout << func();

  return 0;
}
