#include <bits/stdc++.h>
using namespace std;
//https://programmers.co.kr/learn/courses/30/lessons/12977

/*
<소수 만들기>
주요: 수학, 조합
1. 에라토스테네스의 체를 활용해 prime 배열에 소수를 정리한다.
2. backtracking을 활용해 배열의 3개의 원소를 뽑아서 더한다.
3. 1번에서의 소수에 해당하면 answer++ 를 한다.
4. 모든 과정이 끝나면 answer를 리턴한다.

*/

int answer;
int prime[50010];
vector<int> seq;

void backtracking(int level, int num, vector<int> &nums) {
    if (level == 3) {
        int temp = 0;
        for (int i = 0; i < seq.size(); i++) {
            temp += seq[i];
        }
        if (prime[temp] == 0) answer++;
        return;
    }

    for (int i = num; i < nums.size(); i++) {
        seq.push_back(nums[i]);
        backtracking(level + 1, i + 1, nums);
        seq.pop_back();
    }
}

int solution(vector<int> nums) {
    // 소수 찾기
    for (int i = 2; i <= sqrt(50010); i++) {
        if (prime[i] == 1) continue;
        for (int j = i * 2; j < 50000; j += i) {
            prime[j] = 1;
        }
    }

    backtracking(0, 0, nums);

    return answer;
}
