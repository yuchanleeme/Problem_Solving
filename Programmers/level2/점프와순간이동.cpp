#include <bits/stdc++.h>
using namespace std;
// https://programmers.co.kr/learn/courses/30/lessons/12980

/*
<점프와 순간 이동>
주요: 재귀
1. 짝수이면 자신/2 의 위치에서 순간이동으로 올 수 있다.
2. 홀수이면 자신-1의 위치에서 1칸 이동한다.
==========
* dp 배열을 이용했더니 메모리 초과가 났다.
* 배열의 크기가 많이 커진다면 재귀를 써보자.

*/

int solution(int x) {
    if (x == 1) return 1;
    if (x % 2 == 0) {
        return solution(x / 2);
    } else {
        return solution(x - 1) + 1;
    }
}
