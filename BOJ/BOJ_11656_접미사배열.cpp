#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
//https://www.acmicpc.net/problem/11656

/*
<접미사 배열>
주요: string, 정렬
1. 입력받은 input 값을 for문을 이용해 차례대로 words벡터에 저장시킨다.
  => compare이라는 더미 스트링 변수를 이용해 접미사 배열을 만듬
2. 저장된 words 벡터를 정렬해 출력한다.

*/

int main() {

  string input;
  cin >> input;

  vector<string> words;


  for (int i = 0; i < input.size(); i++) {
    string compare;
    for (int j = i; j < input.size(); j++) {
      compare += input[j];
    }
    words.push_back(compare);
  }

  sort(words.begin(),words.end());

  for (int i = 0; i < words.size(); i++) {
    cout << words[i] << '\n';
  }

  return 0;
}
