#include <vector>
#include <string>
#include <stack>
using namespace std;
//https://programmers.co.kr/learn/courses/30/lessons/42588

/*
<탑>
주요: 스택
1. 미리 탑의 개수 만큼의 answer 벡터를 만들어 놓는다. (0으로 초기화 되어있음)
2. heights의 뒤에서부터 스택에 넣는다. ({높이, 원래 위치} 형태의 pair형으로 넣는다.)
3. 현 스택의 top 값이 현재 탑의 위치보다 낮으면 pop 해주고 그때의 탑 idx 번호를 스택의 top idx answer에 저장한다.
  => ex) stack.top() = {10, 2}, height[x] = 11 .... answer[2] = x
4. 이 후 탑의 정보를 스택에 넣는다.
5. 모든 탑에 대하여 이 과정을 반복한다.
6. 결과를 리턴한다.
==========
* 원래는 스택을 비우면서 0을 넣어야 하지만 처음 초기화 할때 이미 0으로 만들었기 때문에 생략했다.
* stack이나 큐가 비었을때 stk.top(), que.fron() 하는 부분을 조심해야 한다.

*/

vector<int> solution(vector<int> heights) {
    stack<pair<int, int> > stk;
    vector<int> answer(heights.size());
    for (int i = heights.size()-1; i >= 0; i--){
        while(!stk.empty() && stk.top().first < heights[i]){
            answer[stk.top().second] = i+1;
            stk.pop();
        }
        stk.push({heights[i], i});
    }
    return answer;
}
