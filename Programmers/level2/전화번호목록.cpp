#include <vector>
#include <algorithm>
using namespace std;
//https://programmers.co.kr/learn/courses/30/lessons/42577

/*
<전화번호 목록>
주요: 정렬
1. 먼저 길이가 작은 순으로 정렬한다.
2. 이제 겹치는 부분이 있는지 판단한다.
3. 각 결과에 맞게 리턴한다.

*/

bool comp(const string &A, const string &B){
  return A.length() < B.length();
}

bool solution(vector<string> phone_book) {
  bool answer = true;
  sort(phone_book.begin(), phone_book.end(), comp);
  for (int i = 0; i < phone_book.size(); i++) {
    bool check = false;
    string base = phone_book[i];
    for (int k = i+1; k < phone_book.size(); k++) {
      for (int j = 0; j < base.length(); j++) {
        if(base[j] == phone_book[k][j]) check = true;
        else{
          check = false;
          break;
        }
      }
      if(check) return false;
    }
  }
  return true;
}
