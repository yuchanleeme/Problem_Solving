#include <bits/stdc++.h>
using namespace std;
//https://programmers.co.kr/learn/courses/30/lessons/64065

/*
<튜플>
주요: 구현, 정렬
1. 문자열을 먼저 기준에 맞게 split한다.
2. 각 튜플 개체의 개수가 작은 번호들을 알아낸다. (정렬)
3. 개수가 작은 것부터 찾으면서 중복처리를 한다.
  => 개수가 적은 튜플 부터 순차적으로 중복처리하며 찾으면, 각 튜플마다 수가 하나씩 남게 된다.
  => 이 남은 숫자를 answer 벡터에 넣고 리턴한다.
==========
* string을 더 깔끔하게 split하는 방법으로 시간을 더 단축할 수도 있을것 같다.

*/

vector<int> seq[505]; // split한 각 튜플의 정보
vector<pair<int, int> > info; // {개수, 위치} 형태의 정보 벡터
int visit[10101010];  // 방문배열

vector<int> solution(string s) {
  vector<int> answer;
  int idx = 0;
  for (int i = 1; i < s.length()-1; i++) {
    // '{'를 기준으로 튜플을 나눈다.
    if(s[i] == '{'){
      int temp = 0;
      // '}'를 기준으로 튜플 나누는것을 끝낸다.
      while(s[i] != '}'){
        i++;
        // ',이나 '}'를 만나면 이제까지 만든 임시 수를 seq에 넣는다.
        if(s[i] == ',' || s[i] == '}'){
          seq[idx].push_back(temp);
          temp = 0;
        }
        else{
          // 임시 수를 만든다. (string이므로)
          temp *= 10;
          temp += s[i] -'0';
        }
      }
      info.push_back({seq[idx].size(), idx}); // 튜플의 정보를 넣는다.
      idx++;
    }
  }

  // 튜플의 총 개수를 기준으로 정렬한다.
  sort(info.begin(),info.end());

  // 3번
  for (int i = 0; i < idx; i++) {
    int order = info[i].second;
    for (int j = 0; j < seq[order].size(); j++) {
      if(visit[seq[order][j]] == 0){
        answer.push_back(seq[order][j]);
        visit[seq[order][j]] = 1;
        break;
      }
    }
  }

  return answer;
}
