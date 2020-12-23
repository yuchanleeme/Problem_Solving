#include <bits/stdc++.h>
using namespace std;
//https://www.acmicpc.net/problem/14467

/*
<소가 길을 건너간 이유1>
주요: 구현
1. 한번도 등장하지 않은 소 check배열로 체크한다.
2. 체크 된 소인데 cow 배열 값이 다르다면 길을 건넜다고 판단하고 최신화 한다.
3. 길을 건넌 횟수를 센다.

*/

int N, ans;
int check[110];
int cow[110];

int main(int argc, char const *argv[]) {
  cin >> N;
  for (int i = 0; i < N; i++) {
    int x, y;
    cin >> x >> y;
    if(check[x] == 0){
      cow[x] = y;
      check[x] = 1;
    }
    else if(check[x] == 1){
      if(cow[x] != y){
        cow[x] = y;
        ans++;
      }
    }
  }
  cout << ans;
  return 0;
}
