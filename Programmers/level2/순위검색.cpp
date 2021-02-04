#include <bits/stdc++.h>
using namespace std;
//https://programmers.co.kr/learn/courses/30/lessons/72412

/*
<순위 검색>
주요: 구현, 비트마스크, lower_bound
1. info를 stringstream을 이용해 해당 정보를 각각의 idx에 맞게 분리한다.
  0 : cpp backend junior chicken
  1 : java frontend senior pizza
  2 : python
  num : (int)숫자
  ex) python frontend junior chicken
    => idx[0]:2, idx[1]:1, idx[2]:0, idx[3]:1
2. 이제 해당 정보에 맞게 check배열에 값을 갱신해줘야 한다.
3. check[A][B][C][D].push_back(num)
  3.1 A 개발언어, B:직군, C:경력, D:소울푸드에 해당하는 지원자의 점수들이 check[A][B][C][D] 벡터에 들어가 있다.
  3.2 이 때, 쿼리에 "-"가 포함 될 경우를 생각해서 분류해야 한다.
  => 비트마스크를 사용한다.
4. 이제 쿼리를 분석해 해당하는 벡터의 lower_bound를 이용해 값을 리턴한다.

==========
* stringstream 사용법을 알고 있자.
* 이와 같은 문제 풀 시 비트마스크를 적극 활용하자.
* upper_bound, lower_bound 숙지하자.

*/

vector<int> check[5][4][4][4];
vector<int> solution(vector<string> info, vector<string> query) {
  vector<int> answer;
  for (int i = 0; i < info.size(); i++) {
    int idx[4] = {0, };
    int num = 0;

    stringstream ss(info[i]);
    for (int j = 0; j < 5; j++) {
      string temp; ss >> temp;
      if(temp == "cpp" || temp == "backend" || temp =="junior" || temp == "chicken" ) idx[j] = 1;
      else if(temp == "java" || temp == "frontend" || temp =="senior" || temp == "pizza" ) idx[j] = 2;
      else if(temp == "python") idx[j] = 3;
      else num = stoi(temp);
    }

    for (int k = 0; k < 16; k++) {
      int mask = k;
      int light[4] = {0, };
      for (int q = 0; q < 4; q++) {
        light[q] = (mask & (1 << q)) ? idx[q] : 0;
      }
      check[light[0]][light[1]][light[2]][light[3]].push_back(num);
    }
  }

  // lower_bound를 위해 정렬
  for (int a = 0; a < 4; a++) {
    for (int b = 0; b < 3; b++) {
      for (int c = 0; c < 3; c++) {
        for (int d = 0; d < 3; d++) {
          sort(check[a][b][c][d].begin(), check[a][b][c][d].end());
        }
      }
    }
  }


  for (int i = 0; i < query.size(); i++) {
    int idx[4] = {0, };
    int num = 0;

    stringstream ss(query[i]);
    for (int j = 0; j < 8; j++) {
      string temp; ss >> temp;
      if(temp == "and") continue;
      if(temp == "cpp" || temp == "backend" || temp =="junior" || temp == "chicken" ) idx[j/2] = 1;
      else if(temp == "java" || temp == "frontend" || temp =="senior" || temp == "pizza" ) idx[j/2] = 2;
      else if(temp == "python") idx[j/2] = 3;
      else if(temp == "-") idx[j/2] = 0;
      else num = stoi(temp);
    }

    auto bg = check[idx[0]][idx[1]][idx[2]][idx[3]].begin();
    auto ed = check[idx[0]][idx[1]][idx[2]][idx[3]].end();
    int val = lower_bound(bg,ed,num)-bg;
    answer.push_back(check[idx[0]][idx[1]][idx[2]][idx[3]].size() - val);
  }

  return answer;
}
