#include <algorithm>
#include <vector>
using namespace std;
//https://programmers.co.kr/learn/courses/30/lessons/12916

/*
<문자열 내 p와 y의 개수>
주요: 정렬
1. p나 P일때의 개수와 y나 Y일때의 개수를 따로 센다.
2. 두 개의 값을 비교하여 결과를 리턴한다.
==========
* 다 소문자로 만들고 해도 되는데, 어차피 for문 하나에서 끝날 거 같아서 그냥 단순비교했다.

*/

int count[2];
bool solution(string s)
{
    for (int i = 0; i < s.size(); i++) {
      if(s[i] == 'P' || s[i] == 'p') count[0]++;
      else if(s[i] == 'Y' || s[i] == 'y') count[1]++
    }
    return count[0] == count[1];
}
