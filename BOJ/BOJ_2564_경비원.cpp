#include <bits/stdc++.h>
using namespace std;
//https://www.acmicpc.net/problem/2564

/*
<경비원>
주요: 구현
1. 각 위치에 맞게 최소값을 계산한다.
2. 반대편일 경우, 양옆편중 하나일 경우, 같은라인일 경우를 나눠서 계산한다.
3. 최소값을 출력한다.

*/

int col, row, N;
int x, y, ans;
vector<pair<int, int> > location;

int main(int argc, char const *argv[]) {

  cin >> col >> row >> N;

  for (int i = 0; i < N; i++) {
    int tx, ty;
    cin >> tx >> ty;
    location.push_back({tx,ty});
  }
  cin >> x >> y;

  for (int i = 0; i < location.size(); i++) {
    int mx = location[i].first;
    int my = location[i].second;
    if(mx+x == 3 || mx+x == 7){
      // 반대편
      if(x == 1 || x == 2)
        ans += (row + min(my+y, (col-my)+(col-y)));
      else
        ans += (col + min(my+y, (row-my)+(row-y)));
    }
    else if(mx == x){
      // 같은 라인
      ans += abs(my-y);
    }
    else{
      // 양쪽
      if(x == 1 && mx == 3) ans += (my + y);
      else if(x == 1 && mx == 4) ans += (my + col-y);
      else if(x == 2 && mx == 3) ans += (row-my + y);
      else if(x == 2 && mx == 4) ans += (row-my + col-y);
      else if(x == 3 && mx == 1) ans += (my + y);
      else if(x == 3 && mx == 2) ans += (my + row-y);
      else if(x == 4 && mx == 1) ans += (col-my + y);
      else if(x == 4 && mx == 2) ans += (col-my + row-y);
    }
  }
  cout << ans;
  return 0;
}
