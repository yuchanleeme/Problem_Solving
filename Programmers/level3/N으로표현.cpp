#include <bits/stdc++.h>
using namespace std;
//https://programmers.co.kr/learn/courses/30/lessons/42895

/*
<N으로 표현>
주요: DP
1. dp[x][y] = 최소 x개의 N을 이용해서 만들 수 있는 숫자중 y번째 숫자
2. 각 자리수로 매칭을 시켜서 사칙연산 계산을 한 뒤 최소 횟수를 찾아 리턴한다.
  ex) 5+5   +   5*55  => dp[2][?]   +  dp[3][?] = dp[5][?]
  ex) 55/5   +   5*555  => dp[3][?]   +  dp[4][?] = dp[7][?]
3. 8을 넘어가면 -1을 리턴한다.

*/

int check[32010];  // 중복 됐으면 pass
vector<int> dp[10];

int solution(int N, int number) {
    int answer = 0;
    if (N == number) return 1;  // N = number 일 때 바로 리턴
    dp[1].push_back(N);
    check[N] = 1;

    string temp = to_string(N);
    for (int i = 2; i <= 8; i++) {
        for (int j = i - 1; j >= 1; j--) {
            for (int k = 0; k < dp[j].size(); k++) {
                int now = dp[j][k];
                for (int idx = 0; idx < dp[i - j].size(); idx++) {
                    int op = dp[i - j][idx];
                    // 사칙연산 계산
                    int res[4];
                    res[0] = now + op;
                    res[1] = now - op;
                    res[2] = now * op;
                    res[3] = now / op;

                    // 사칙연산 계산한거 확인
                    for (int q = 0; q < 4; q++) {
                        if (res[q] == number) return i;
                        if (res[q] >= 1 && res[q] <= 32000 && check[res[q]] == 0) {
                            check[res[q]] = 1;
                            dp[i].push_back(res[q]);
                        }
                    }
                }
            }
        }
        temp += to_string(N);  // "55", "555", "5555" 이런 것들
        if (stoi(temp) == number) return i;
        dp[i].push_back(stoi(temp));
    }

    return -1;
}