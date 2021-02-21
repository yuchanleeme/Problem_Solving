#include <bits/stdc++.h>
using namespace std;
//https://programmers.co.kr/learn/courses/30/lessons/68935

/*
<3진법 뒤집기>
주요: 수학
1. 먼저 주어진 값을 3진법으로 구한다. (temp)
2. temp값을 앞에서부터 3을 곱하는 과정을 거쳐 10진수로 만든다.
3. 그 값을 리턴한다.

*/

int solution(int n) {
  int answer = 0;
  string temp = "";
  while (n != 0) {
    temp += to_string(n % 3);
    n /= 3;
  }
  reverse(temp.begin(), temp.end());

  int num = 1;
  for (int idx = 0; idx < temp.length(); idx++) {
    string val = ""; val += temp[idx];
    answer += stoi(val)*num;
    num *= 3;
  }
  return answer;
}
