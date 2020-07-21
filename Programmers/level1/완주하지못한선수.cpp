#include <algorithm>
#include <vector>
using namespace std;
//https://programmers.co.kr/learn/courses/30/lessons/42576

/*
<완주하지 못한 선수>
주요: 구현, 정렬
1. 비교해야하는 두 배열의 차이점을 살펴본다.
  1.1 개수 차이 (N vs N-1)
  1.2 completion와 participant는 포함관계이다.
  1.3 즉, participant = completion + (완주 못한 사람)이란 뜻
2. 이제 정렬을 하고 O(nlogn) for문 하나로 비교하면서 일치 하지 않는 원소를 찾아 리턴한다.
3. 못 찾았다면 마지막 원소가 완주 하지 못한 선수이므로 그 값을 리턴한다.
==========
* 단순 2중 for문으로 비교하면 효율성 check에서 실패한다.
* 원래는 해시맵으로 구현하는 문제인데(unorderd_map) 정렬로 풀어봤다.
* input 배열 두개가 너무 유사해서 정렬을 생각해봤다.

*/

int visit[101010];
string solution(vector<string> participant, vector<string> completion) {

    string answer = "";
    sort(participant.begin(), participant.end());
    sort(completion.begin(), completion.end());

    for (int i = 0; i < completion.size(); i++) {
      if(participant[i] != completion[i])
        return participant[i];
    }
    return participant.back();
}
