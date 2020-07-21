#include <vector>
#include <stack>
#include <queue>
using namespace std;
//https://programmers.co.kr/learn/courses/30/lessons/64061

/*
<크레인 인형 뽑기>
주요: 구현, 큐, 스택
1. 우선 큐로 각 라인의 인형들을 모아서 넣는다.
2. 맨위에 있는 인형을 따로 저장하고 옮길 인형을 스택에 넣는다.
3. 만약 따로 저장된 인형과 스택에 넣고 난 후의 인형의 값이 같으면 스택에서 두번 pop한다.
4. pop의 횟수만큼 answer을 증가시킨다(+2)
5. answer를 리턴한다.

*/

stack<int> stk;
queue<int> que[110];

int solution(vector<vector<int>> board, vector<int> moves) {

  int answer = 0;
    // 1번
    for(int i = 0; i < board[0].size(); i++){
        for(int j = 0; j < board[0].size();j++){
            if(board[i][j] != 0){
                que[j].push(board[i][j]);
            }
        }
    }

    for(int i = 0; i < moves.size();i++){
        // 2번
        int now = -1;
        if(!stk.empty()) now = stk.top();
        if(que[moves[i]-1].size() == 0) continue; // 인형 비어있으면 무시
        stk.push(que[moves[i]-1].front());
        que[moves[i]-1].pop();

        // 3,4 번
        if(now != -1 && now == stk.top()){
            stk.pop();
            stk.pop();
            answer += 2;
        }
    }
    return answer;
}
