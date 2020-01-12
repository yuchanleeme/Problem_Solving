#include <iostream>
#include <vector>
#include <map>
using namespace std;
//https://www.acmicpc.net/problem/1620

/*
<나는야 포켓몬 마스터 이다솜>
주요: map, 입출력
1. 두가지 자료구조를 이용한다. (map, vector)
  1-1) map : key값으로 value값을 찾기 위해 이용
  1-2) vector : idx 값으로 string 값을 출력하기 위해 이용
2. name[0]이 1~9 사이에 있으면 이건 숫자이다.
  => stoi로 int값으로 바꾼뒤 (1-2) vector 이용해서 출력
3. 2번이 아니면 포켓몬의 이름이므로 (1-1) map 에서 찾아서 출력

===========
* cin,cout 출력 시 아래 두 줄을 넣어주어 시간을 줄인다.
  - ios::ios_base::sync_with_stdio(false);
  - cin.tie(NULL);

*/

int main() {

  ios::ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int N, M;
  cin >> N >> M;

  map<string, int> pokemon;
  vector<string> pokemon_2;
  for (int i = 1; i <= N; i++) {
    string input;
    cin >> input;
    pokemon[input] = i;
    pokemon_2.push_back(input);
  }

  for (int i = 0; i < M; i++) {
    string name;
    cin >> name;
    if('1' <= name[0] && '9' >= name[0]){
      cout << pokemon_2[stoi(name)-1] << '\n';
    }
    else{
      cout << pokemon[name] << '\n';
    }
  }
  return 0;
}
