#include <bits/stdc++.h>
using namespace std;
//https://programmers.co.kr/learn/courses/30/lessons/12985

/*
<예상 대진표>
주요: 비교
1. 몫 계산을 위해 우선 1~2^20까지의 각 번호에서 1을 빼준 a-1과 b-1을 비교한다.
2. 2^1 부터 2^20까지 2를 곱하면서 몫을 비교해 같은 값일 때 그 라운드에서 만난다고 보면 된다.

*/

int solution(int n, int a, int b) {
    int temp = 1;
    for (int i = 1; i <= 20; i++) {
        temp *= 2;
        if ((a - 1) / temp == (b - 1) / temp) return i;
    }
}