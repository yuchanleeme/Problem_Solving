#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
//https://programmers.co.kr/learn/courses/30/lessons/17682

/*
<다트 게임>
주요: 구현
1. 우선 숫자영역을 구분해서 새로운 벡터에 넣는다.
  => ex) 10D*20T# => 10D(계산값), *, 20T(계산값), #
2. 문제 조건에 맞게 각 다트 점수에 *과 # 처리를 한다.
3. '*'의 경우에는 3가지로 나눠서 생각한다.
  3.1 처음 다트점수에서 나왔을때 : 첫 점수만 x2배 해준다. (idx-1)
  3.2 두개 뒤 idx가 * 또는 # 일때 : 첫점수, 두번째 점수를 찾아 x2배 해준다. (idx-1, idx-3)
  3.3 나머지 : (idx-1, idx-2)
4. 최종적으로 변형된 다트 점수들을 다 더한후 리턴해준다.
==========
* to_string, stoi 함수를 쓰면서 구현했는데, 애초에 숫자, 연산자 벡터 두개로 나눠서 풀면 좀 더 효율적일것 같다.
  => 단, 연산자 벡터는 pair형(idx 위치 포함)
* 구현력 기를 필요가 있다고 생각한다.

*/

int solution(string dartResult) {
  int answer = 0;
  string num = "";
  vector<string> seq;
  for (int i = 0; i < dartResult.length(); i++) {
    if('0' <= dartResult[i] && dartResult[i] <='9'){
      num += dartResult[i];
    }
    else{
      if(dartResult[i] == 'S'){
        seq.push_back(num);
        num = "";
      }
      else if(dartResult[i] == 'D'){
        seq.push_back(to_string(stoi(num)*stoi(num)));
        num = "";
      }
      else if(dartResult[i] == 'T'){
        seq.push_back(to_string(stoi(num)*stoi(num)*stoi(num)));
        num = "";
      }
      else{
        string temp = "";
        temp += dartResult[i];
        seq.push_back(temp);
      }
    }
  }

  int number = 0;
  for (int i = 0; i < seq.size(); i++) {
    if(seq[i] == "*"){
      if(i >= 2){
        if(seq[i-2] == "*" || seq[i-2] == "#")
          seq[i-3] = to_string(stoi(seq[i-3])*2);
        else
          seq[i-2] = to_string(stoi(seq[i-2])*2);
      }
      seq[i-1] = to_string(stoi(seq[i-1])*2);
    }
    else if(seq[i] == "#"){
      seq[i-1] = to_string(stoi(seq[i-1])*(-1));
    }
  }

  for (int i = 0; i < seq.size(); i++) {
    if(seq[i] != "*" && seq[i] != "#")
      answer += stoi(seq[i]);
  }

  return answer;
}
