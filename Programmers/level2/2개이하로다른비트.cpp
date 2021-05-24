#include <bits/stdc++.h>
using namespace std;
//https://programmers.co.kr/learn/courses/30/lessons/77885

/*
<2개 이하로 다른 비트>
주요: 비트연산, 아이디어
1. 0이 언제 처음 등장하는지가 중요하다.
2. 큰 수들 중에 작은 수이기 때문에 처음 0등장 한 후 다음 비트들은 무조건 동일해야 한다.
3. xxxx0111 -> xxxx1011 와 같이 0이 나온 부분과 그 이전 부분의 비트를 반대로 켜주면 된다.

*/

vector<long long> arr;
vector<long long> solution(vector<long long> numbers) {
    vector<long long> answer;

    // 미리 2의 배수 값 만들어 놓기
    long long idx = 1;
    arr.push_back(1);
    for (int i = 1; i < 60; i++) {
        idx *= 2;
        arr.push_back(idx);
    }

    for (int i = 0; i < numbers.size(); i++) {
        long long num = numbers[i];
        int res = 0;
        for (int j = 0; j < 60; j++) {
            if ((num >> res) & 1 == 1) {
                res++;
            } else
                break;
        }
        // res는 0이 처음 나온 위치
        if (res == 0 || res == 1) {
            answer.push_back(numbers[i] + 1);
        } else {
            long long ans = numbers[i] + 1;
            ans += (arr[res - 1] - 1);
            answer.push_back(ans);
        }
    }
    return answer;
}

int main() {
    long long a = 1e15 - 1;
    solution({7, 2});
    return 0;
}