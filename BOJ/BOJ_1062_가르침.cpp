#include <bits/stdc++.h>
using namespace std;
//https://www.acmicpc.net/problem/1062

/*
<가르침>
주요: 문자열, 백트래킹
1. 각 단어의 철자를 알파벳 단위로 나누어서 배열에 저장한다.
2. 백트래킹을 통해 가능한 경우를 다 조사한다.
  2-1. a,c,i,n,t : level에 포함시키지 않고 조합을 조사한다.
  2-2. 그 외 : level+1 해서 조합을 조사한다.
3. 조합의 개수가 K-5개이면 해당 조합으로 몇개의 단어를 읽을 수 있는지 체크한다.
4. 최댓값을 구해 출력한다.

*/

int N, K, ans;
int alpha[55][30];
int alphaCheck[30];
vector<string> interval; // 사이 문자열 값

void backtracking(int num, int level){

  if(level == (K-5)){

    int cnt = 0;
    for (int i = 0; i < N; i++) {
      bool canRead = true;
      for (int j = 0; j < interval[i].size(); j++) {
        int idx = interval[i][j] -'a';
        if(idx == 0 || idx == 2 || idx == 8 || idx == 13 || idx == 19) continue;
        if(alphaCheck[idx] == 0){
          canRead = false;
          break;
        }
      }
      if(interval[i].size() == 0 || canRead )
        cnt++;
    }
    ans = max(ans, cnt);
    return;
  }

  for (int i = num+1; i < 26; i++) {
    if(i == 0 || i == 2 || i == 8 || i == 13 || i == 19) continue;
    alphaCheck[i]++;
    backtracking(i, level+1);
    alphaCheck[i]--;
  }
}


int main(int argc, char const *argv[]) {
  cin >> N >> K;
  for (int i = 0; i < N; i++) {
    string temp; cin >> temp;

    interval.push_back(temp.substr(4, temp.length()-8));

    for (int j = 0; j < interval[i].length(); j++) {
      alpha[i][interval[i][j]-'a']++;
    }
  }

  if(K < 5) return !printf("0");

  // a n t i c
  for (int i = 0; i < 26; i++) {
    if(i == 0 || i == 2 || i == 8 || i == 13 || i == 19){
      backtracking(i, 0);
    }
    else{
      alphaCheck[i]++;
      backtracking(i, 1);
      alphaCheck[i]--;
    }
  }
  cout << ans;
  return 0;
}
