#include <iostream>
#include <vector>
using namespace std;
//https://www.acmicpc.net/problem/2751

/*
<수 정렬하기2>
주요: 병합 정렬
1. 병합 정렬을 구현해 nlogn의 속도로 정렬한다.
2. 큰 부분에서 작은 부분으로 분할하여 크기를 비교한다.
3. 비교가 끝나면 남아있는 값들을 그대로 복사해준다(남았다는것은 크기비교가 완료된것).
4. 임시 벡터에 값을 기존 리스트에 복사한다.
5. 분할정복이 끝난 리스트(오름차순 정렬)를 출력한다.

*/

vector<int> list;
void merge(int left, int mid, int right){

  // (left ~ mid)  - (mid+1 ~ right)
  vector<int> temp;
  int a = left, b = mid+1, c = right;
  while(a <= mid && b <= right){
    if(list[a] < list[b]){
      temp.push_back(list[a++]);}
    else{
      temp.push_back(list[b++]);
    }
  }

  // 3번
  if(a-1 == mid){
    for (int p = b; p <= right; p++) {
      temp.push_back(list[p]);
    }
  }
  else if(b-1 == right){
    for (int p = a; p <= mid; p++) {
      temp.push_back(list[p]);
    }
  }

  // 4번
  int idx = 0;
  for (int i = left; i <= right; i++) {
    list[i] = temp[idx++];
  }
}

void partition(int left, int right){
  while(left < right){
    int mid = (left+right) / 2;

    partition(left, mid);
    partition(mid+1, right);
    merge(left, mid, right);
    return;
  }

}

int main() {

  int N;
  scanf("%d", &N);
  for (int i = 0; i < N; i++) {
    int temp;
    scanf("%d", &temp)
    list.push_back(temp);
  }

  partition(0, N-1);

  for (int i = 0; i < N; i++) {
    printf("%d\n", list[i]);
  }

  return 0;
}
