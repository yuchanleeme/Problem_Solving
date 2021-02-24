#include <bits/stdc++.h>
using namespace std;
//www.acimpc.net/problem/2941

/*
<크로아티아 알파벳>
주요: 구현
1. 크로아티아 알파벳에 해당하는 단어들을 다 치환한다.
2. 단, dz= , z= 은 순서를 지켜서 치환한다.
3. 최종 str의 길이가 총 알파벳 길이이다.

*/

string str;
int main() {
    cin >> str;

    while (true) {
        int startLength = str.length();
        if (str.find("c=") != string::npos) str.replace(str.find("c="), 2, "O");
        if (str.find("c-") != string::npos) str.replace(str.find("c-"), 2, "O");
        if (str.find("d-") != string::npos) str.replace(str.find("d-"), 2, "O");
        if (str.find("lj") != string::npos) str.replace(str.find("lj"), 2, "O");
        if (str.find("nj") != string::npos) str.replace(str.find("nj"), 2, "O");
        if (str.find("s=") != string::npos) str.replace(str.find("s="), 2, "O");
        if (str.find("dz=") != string::npos) {
            str.replace(str.find("dz="), 3, "O");
            continue;
        }
        if (str.find("z=") != string::npos) str.replace(str.find("z="), 2, "O");
        int endLength = str.length();
        if (startLength == endLength) break;
    }
    cout << str.length();

    return 0;
}