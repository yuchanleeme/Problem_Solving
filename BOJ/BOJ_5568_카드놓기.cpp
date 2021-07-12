#include <bits/stdc++.h>
using namespace std;
//https://acmicpc.net/problem/5568

/*
<카드 놓기>
주요: 재귀 
1. 각 경우의 수를 string 변수를 이용해 재귀함수를 돌린다.
2. set을 이용해 중복을 체크한다.
3. 최종 set 사이즈를 출력한다.

*/

int n, k;
vector<int> arr;
set<string> res;
int visitNum[12];

void func(string str, int level) {
    if (level == k) {
        res.insert(str);
        return;
    }

    for (int i = 0; i < n; i++) {
        if (visitNum[i] == true) continue;
        visitNum[i] = true;
        func(str + to_string(arr[i]), level + 1);
        visitNum[i] = false;
    }
}

int main() {
    cin >> n >> k;

    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        arr.push_back(temp);
    }

    func("", 0);

    cout << res.size();
    return 0;
}