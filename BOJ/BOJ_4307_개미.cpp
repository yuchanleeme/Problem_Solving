#include <iostream>
#include <algorithm>
using namespace std;
//https://www.acmicpc.net/problem/4307

/*
<개미>
주요: 개미의 방향이 바뀌는것을 다르게 생각해 본다.
1. '특정' 개미의 떨어졌을때 시간을 구하는 것이 아니라 모든 개미가 떨어졌을때 시간의 최솟값과 최댓값을 구하는 것이다.
2. 개미가 만날 때를 방향이 바뀌는게 아니라 '교차'한다고 생각하면 이해하기 쉽다.
3. 1,2번 개미가 서로 마주하는 방향에서 이동해 만났다고 하자.
  => 1번 개미가 방향을 바꿔 막대 끝으로 가는 거리는 2번개미가 방향을 바꾸지 않고 막대 끝까지 가는 거리와 같다.
  => 따라서 2번 개미 입장에서는 결국 막대 끝까지 방향을 바꾸지 않고 가는 값과 결국 같은 것이다.
4. 결국 막대에 떨어지는 개미들을 하나하나 분리해서 생각하면 된다.
=========
가장 빠른 시간 : 막대길이 절반을 기준으로 개미위치와의 차의 절댓값이 가장 큰 개미의 떨어지는 최단시간
가장 느린 시간 : 양 막대의 끝까지 도달하는 시간이 제일 긴 개미가 떨어질때까지 걸리는 시간

*/


int main() {

  int T, l, n, min_time, max_time;

  cin >> T;

  for (int i = 0; i < T; i++) {
    cin >> l >> n;

    int location[n];
    min_time = 0; max_time = 0;

    for (int j = 0; j < n; j++) {
      cin >> location[j];

      if(location[j] >= l/2){
        min_time = max(min_time, l-location[j]);
        max_time = max(max_time, location[j]);
      }
      else{
        min_time = max(min_time, location[j]);
        max_time = max(max_time, l - location[j]);
      }
    }

    cout << min_time << " " << max_time << endl;

  }

  return 0;
}
