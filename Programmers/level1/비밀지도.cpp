#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
//https://programmers.co.kr/learn/courses/30/lessons/17681

/*
<비밀 지도>
주요: 구현, 비트 연산
1. 비트 연산자를 이용해서 푼다.
2. 두개 중 하나라도 벽이 있을때는 1이므로 or 연산을 이용해서 값을 알아낸다.
3. &연산을 통해 벽의 위치를 만든다.
4. reverse 함수를 통해 원하는 위치를 잡아낸다.
5. 결과값을 리턴한다.

*/

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
  vector<string> answer;
  for (int i = 0; i < n; i++) {
    string temp = "";
    int num = arr1[i] | arr2[i];
    int tempN = n;
    while (tempN--) {
      if(num & 1) temp += "#";
      else temp += " ";
      num /= 2;
    }
    reverse(temp.begin(), temp.end());
    answer.push_back(temp);
  }
  return answer;
}
