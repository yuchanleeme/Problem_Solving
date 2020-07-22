#include <algorithm>
#include <vector>
using namespace std;
//https://programmers.co.kr/learn/courses/30/lessons/12915

/*
<문자열 내 마음대로 정렬하기>
주요: 정렬
1. 입력받은 벡터를 comp 함수를 이용해 정렬한다.
  1-1. 두 문자가 같으면 사전순으로 정렬
  1-2. 같지 않다면, 그 문자들의 사전순으로 정렬
2. n번째 idx는 전역 선언해줘서 사용한다.

*/

int num;
bool comp(const string &A, const string &B){
  if(A[num] == B[num]){
    return A < B;
  }
  else{
    return A[num] < B[num];
  }
}

vector<string> solution(vector<string> strings, int n) {
    vector<string> answer = strings;
    num = n;
    sort(answer.begin(), answer.end(), comp);
    return answer;
}
