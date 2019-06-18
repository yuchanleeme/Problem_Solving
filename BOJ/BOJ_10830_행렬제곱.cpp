#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
//https://www.acmicpc.net/problem/10830

/*
<행렬 제곱>
주요: 분할 정복
1. 분할 정복을 이용해 시간복잡도를 줄인다.
2. 행렬은 결합법칙이 성립하기 때문에 시행 횟수를 줄이기 위해 반씩 나눠서 계산한다.
  => 행렬 계수가 짝수이면 계수의 반에 해당하는 값을 두번 곱해준다 (ex: 50 -> 25 x 25)
  => 행렬 계수가 홀수이면 계수-1에 기본 base 행렬을 곱해준다 (ex: 51 -> (51-1) x 1)
3. 계산된 행렬을 res에 저장하고 출력한다.

*/

typedef long long ll;
const int R = 1000;
int N;
ll B;
vector<vector<ll> > base(6, vector<ll>(6, 0)); // 최대 크기[6][6] 행렬 만들기

// 2개의 행렬을 입력받아 곱한 뒤 그 결과 행렬을 리턴하는 함수
vector<vector<ll> > mul_matrix(vector<vector<ll> > A, vector<vector<ll> > B){

  vector<vector<ll> > temp(6, vector<ll>(6, 0));
  ll sum;

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      sum = 0;
      for(int k = 0; k < N; k++) {
        sum += (A[i][k] * B[k][j]) % R;
      }
    temp[i][j] = sum % R;
    }
  }

  return temp;
}

// 분할 정복을 이용해 값 계산하는 함수
vector<vector<ll> > cal(ll num){

  if(num == 1){
    return base;
  }
  else{
    if(num % 2 == 0){
      vector<vector<ll> > temp = cal(num/2); // 시간 줄이기
      return mul_matrix(temp, temp);
    }
    else{
      return mul_matrix(cal(num-1), base);
    }
  }
}

int main() {

  ll temp;
  cin >> N >> B;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cin >> temp;
      base[i][j] = temp % R;
    }
  }

  vector<vector<ll> > res = cal(B);

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cout << res[i][j] << " ";
    }
    cout << endl;
  }

  return 0;
}
