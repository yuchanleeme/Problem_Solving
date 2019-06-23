#include <iostream>
using namespace std;
//https://www.acmicpc.net/problem/1038

int main() {

  int N, temp, first, next, count = 0;
  unsigned long long i = 0;
  bool flag;

  cin >> N;

  while(N != count){
    i++;
    flag = true;

    temp = i;
    if(temp < 10){
      count++;
      flag = false;
    }
    else if(temp > 9876543210){
      break;
    }
    else{
      while (temp != 0) {
        first = temp % 10;
        temp /= 10;
        next = temp % 10;

        if(next <= first){ // 한번이라도 증가 또는 같아 지면 break
          flag = false;
          break;
        }
        else{ // 이쪽 분기에 들어왔는데 temp<10 이면 while문 끝난것임으로 break
          if(temp < 10){
            break;
          }
        }
      }
    }

    if(flag){
      count++;
    }
  }

  cout << i;


  return 0;
}
