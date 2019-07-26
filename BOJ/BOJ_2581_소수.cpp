#include <iostream>
#include <vector>
using namespace std;
//https://www.acmicpc.net/problem/2581

/*
<소수>
주요: 수학 , 브루투포스
1. num 2부터 1씩 증가시키면서 소수를 찾는다.
2. 각각의 num들을 prime의 모든 원소들로 나누었을때 나머지가 0이 없다면 소수이다.
3. 이렇게 소수를 찾으면 prime에 추가해준다.
4. num 값이 M 이상일 때 합(sum)을 구해주고 처음 넘었을 때 idx를 저장한다.
5. sum과 prime[idx]를 출력한다.

*/

int main() {

  int M, N;
  cin >> M >> N;

  vector<int> prime;
  bool first = true;

  int idx, num = 1, sum = 0;
  while (num != N) {

    bool prime_check = true;
    num++;

    for (int i = 0; i < prime.size(); i++) {
      if(num % prime[i] == 0){
        prime_check = false;
        break;
      }
    }

    if(prime_check){
      prime.push_back(num);
      if(num >= M){
        sum += num;

        if(first){
          idx = prime.size();
          first = false;
        }
      }
    }

  }

  if(sum == 0){
    cout << "-1" << endl;
  }
  else{
    cout << sum << endl;
    cout << prime[idx-1];
  }

  return 0;
}
