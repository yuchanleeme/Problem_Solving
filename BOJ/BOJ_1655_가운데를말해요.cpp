#include <iostream>
#include <queue>
using namespace std;
//https://www.acmicpc.net/problem/1655

/*
<가운데를 말해요>
주요: 힙
1. 중간값을 기준으로 그 값보다 작거나 같은 값들의 집합(이하A)과 큰 값들의 집합(이하B)으로 나눈다.
2. A집합의 가장 큰 원소는 중간값이고 이 값을 출력할것이므로 항상 A집합의 크기는 B집합의 크기보다 같거나 1커야한다.
3. 이제 A집합과 B집합의 top값의 크기를 비교해서 둘의 순서를 맞춰준다.
4. 마지막에 중간값(max_heap.top())을 출력한다.

*/

int main() {

  priority_queue<int> max_heap;
  priority_queue<int, vector<int> , greater<int> > min_heap;

  int N, input;

  scanf("%d", &N);
  for (int i = 0; i < N; i++) {
    scanf("%d", &input);

    // 2번 조건을 맞추기 위함
    if(max_heap.empty()){
      max_heap.push(input);
    }
    else if(max_heap.size() == min_heap.size()){
      max_heap.push(input);
    }
    else{
      min_heap.push(input);
    }

    // 3번
    if(!max_heap.empty() && !min_heap.empty()){
      if(max_heap.top() >= min_heap.top()){
        max_heap.push(min_heap.top());
        min_heap.push(max_heap.top());
        max_heap.pop();
        min_heap.pop();
      }
    }
    printf("%d\n", max_heap.top());
  }

  return 0;
}
