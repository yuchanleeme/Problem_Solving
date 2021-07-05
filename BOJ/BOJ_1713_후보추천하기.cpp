#include <bits/stdc++.h>
using namespace std;
//https://acmicpc.net/problem/1713

/*
<후보 추천하기>
주요: 구현
1. 먼저 사진틀에 등록되어 있는지 확인을 한다.
2. 등록되어 있으면 추천 수를 더해준다.
3. 등록되어 있지 않으면 그 다음으로 사진틀이 꽉찼는지 확인한다.
    3-1. 꽉 차 있지 않으면 사진틀에 등록한다.
    3-2. 꽉 차 있다면 제일 적고, 오래된 idx 값을 찾아 바꿔준다.
4. 최종 계산된 배열을 정렬하고 최종값을 출력한다.
==========
* 우선순위 큐를 활용하는 방법도 있다. 
 -> 우선순위 조건을 따로 설정해주고, (적은 순, 오래된 순)
 -> 큐 값을 찾아서 업데이트 해준다음 다시 넣어주는 방식

*/

typedef struct info {
    int order;   // 순서
    int score;   // 추천 점수
    int number;  // 학생 번호
} Info;

int N, K;
vector<Info> arr;

const bool comp(Info &A, Info &B) {
    return A.number < B.number;
}

int main() {
    cin >> N >> K;
    int nowPic = 0;
    for (int i = 1; i <= K; i++) {
        int num;
        cin >> num;

        // 먼저 사진틀에 등록되어 있는지 확인
        int idx = -1;
        for (int j = 0; j < arr.size(); j++) {
            if (arr[j].number == num) {
                idx = j;
                break;
            }
        }

        // 있으면 값 ++
        if (idx != -1) {
            arr[idx].score++;
        } else {
            // 없으면 arr 꽉 차있는지 확인
            if (arr.size() < N) {
                arr.push_back({i, 1, num});
            } else {
                // 꽉 차있으면 제일 값이 작은 애를 찾음
                Info comp = arr[0];
                int idx = 0;
                for (int j = 0; j < arr.size(); j++) {
                    if (comp.score == arr[j].score) {
                        if (comp.order > arr[j].order) {
                            idx = j;
                            comp = arr[j];
                        }
                    } else if (comp.score > arr[j].score) {
                        idx = j;
                        comp = arr[j];
                    }
                }
                // 빠질 idx를 찾음
                arr[idx] = {i, 1, num};
            }
        }
    }
    sort(arr.begin(), arr.end(), comp);
    for (auto student : arr) {
        cout << student.number << " ";
    }
    return 0;
}