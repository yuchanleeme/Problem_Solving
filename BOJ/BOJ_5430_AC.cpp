#include <iostream>
#include <deque>
#include <cstring>
using namespace std;
//https://www.acmicpc.net/problem/5430

/*
<AC>
주요: 덱 STL의 기능들을 활용한다.
1. strtok 기능을 이용해 입력값을 분해한다.
2. 덱의 성질(양방향 큐)을 이용해 R 입력을 받았을때 시작점을 맨앞/맨뒤로 설정한다.
3. D를 입력 받았을 때 reverse의 값에 따라 pop을 한다. (덱 비었는데 D 입력받으면 error_trigger True)
4. 위 상황에 맞게 출력한다.
=======
* 입/출력이 까다로운 문제
* strtok 기능을 이용한다.
* 배열크기 할당을 잘해준다. (런타임 에러의 원인)
* \b는 출력할때는 사용하지 않는다. (커서 위치만 옮겨지는 것)

*/

int main() {

  int T, n, idx;
  char p[100010], born_data[500010];
  bool reverse, error_trigger; // true 일때 정방향, false일때 역방향

  scanf("%d", &T); // T값 저장

  for (int t = 0; t < T; t++) {
    scanf("%s", &p); // 함수 저장
    scanf("%d", &n); // 배열 개수 저장
    scanf("%s", &born_data); // 입력 저장
    idx = 0;
    deque<int> dq;
    reverse = true;
    error_trigger = false;

    // 1번
    char *tok = strtok(born_data,"[,]");
    while (tok != NULL) {
      dq.push_back(atoi(tok));
      tok = strtok(NULL,"[,]");
    }

    for (int i = 0; i < 100001; i++) {

      // 2,3번
      if(p[i] == 'R'){
        reverse = !reverse;
      }
      else if(p[i] == 'D'){

        if (dq.empty()) {
          error_trigger = true;
          break;
        }

        if (reverse) {
          dq.pop_front();
        }
        else{
          dq.pop_back();
        }
      }
      else{
        break;
      }
    }

    if (error_trigger) {
      printf("error\n");
    }
    else if(dq.size() == 0){
      printf("[]\n");
    }
    else{
      if (reverse) {
        printf("[");
        for (int p = 0; p < dq.size(); p++) {
          if (p == dq.size()-1) {
            printf( "%d]\n",dq.at(p));
            break;
          }
          else{ printf("%d,",dq.at(p));}
        }
      }
      else{
        printf("[");
        for (int p = dq.size(); p > 0; p--) {
          if (p == 1) {
            printf("%d]\n",dq.at(p - 1));
            break;
          }
          printf("%d,",dq.at(p - 1));
        }
      }
    }
  }
  return 0;
}
