#include <bits/stdc++.h>
using namespace std;
//https://programmers.co.kr/learn/courses/30/lessons/12900

/*
<2 x n 타일링>
주요: DP
1. 1칸 짜리는 세로로 세우는 경우 밖에 없다.
2. 2칸 짜리는 가로로 두개 세우는 경우가 있다. (이 때, 세로로 두개 세우는것은 제외한다. - 중복 제거를 위해)
3. 따라서 dp[x] = dp[x-1](1칸 적은것에서 세로로 하나 세우기) + dp[x-2](2칸 적은것에서 두개 세우기) 가 된다.
4. 이 점화식을 풀면 된다.
==========
* dp[x] = x칸 까지 세울 수 있는 경우의 수

*/

vector<int> dp = {
    0,
    1,
    2,
};
int solution(int n) {
    for (int i = 3; i <= n; i++) {
        int temp = dp[i - 2] + dp[i - 1];
        dp.push_back(temp % 1000000007);
    }
    return dp[n];
}