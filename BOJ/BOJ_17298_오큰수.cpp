#include <iostream>
#include <vector>
#include <stack>
using namespace std;
//https://www.acmicpc.net/problem/17298

/*
<오큰수>

=========
* 단순 vector로 크기 비교 했더니 시간초과가 떴다.

*/

int main(int argc, char const *argv[]) {

  int N, input, max_value;
  vector<int> seq;

  scanf("%d", &N);
  for (int i = 0; i < N; i++) {
    scanf("%d", &input);
    seq.push_back(input);
  }

  for (int i = 0; i < N; i++) {
    max_value = seq[i];

    for (int j = i + 1; j < N; j++) {
      if(seq[j] > max_value){
        max_value = seq[j];
        break;
      }
    }

    if(max_value == seq[i]){
      printf("-1 ");
    }
    else{
      printf("%d ", max_value);
    }
  }

  return 0;
}
