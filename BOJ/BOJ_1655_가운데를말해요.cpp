#include <iostream>
#include <queue>
#include <vector>
using namespace std;
//https://www.acmicpc.net/problem/1655

/*
<가운데를 말해요>
주요: 힙
1. 중간값을 기준으로 그 값보다 작은 값들의 집합과 큰 값들의 집합으로 나눈다.

*/

int main() {
  freopen("1aa.txt", "r", stdin);

  priority_queue<int, vector<int> , less<int> > max_heap;
  priority_queue<int, vector<int> , greater<int> > min_heap;

  vector<int> value;
  int N, mid, input;

  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> input;

    if(max_heap.empty()){
      max_heap.push(input); // 1번
    }else if(min_heap.empty()){
      if(max_heap.top() <= input){
        min_heap.push(input);
      } // 2번
      else{
        min_heap.push(max_heap.top());
        max_heap.pop();
        max_heap.push(input);
      }
    }
    else{
      if(max_heap.top() > input){
        // 중간값 기준 작을때
        // printf("1 : %d\n",input);
        if(max_heap.size() > min_heap.size()){
          min_heap.push(max_heap.top());
          max_heap.pop();
        }
        max_heap.push(input);
      }
      else if(min_heap.top() > input && input >= max_heap.top()){
        // 중간값
        // printf("2 : %d\n",input);
        if(max_heap.size() > min_heap.size()){
          min_heap.push(input);
        }
        else{
          max_heap.push(input);
        }
      }
      else if(min_heap.top() <= input){
        // 중간값 기준 클 때
        // printf("3 : %d\n",input);
        if(max_heap.size() > min_heap.size()){
          min_heap.push(input);
        }
        else{
          max_heap.push(input);
        }
      }
    }
    cout << max_heap.top()<< "\n";
  }

  return 0;
}
