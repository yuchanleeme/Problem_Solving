#include <bits/stdc++.h>
using namespace std;
//https://programmers.co.kr/learn/courses/30/lessons/42628

/*
<이중우선순위큐>
주요: priority_queue
1. 우선순위큐로 최대힙, 최소힙을 선언한다.
2. 값을 넣어줄 때, 해당 순서의 값을 순서로 인덱싱한다. (checkIdx)
3. 조건에 맞게 maxHeap, minHeap에서 값을 제거하되,
  3-1. 각각의 반대 힙에서 이미 제거 처리가 되었으면 추가적으로 제거한 뒤 진행한다. (checkIdx배열 사용)
  3-2. 이 때 제거된 idx의 checkIdx 값은 2이고, 제거되지 않았다면 1로 놓는다. (bool로 true, false로 해도 된다.)
4. 모든 명령이 끝났으면 추가적으로 checkIdx 배열과 최대힙, 최소힙과 비교해 아직 남아있는 원소들을 제거한다.
5. 이제 각각 조건에 맞게 값을 answer 벡터에 넣고 리턴한다.
==========
* 멀티셋을 쓰면 더 간단히 풀린다. (정렬이 되는 성질)
* 최댓값  *(--multiset.end());
* 최솟값  *multiset.begin();
* 제거할 때  multiset.erase(--multiset.end());, multiset.erase(multiset.begin());

*/

int checkIdx[1000010];
int idx;

vector<int> solution(vector<string> operations) {
    priority_queue<pair<int, int> > maxHeap;
    priority_queue<pair<int, int> > minHeap;

    for (auto str : operations) {
        string op = str.substr(0, 1);
        int num = stoi(str.substr(2));
        if (op == "I") {  // 2번
            maxHeap.push({num, idx});
            minHeap.push({-num, idx});
            checkIdx[idx] = 1;
            idx++;
        } else if (op == "D") {  // 3번
            if (num == 1) {
                while (!maxHeap.empty()) {
                    int topidx = maxHeap.top().second;
                    if (checkIdx[topidx] == 2)
                        maxHeap.pop();
                    else {
                        checkIdx[topidx] = 2;
                        maxHeap.pop();
                        break;
                    }
                }
            } else if (num == -1) {
                while (!minHeap.empty()) {
                    int topidx = minHeap.top().second;
                    if (checkIdx[topidx] == 2)
                        minHeap.pop();
                    else {
                        checkIdx[topidx] = 2;
                        minHeap.pop();
                        break;
                    }
                }
            }
        }
    }

    // 4번
    while (!maxHeap.empty()) {
        int topidx = maxHeap.top().second;
        if (checkIdx[topidx] == 2)
            maxHeap.pop();
        else
            break;
    }

    while (!minHeap.empty()) {
        int topidx = minHeap.top().second;
        if (checkIdx[topidx] == 2)
            minHeap.pop();
        else
            break;
    }

    // 5번
    vector<int> answer;
    if (!maxHeap.empty())
        answer.push_back(maxHeap.top().first);
    else
        answer.push_back(0);

    if (!minHeap.empty())
        answer.push_back(-minHeap.top().first);
    else
        answer.push_back(0);
    return answer;
}

int main() {
    solution({"I 16", "I -5643", "D -1", "D 1", "D 1", "I 123", "D -1"});
    return 0;
}