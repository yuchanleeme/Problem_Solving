#include <iostream>
#include <vector>
using namespace std;
//https://www.acmicpc.net/problem/17128

/*
<소가 정보섬에 올라온 이유>
주요: 구현
1. idx를 잘 잡아주면 풀리는 문제
2. 1: (1 2 3 4), 2: (2 3 4 5) .... N-1 : (N-1 N 1 2), N : (N 1 2 3)
	=> 이렇게 N개짜리 seq 배열을 만든다.
3. 각 해당하는 스티커 번호를 가지고 있는 배열 원소를 뺀 후 -1 곱해서 다시 더하면 된다.
4. 이 때마다 갱신해준다.	

*/

int num[202020];
int seq[202020];
int sticker[202020];
int N, Q;
long long base;

int main(int argc, char const *argv[]) {

	cin.tie(0);
	ios_base::sync_with_stdio(false);
  cin >> N >> Q;
  for (int i = 0; i < N; i++)
    cin >> num[i];
  for (int i = 0; i < Q; i++)
    cin >> sticker[i];

  for (int i = 0; i < N; i++) {
    int temp_mul = 1;
    for (int j = i; j < i+4; j++) {
      if(j >= N) temp_mul *= num[j-N];
      else temp_mul *= num[j];
    }
    seq[i] = temp_mul;
    base += temp_mul;
  }

  for (int i = 0; i < Q; i++) {
    int idx = sticker[i] - 1;
    for (int j = idx; j > idx-4; j--) {
      if(j < 0){
        base -= seq[j+N];
        seq[j+N] *= -1;
        base += seq[j+N];
      }
      else {
        base -= seq[j];
        seq[j] *= -1;
        base += seq[j];
      }
    }
    cout << base <<"\n";
  }

  return 0;
}
