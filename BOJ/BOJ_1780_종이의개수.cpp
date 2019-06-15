#include <iostream>
using namespace std;
//https://www.acmicpc.net/problem/1780

/*
<종이의 개수>
주요: 분할 정복(Divide-and-conquer)
1. 가장 간단한 경우로 기본 단계를 찾는다.
  => 비교 배열의 크기가 1x1가 될 때까지 분할 한다.
  => 9개가 다 같은 값인지 확인한다.
  => 같은 값이면 그 해당 값을 플러스 해주고 아닐경우 9등분 해준다.
  => size가 1 일때(1칸짜리) 그대로 해당 값을 플러스 해준다.
2. 재귀 함수를 호출 할 때마다 비교할 배열의 크기를 줄여준다.
  => 3의 제곱수로 구성되므로 3씩 나눠준다.
======
* -1, 0, 1 연속 수이므로 각각 count 배열의 인덱스 0,1,2에 대응시킨다.

*/

int paper[2200][2200];
int count[3];

void cut_paper(int size, int a, int b){

  int cur = paper[a][b];
  int div_size = size/3;
  bool same = true;

  if(size == 1){
    count[cur+1]++;
    return;
  }

  for (int i = a; i < a+size; i++) {
    for (int j = b; j < b+size; j++) {
      if(cur != paper[i][j]){
        same = false;
      }
    }
  }

  if(same){
    count[cur+1]++;
  }
  else{
    for (int i = 0; i < 3; i++) {
      for (int j = 0; j < 3; j++) {
        cut_paper(div_size, a + (div_size*i), b + (div_size*j));
      }
    }
  }
}

int main() {

  int N;

  cin >> N;

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cin >> paper[i][j];
    }
  }

  cut_paper(N, 0, 0);

  for (int i = 0; i < 3; i++) {
    cout << count[i] << endl;
  }

  return 0;
}
