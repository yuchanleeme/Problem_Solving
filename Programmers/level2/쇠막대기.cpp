#include <string>
#include <vector>
#include <stack>
using namespace std;
//https://programmers.co.kr/learn/courses/30/lessons/42585

/*
<쇠막대기>
주요: 스택, 아이디어
1. '('가 나오면 스택에 넣는다.
2. ')'가 나오면 두가지 경우로 생각한다.
  2.1 '(' 바로 다음에 ')'가 나오면 레이저이므로 스택에 담겨있는 모든 '('의 조각의 개수를 더한다.
  2.2 이 이외의 ')'가 나오면 막대기의 끝이므로 pop 해주고 하나를 더해준다.
3. 결과 값을 리턴한다.  
==========
* 보통 괄호 문제가 나오면 이렇게 스택이 쓰이는 경우가 많다.

*/

int solution(string arrangement) {
    int answer = 0;
    stack<char> stk;
    for (int i = 0; i < arrangement.length(); i++){
        if(arrangement[i] == '('){
            stk.push('(');
        }
        else if(arrangement[i] == ')'){
            stk.pop();
            if(arrangement[i-1] == '('){      
                answer += stk.size();
            }
            else{
                answer += 1;
            }
        }
    }
    return answer;
}