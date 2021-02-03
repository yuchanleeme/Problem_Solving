#include <bits/stdc++.h>
using namespace std;
//https://programmers.co.kr/learn/courses/30/lessons/68936

/*
<쿼드압축 후 세기>
주요: 분할 정복
1. 4영역으로 분할하면서 각 숫자를 조사한다.
2. 영역의 사이즈가 1일 때 해당 숫자를 리턴한다.
3. 4영역의 숫자가 모두 같지 않으면 해당 숫자의 값을 증가시켜주고 2를 리턴한다.
4. 4영역의 숫자가 같고 리턴값이 2가 아나라면 해당 숫자의 값을 리턴한다.
5. 이렇게 계산된 최종 answer를 리턴한다.

==========
* vector 참조 시 &로 한다. (시간 초과 원인)
 => vector<vector<int>> &arr

*/

vector<int> answer = {0, 0, 0, };

int divide(int x, int y, int div, vector<vector<int>> &arr){
  if(div == 1) return arr[x][y];
  else{
    int num = div/2;
    int a = divide(x, y, num, arr);
    int b = divide(x, y+num, num, arr);
    int c = divide(x+num, y, num, arr);
    int d = divide(x+num, y+num, num, arr);

    if(a == b && b == c && c== d && a != 2) return a;
    else{
      answer[a]++; answer[b]++; answer[c]++; answer[d]++;
      return 2;
    }
  }
}

vector<int> solution(vector<vector<int>> arr) {

  int num = arr.size();
  int res = divide(0,0,num,arr);
  answer[res]++;
  answer.pop_back();

  return answer;
}
