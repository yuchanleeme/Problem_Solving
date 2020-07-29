#include <vector>
#include <algorithm>
#include <string>
using namespace std;
//https://programmers.co.kr/learn/courses/30/lessons/12899

/*
<124나라의 숫자>
주요: 구현
1. 3진법을 만들되, 기존 3진법에서 0 -> 4 로 바꾼다.
2. 3으로 나눠 떨어질 때는 몫을 1빼준다.
  => ex) 9 는 6 + 3 으로 계산 해야하는데 그냥 몫을 그대로 쓰면  9 + 0 이런 형태가 된다.
3. 각 조건에 맞게 1,2,4를 배치해서 푼다. 
===========
* upper_bound로 3의 제곱수를 찾아내면서 풀었지만 효율성에서 통과하지 못했다.
* 그래서, 1~20까지 계속 써보면서 규칙을 찾았다.
* 직관력을 기르는 연습을 하는데 좋은것 같다.

*/

string solution(int n) {
    string answer = "";
    while(n != 0){
        if(n % 3 == 0){
            answer += "4";
            n = (n/3)-1;
        } 
        else{
            answer += to_string(n%3);
            n /=3;
        }
    }
    reverse(answer.begin(),answer.end());
    return answer;
}
