#include <iostream>
#include <stack>
using namespace std;
// https://www.acmicpc.net/problem/1874

/*
<스택 수열>
주요: 스택의 기능들을 이용한다.
1. 입력받을 값의 data 배열(크기 N), 정수값을 지정할 value, data배열의 위치를 알려줄 idx 지정한다.
2. 값이 출력될 res배열은 data 배열의 크기(N)의 2배로 한다. (push,pop을 한번씩 해야하므로 2 * N)
3. data 배열을 처음부터 전부 조사한다.
4-1. 스택이 비어있거나 스택의 top 값이 찾으려는 data[idx] 와 다르면 value를 push 하고 res에 '+'를 저장한다.
4-2. push를 해주다가 스택의 top 값이  N을 초과하면 스택 수열을 만들 수 없으므로 break해준다.
5. 위의 상황이 아니라면 pop 해주고 res에 '-'를 저장한다.
6-1. idx 가 N 값과 같으면 모든 value들이 pop 된것이므로 저장되어있던 res 배열을 출력한다.
6-2. 위의 상황이 아니라면 스택 수열을 만들 수 없으므로 "NO"를 출력한다.

*/

int main() {

  int N, data[100001], value = 1, idx = 0;
  char res[200002]; // 2번
  stack <int> stk;

  scanf("%d", &N);

  for (int i = 0; i < N; i++) {
    scanf("%d", &data[i]);
  }

  for (int j = 0; idx < N; j++) {

    // 4,5번
    if(stk.empty() || stk.top() != data[idx]){
      stk.push(value++);
      res[j] = '+';
      if (stk.top() > N) {
        break;
      }
    }
    else{
      stk.pop();
      res[j] = '-';
      idx++;
    }
  }

  // 6번
  if(idx == N){
    for (int j = 0; j < 2*N; j++) {
      printf("%c\n", res[j]);
    }
  }
  else{
    printf("NO\n");
  }

  return 0;
}
