#include <bits/stdc++.h>
using namespace std;
//https://www.acmicpc.net/problem/16113

/*
<시그널>
주요: BFS
1. 우선 행의 길이가 5이므로 이를 이용해 열의 길이를 재서 벡터에 넣는다.
2. BFS탐색을 통해 연결된 #의 개수를 센다.
3. 개수와 각 숫자에 맞게 조사해 해당 숫자를 출력한다.
4. 1은 idx += 1, 나머지는 idx +=3 을 해준다.
==========
개수 -> 숫자
  13 -> 8
  12 -> 0,6,9
  11 -> 2,3,5
  9 -> 4
  7 -> 7
  5 -> 1
===========
*/
int N;
int line;
string base_signal;
vector<string> signalX;
int visitSignal[6][20010];
int tx[4] = {0, -1, 1, 0}, ty[4] = {1, 0, 0, -1};

int checkSignal(int y){

  queue<pair<int, int> > que;
  que.push({0,y});
  visitSignal[0][y] = 1;
  int check = 0;

  while (!que.empty()) {
    int temp_size = que.size();
    check += temp_size;
    for (int q = 0; q < temp_size; q++) {
      for (int i = 0; i < 4; i++) {
        int nx = tx[i] + que.front().first;
        int ny = ty[i] + que.front().second;

        if(nx < 0 || ny < 0 || nx >=5 || ny >= line) continue;
        if(visitSignal[nx][ny] == 1 || signalX[nx][ny] != '#') continue;
        que.push({nx,ny});
        visitSignal[nx][ny] = 1;
      }
      que.pop();
    }
  }
  if(check == 13) cout << "8";
  else if(check == 12){
    if(signalX[2][y+1] == '.') cout << "0";
    else if(signalX[3][y] == '.') cout << "9";
    else cout << "6";
  }
  else if(check == 11){
    if(signalX[1][y+2] == '.') cout << "5";
    else if(signalX[3][y] == '.') cout << "3";
    else cout << "2";
  }
  else if(check == 9) cout << "4";
  else if(check == 7) cout << "7";
  else if(check == 5){
    cout << "1";
    return 1;
  }

  return 3;
}

int main(int argc, char const *argv[]) {
  cin >> N;
  cin >> base_signal;
  line = N/5;
  for (int i = 0; i < 5; i++) {
    string temp = base_signal.substr(i*line, line);
    signalX.push_back(temp);
  }

  for (int i = 0; i < line; i++) {
    if(signalX[0][i] == '#'){
      i += checkSignal(i);
    }
  }
  return 0;
}
