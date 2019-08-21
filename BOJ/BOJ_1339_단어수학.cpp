#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
using namespace std;
//https://www.acmicpc.net/problem/1339

/*
=======
* 백트래킹으로 풀었더니 시간초과가 났다.

*/
int N, cnt = 0, max_value = 0;
string input;
vector<string> words;
vector<int> visit, seq;
vector<char> alp; // 각각의 알파벳 cnt개
map<char, int> m;

// 입력받은 라인 하나 알파벳에 맞게 계산하는 함수
int cal_individual(int num){
  int idx = 1;
  int res = 0;

  for (int i = words[num].size() - 1; i >= 0; i--) {
    res += idx * m[words[num][i]];
    idx *= 10;
  }
  return res;
}

// 모든 라인들을 더해서 계산하는 함수
int cal_max(){

  int ans = 0;

  for (int i = 0; i < N; i++) {
    ans += cal_individual(i);
  }

  return ans;
}

void back_tracking(int level){

  if(level == cnt){
    // 조합한 순열을 각 알파벳 값에 대응
    for (int i = 0; i < cnt; i++) {
      m[alp[i]] = seq[i];
    }
    // 최대값 계산
    max_value = max(max_value, cal_max());
    return;
  }

  // 백트래킹 구현
  // 10 - cnt 이유 : 최대값 구하는 것이므로 그 아래값 필요가 없다.
  for (int i = 10-cnt; i <= 9 ; i++) {
    if(visit[i] == 0){
      seq.push_back(i);
      visit[i] = 1;
      back_tracking(level + 1);
      visit[i] = 0;
      seq.pop_back();
    }
  }
}

int main() {

  cin >> N;
  visit = vector<int>(10,0);
  
  // 각 10으로 map 초기화, 서로 다른 알파벳 개수 : cnt
  for (int i = 0; i < N; i++) {
    cin >> input;
    words.push_back(input);
    for (int j = 0; j < words[i].size(); j++) {
      if(m[words[i][j]] != 10){
        alp.push_back(words[i][j]);
        m[words[i][j]] = 10;
        cnt++;
      }
    }
  }

  back_tracking(0);

  cout << max_value;

  return 0;
}
