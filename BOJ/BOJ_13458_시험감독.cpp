#include <iostream>
#include <queue>
using namespace std;
//https://www.acmicpc.net/problem/13458

/*
<시험 감독>
주요 : 구현
1. 원형큐를 이용해 각 방에 감독관이 감시해야 할 남은 응시자의 수를 저장한다.
2. 총 감독관은 각 방마다 꼭 1명씩 있어야 한다. (res += N)
  2-1) 각 방마다 총 감독관이 감시하는 인원을 빼고 남은 인원을 큐에 삽입한다. (que.front() -= A)
  2-2) 만약 모두 감시가 가능한 방이라면 pop만 해준다.
3. 부 감독관은 나머지 응시자들의 남은 수에 결정된다.
  3-1) 응시자들 수를 맡을 수 있는 최대 부감독관의 수를 구한다. (que.front() / B)
  3-2) 다 감시가 가능한다면 그냥 넘어가고 아니라면 부감독관 1명더 추가한다.
4. 모든 감독관의 수를 세서 res로 출력한다.

==========
* 결과값이 int 범위를 넘어가므로 long long으로 선언한다.

*/

int main() {

  int N, A, B;
  long long res = 0;
  cin >> N;
  queue<int> que;

  for (int i = 0; i < N; i++) {
    int input;
    cin >> input;
    que.push(input);
  }
  cin >> A >> B;

  // 총 감독관
  for (int i = 0; i < N; i++) {
    int temp = que.front();

    // 2-1
    if(temp > A){
      temp -= A;
      que.push(temp);
    }

    que.pop();
    res++;
  }

  // 부 감독관
  while (!que.empty()) {
    int tempV = que.front();

    // 3-1
    res += tempV / B;
    // 3-2
    if(tempV % B != 0){ res+=1;}
    que.pop();
  }

  // 4
  cout << res;

  return 0;
}
