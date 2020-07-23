#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
//https://programmers.co.kr/learn/courses/30/lessons/12928

/*
<약수의 합>
주요: 수학
1. 루트 n 까지만 구하면 된다.
2. 약수는 서로 짝이 있으므로 그 짝들을 더해준다.
3. 단, 짝이 같을 경우는 한번만 더해준다.
4. 최종 결과를 리턴한다

*/

int solution(int n) {
    int answer = 0;
    for (int i = 1; i <= sqrt(n); i++) {
      if(n % i == 0){
        if(i == n/i) answer +=i;
        else answer += (i + n/i);
      }
    }
    return answer;
}
