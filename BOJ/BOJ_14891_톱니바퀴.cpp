#include <bits/stdc++.h>
using namespace std;
//https://www.acmicpc.net/problem/14891

/*
<톱니바퀴>
주요: 구현, 시뮬레이션
1. 기어의 정보를 입력받는다. (gear)
2. 초기 9시, 3시 방향 idx를 지정한다. idx-(6(왼), 2(오))
3. 이제 각 기어에 따라 어떻게 회전시킬지 구현한다.
4. 편의를 위해 방향 idx를 바꾸는 함수를 따로 만들어 계산한다.
5. 최종 결과를 계산해 출력한다.
==========
* 회전하는 idx를 계산할 때 %를 쓰며, -1이나 length를 벗어나지 않게 한다.

*/

int K;
vector<string> gear;
vector<pair<int, int> > idx;

// 회전 한 후 idx의 위치값 고치는 함수
void change_dir(int G, int dir){

  if(dir == 1){
    idx[G].first = (idx[G].first-1 +8)%8;
    idx[G].second = (idx[G].second-1 +8)%8;
  }
  else if(dir == -1){
    idx[G].first = (idx[G].first+1)%8;
    idx[G].second = (idx[G].second+1)%8;
  }

}

// 기어에 따라 고려해야 하는 대상이 다르므로 따로 계산한다.
void change(int G, int dir){
  int changeInfo[4] = {0, }; // 기어 어느쪽으로 회전할지
  changeInfo[G] = dir;

  // 기어값에 따라 계산
  if(G == 0){
    // 1->2->3
    if(gear[0][idx[0].second] != gear[1][idx[1].first]){
      changeInfo[1] = -changeInfo[0];
      if(gear[1][idx[1].second] != gear[2][idx[2].first]){
        changeInfo[2] = -changeInfo[1];
        if(gear[2][idx[2].second] != gear[3][idx[3].first]){
          changeInfo[3] = -changeInfo[2];
        }
      }
    }
  }else if(G == 1){
    // 0, 2->3
    if(gear[0][idx[0].second] != gear[1][idx[1].first]) changeInfo[0] = -changeInfo[1];
    if(gear[1][idx[1].second] != gear[2][idx[2].first]){
      changeInfo[2] = -changeInfo[1];
      if(gear[2][idx[2].second] != gear[3][idx[3].first]){
        changeInfo[3] = -changeInfo[2];
      }
    }
  }else if(G == 2){
    // 3, 1->0
    if(gear[2][idx[2].second] != gear[3][idx[3].first]) changeInfo[3] = -changeInfo[2];
    if(gear[2][idx[2].first] != gear[1][idx[1].second]){
      changeInfo[1] = -changeInfo[2];
      if(gear[1][idx[1].first] != gear[0][idx[0].second]){
        changeInfo[0] = -changeInfo[1];
      }
    }
  }
  else if(G == 3){
    // 2->1->0
    if(gear[3][idx[3].first] != gear[2][idx[2].second]){
      changeInfo[2] = -changeInfo[3];
      if(gear[2][idx[2].first] != gear[1][idx[1].second]){
        changeInfo[1] = -changeInfo[2];
        if(gear[1][idx[1].first] != gear[0][idx[0].second]){
          changeInfo[0] = -changeInfo[1];
        }
      }
    }
  }

  // 이제 기어 이동
  for (int i = 0; i < 4; i++) {
    change_dir(i, changeInfo[i]);
  }

}

int main(int argc, char const *argv[]) {

  for (int i = 0; i < 4; i++) {
    string temp; cin >> temp;
    gear.push_back(temp);
    idx.push_back({6,2}); // 초기 6(왼), 2(오)
  }

  cin >> K;
  for (int i = 0; i < K; i++) {
    int G, dir;
    cin >> G >> dir;
    change(G-1, dir);
  }

  // 값 계산
  int answer = 0;
  if(gear[0][(idx[0].first+2)%8] == '1') answer += 1;
  if(gear[1][(idx[1].first+2)%8] == '1') answer += 2;
  if(gear[2][(idx[2].first+2)%8] == '1') answer += 4;
  if(gear[3][(idx[3].first+2)%8] == '1') answer += 8;
  cout << answer;
  return 0;
}
