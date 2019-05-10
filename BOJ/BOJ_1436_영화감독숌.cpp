#include <iostream>
#include <string>
using namespace std;
// https://www.acmicpc.net/problem/1436

/*
<영화감독 숌>
주요: string 라이브러리를 이용한다.
1. 1부터 순차적으로 값을 증가시켜 확인하되, 비교시에는 string으로 형변환 후 비교한다.
2. string으로 변환된 값에 '666'이 포함되어 있으면 카운팅한다.
3. 비교하는 값이 입력받은 N과 같다면 while문을 종료 후 출력한다.

*/

int main(){

  int N;
  int num = 0, check = 0;
  string temp_value_str;

  cin >> N ;

  while(true){
    num++;
    temp_value_str = to_string(num);

    if(temp_value_str.find("666") != string::npos){
      check++;
    }
    if(check == N)
      break;
  }

  cout << num << endl;

  return 0;
}
