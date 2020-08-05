#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
//https://programmers.co.kr/learn/courses/30/lessons/42839

/*
<소수 찾기>
주요: 백트래킹, 소수
1. 범위가 주어졌으니 미리 1~10,000,000까지의 소수를 구한다. (7자리 수)
2. 이제 각 종이의 조핣 수를 찾는다. (백트래킹)
  2.1 모든 조합을 백트래킹으로 찾는다. 
  2.2 check 배열을 활용하여 중복을 줄인다. (0011, 011, 11 등)
3. 모든 조합에 대한 결과를 출력한다.
*/

// 소수 찾기
int prime[10101010] = {1, 1, };
int check[10101010];
void make_prime(){
  for (int i = 2; i < sqrt(10101010); i++) {
    if(prime[i] == 1) continue;
    for (int j = i*i; j < 10101010; j+=i) {
      if(prime[j] == 1) continue;
      prime[j] = 1;
    }
  }
}

// 2번
vector<int> seq;
vector<int> visit;
string num;
int ans;
void backtracking(int level){
  if(level > num.length()) return;  // 길이 초과 시 리턴

  string temp = "";
  for(int i = 0; i < seq.size(); i++){
    temp += seq[i];
  }
  if(temp != "" && prime[stoi(temp)] == 0 && check[stoi(temp)] == 0){
    check[stoi(temp)] = 1;
    ans++;
  }

  for(int i = 0; i < num.length(); i++){
    if(visit[i] == 0){
      seq.push_back(num[i]);
      visit[i] = 1;
      backtracking(level+1);
      visit[i] = 0;
      seq.pop_back();
    }
  }
}

int solution(string numbers) {
  make_prime();
  num = numbers;
  visit = vector<int>(num.length()+1, 0);
  backtracking(0);
  return ans;
}
