#include <iostream>
#include <vector>
#include <stack>
using namespace std;
//https://www.acmicpc.net/problem/17298

/*
<오큰수>
주요: 스택
1. 입력받은 값들을 거꾸로 스택에 값을 넣고 입력받은 값들을 거꾸로 비교한다.
2. 스택의 top값이 입력값보다 작거나 같을 때까지 스택의 값들을 빼준다.
  => 이렇게 했을 때 결과 스택의 top값이 그 idx 기준 오큰수가 된다.
  => 그 top값을 ans벡터에 넣어준다.
3. 만약에 모두 pop해서 MAX값에 도달하면 더이상 큰 수가 없으므로 -1을 ans에 넣어준다.
4. 다 비교했으면 ans 벡터를 idx의 반대부터 출력한다.

=========
* 단순 vector로 크기 비교 했더니 시간초과가 떴다.
  => 그래서 다른 방법을 찾아보다가 같은 수가 여러번 나오는것을 발견,응용해 풀었다.

*/

int MAX_VALUE = 1000001;
int main(int argc, char const *argv[]) {

  int N, input;
  stack<int> stk;
  vector<int> seq, ans;

  scanf("%d", &N);
  for (int i = 0; i < N; i++) {
    scanf("%d", &input);
    seq.push_back(input);
  }

  stk.push(MAX_VALUE);
  while (N--) {
    while(stk.top() <= seq[N]){
      stk.pop();
    }

    if(stk.top() == MAX_VALUE){
      ans.push_back(-1);
    }
    else{
      ans.push_back(stk.top());
    }
    stk.push(seq[N]);
  }

  for (int i = ans.size()-1; i >= 0; i--) {
    printf("%d ", ans[i]);
  }

  return 0;
}
