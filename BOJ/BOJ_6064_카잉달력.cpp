#include <iostream>
using namespace std;
//https://www.acmicpc.net/problem/6064

/*
<카잉 달력>
주요: 계산
1. 규칙을 생각해보자.
 => ex) M = 10 , N = 12 : <1:1> , <2:2> .... <10:10>, <1,11>, <2:12>, <3:1> ...
2. 찾아야 하는 x값을 고정해 놓고 푼다.
 => ex) <5:5> --> <5:7> --> <5:9> ... 일정 간격을 두고 변하는것을 알 수 있다.
3. 따라서 x의 첫번째 짝을 찾고 거기부터 y까지 몇바퀴나 돌았는지를 확인하면 된다.
4. 각종 예외상황을 다 계산해야 한다. (나머지가 0일때)
5. max_year을 최소공배수 함수를 이용해서 구한후 그 이상 초과한다면 -1을 출력시키게 한다.

=============
* 브루트 포스로 풀면 당연히 시간초과가 뜬다. 규칙성을 찾아야한다.
* 최소공배수를 이용해야 풀기 편하다.

*/

int lcm(int a, int b){

  int ans = 1, val = 2;
  while(true){
    if(a % val == 0 && b % val == 0){
      ans *= val;
      a /= val, b /= val;
    }
    else{
      val++;
      if(val > max(a,b)){ return ans*a*b;}
    }
  }
}

int main() {

  int T, M, N, x, y, max_year, cnt, std_y;
  bool end_flag;
  cin >> T;

  for (int testcase = 0; testcase < T; testcase++) {
    end_flag = false;
    cnt = 0;
    cin >> M >> N >> x >> y;

    cnt = x % N == 0 ? x/N - 1 : x/N;// 초기 회전수
    std_y = x % N == 0 ? N : x % N; // y의 초기값

    max_year = lcm(M,N); // 최대 연도수를 찾는다.

    while (1) {
      if (std_y == y) { break;} // 정답
      else if(cnt*N + std_y > max_year){
        end_flag = true; //
        break;
      }

      cnt += (std_y + M)/N; // 계산할 동안 N만큼 몇번 돌았는지 카운트

      // 나머지가 0일때를 구분해서 계산
      if((std_y + M) % N == 0){
        std_y = N;
        cnt--; // 중복으로 카운트 되는것을 빼준다.
      }
      else{
        std_y = (std_y + M) % N;
      }
    }

    if(end_flag){
      cout << "-1" << endl;
    }
    else{
      cout << std_y + cnt*N << endl;
    }
  }
  return 0;
}
