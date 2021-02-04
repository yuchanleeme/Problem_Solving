#include <bits/stdc++.h>
using namespace std;
//https://programmers.co.kr/learn/courses/30/lessons/72411

/*
<메뉴 리뉴얼>
주요: map, 정렬
1. 백트래킹을 통해 각 단품 메뉴 조합의 경우의 수를 나눈다.
  => 이 때, map을 사용하여 개수를 센다.
2. map에 들어있는 item들 중에 2 이상의 값을 가진 항목들을 res배열에 넣는다.
3. res배열을 값이 큰 순으로 정렬한다.
4. 정렬된 res 배열을 순회하면서 문제 조건에 맞는 값들을 찾아 answer 벡터에 넣는다.
5. 최종적으로 선별된 answer 벡터를 리턴한다.
==========
* "AD": 2번, "AC": 4번이면 "AC"만 출력하게 한다. (2개 코스 중 가장 많이 주문된 것)

*/

unordered_map<string, int> m;
vector<pair<int,string> > res;
string seq = "";

void backtracking(int num, int level, int target, string st) {
  if(seq.length() == target){
    m[seq]++;
    return;
  }

  for (int i = num; i < st.length(); i++) {
    seq += st[i];
    backtracking(i+1, level+1, target, st);
    seq.pop_back();
  }
}

vector<string> solution(vector<string> orders, vector<int> course) {
  vector<string> answer;

  for (int i = 0; i < orders.size(); i++) {
    sort(orders[i].begin(), orders[i].end());
    for(int j = 0; j < course.size(); j++){
      backtracking(0, 0, course[j], orders[i]);
    }
  }

  for (auto item: m) {
    if(item.second >= 2) res.push_back({item.second, item.first});
  }
  sort(res.rbegin(),res.rend());

  int check[12] = {0, };
  for (size_t i = 0; i < res.size(); i++) {
    int num = res[i].second.length();
    if(check[num] == 0 || check[num] == res[i].first){
      answer.push_back(res[i].second);
      check[num] = res[i].first;
    }
  }

  sort(answer.begin(), answer.end());

  return answer;
}
