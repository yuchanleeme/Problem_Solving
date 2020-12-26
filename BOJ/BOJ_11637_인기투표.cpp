#include <bits/stdc++.h>
using namespace std;
// https://www.acmicpc.net/problem/11637

/*
<인기 투표>
주요: 구현
1. 후보번호랑 같이 seq 벡터에 넣는다.
2. 벡터를 큰 순으로 정렬한다.
3. 각 조건에 따라 출력한다.
==========
* (double) total/2를 주의하자.

*/

bool comp(const pair<int, int> &A, const pair<int, int> &B){
  return A.first > B.first;
}
vector<pair<int, int> > seq;
int main(){
  int T;
  scanf("%d", &T);

  while(T--){
    int N, total;
    total = 0;
    scanf("%d", &N);

    seq.clear();
    for (int i = 0; i < N; i++) {
      int temp;
      scanf("%d", &temp);
      seq.push_back({temp,i+1});
      total += temp;
    }

    sort(seq.begin(),seq.end(), comp);
    if(seq[0].first == seq[1].first){
      printf("no winner\n");
    }
    else if((double)total/2 < seq[0].first){
      printf("majority winner %d\n", seq[0].second);
    }
    else{
      printf("minority winner %d\n", seq[0].second);
    }
  }
}
