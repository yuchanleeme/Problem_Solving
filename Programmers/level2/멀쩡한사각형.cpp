#include <vector>
#include <string>
using namespace std;
//https://programmers.co.kr/learn/courses/30/lessons/62048

/*
<멀쩡한 사각형>
주요: 수학
1. 좌표평면에 사각형을 올리고 (0,0)을 지나는 양의 기울기를 가진 대각선을 하나 그려본다.
2. 이 대각선 과 x = K가 만나는 점 이하의 사각형들을 다 더해주면된다.
3. 대칭이므로 반대쪽 대각선 개수까지 x 2배 해서 더해준 후 리턴한다.

*/

#include <iostream>
long long solution(int w,int h) {
    long long answer = 0;
    if(w < h) swap(w,h);
    double lean = (double)h / w;
    for (long long i = 1; i < w; i++){
        double maxDot = lean * i;
        cout << i << " " <<maxDot << endl;
        answer += (int)maxDot;
    }
    return answer * 2;
}

int main(){
    cout << solution(8,12);
}