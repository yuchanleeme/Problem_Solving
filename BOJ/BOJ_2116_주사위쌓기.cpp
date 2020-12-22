#include <bits/stdc++.h>
using namespace std;
//https://www.acmicpc.net/problem/2116

/*
<주사위 쌓기>
주요: 구현, 아이디어
1. 각 주사위는 90, 180, 270도 돌릴 수 있다.
  => 결국, 아래, 윗면을 제외한 가장 큰 값들의 합을 찾는 문제이다.
2. 경우의 수는 6가지이다. (아랫면이 1~6일때)
3. 자신의 눈과 매칭되는 주사위의 눈의 값을 각각 지정해준다.
4. 주사위를 이제 하나씩 쌓으면서 옆면들중 값이 가장 큰 것이 무엇인지 찾는다.
  => 6,5,4 이 세가지 값이 후보이다. 다른 값은 나오지 않는다.
  => 각 경우의 수를 다시 만들어 비교해본다.
5. 아랫면이 1~6 일때 모두를 돌았을때의 최대값을 비교해서 답을 출력한다.

*/

int N;
int dices[10010][8]; // 내 반대편 눈의 값 ex) dice[2][1] : 2번주사위 1번눈의 반대면의 값
int ans;

int main(int argc, char const *argv[]) {
  cin >> N;
  for (int i = 1; i <= N; i++) {
    int num[8] = {0, };
    for (int j = 1; j <= 6; j++) {
      cin >> num[j];
    }
    // 3번
    dices[i][num[1]] = num[6];
    dices[i][num[6]] = num[1];
    dices[i][num[2]] = num[4];
    dices[i][num[4]] = num[2];
    dices[i][num[3]] = num[5];
    dices[i][num[5]] = num[3];
  }

  // 2번
  for (int eye = 1; eye <= 6; eye++) {
    int temp = 0;
    int down = eye;
    for (int i = 1; i <= N; i++) {
      int up = dices[i][down];
      // 4번
      if(down == 6 && up != 5) temp += 5;
      else if(down == 6 && up == 5) temp += 4;
      else if(up == 6 && down != 5) temp += 5;
      else if(up == 6 && down == 5) temp += 4;
      else if(up != 6 && down != 6) temp += 6;
      down = up;
    }
    ans = max(ans, temp);
  }
  cout << ans;


  return 0;
}
