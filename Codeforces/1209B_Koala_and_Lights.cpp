#include <iostream>
#include <vector>
using namespace std;
//http://codeforces.com/contest/1209/problem/B

int main() {
  int N;
  scanf("%d", &N);

  int ans = 0;
  vector<int> lights;

  for (int i = 0; i < N; i++) {
    int temp;
    scanf("%1d", &temp);
    lights.push_back(temp);
    if(temp == 1){ ans++;}
  }

  vector<int> par[N];
  for (int i = 0; i < N; i++) {
    int a, b;
    scanf("%d %d", &a, &b);
    par[i].push_back(a);
    par[i].push_back(b);
  }

<<<<<<< HEAD
  // max : 125 => 5 + Lcm(1,2,3,4,5)
=======
  // max : 125 => 5 + Lcd(1,2,3,4,5)
>>>>>>> c5f331eb49a56d83253c1e81ded2fa48d105513b
  for (int i = 1; i <= 125; i++) {
    int res = 0;
    for (int j = 0; j < N; j++) {
      if(i < par[j][1]){
        if(lights[j] == 1){ res++;}
        continue;
      }
      if((i-par[j][1]) % par[j][0] == 0){
        // change lights
        if(lights[j] == 0){ lights[j] = 1;}
        else{ lights[j] = 0;}
      }
      if(lights[j] == 1){ res++;}
    }

    ans = max(ans, res);
  }

  printf("%d\n", ans);

  return 0;
}
