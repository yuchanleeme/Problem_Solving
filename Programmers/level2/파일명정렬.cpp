#include <bits/stdc++.h>
using namespace std;
//https://programmers.co.kr/learn/courses/30/lessons/17686

/*
<파일명 정렬>
주요: stable sort
1. stable sort와 comp를 활용해서 정렬한다.
2. 우선 A와 B의 Head와 Number을 분류한다.
3. Head 와 Num에 맞게 정렬하여 그 벡터를 리턴한다.
==========
* comp 함수 작동 원리를 이해하자.
* stoi를 쓰면 자동으로 앞에 0은 빠진다.

*/

bool comp(const string &A, const string &B) {
    string HeadA = "", HeadB = "";
    string NumA = "", NumB = "";
    bool numberA = false, numberB = false;
    for (int i = 0; i < A.length(); i++) {
        if ('0' <= A[i] && A[i] <= '9') {
            numberA = true;
            NumA += A[i];
        } else {
            if (numberA) break;
            HeadA += A[i];
        }
    }
    for (int i = 0; i < B.length(); i++) {
        if ('0' <= B[i] && B[i] <= '9') {
            numberB = true;
            NumB += B[i];
        } else {
            if (numberB) break;
            HeadB += B[i];
        }
    }
    transform(HeadA.begin(), HeadA.end(), HeadA.begin(), ::tolower);
    transform(HeadB.begin(), HeadB.end(), HeadB.begin(), ::tolower);
    if (HeadA == HeadB) {
        int transA = stoi(NumA), transB = stoi(NumB);
        return transA < transB;
    } else {
        return HeadA < HeadB;
    }
}

vector<string> solution(vector<string> files) {
    stable_sort(files.begin(), files.end(), comp);
    return files;
}