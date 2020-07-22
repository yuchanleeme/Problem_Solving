#include <string>
#include <vector>
using namespace std;
//https://programmers.co.kr/learn/courses/30/lessons/12910

/*
<나누어 떨어지는 숫자 배열>
주요: 구현
1. 나누어 떨어지면 answer 벡터에 넣는다.
2. answer 벡터에 원소가 없으면 -1을 넣고 리턴
3. 아니라면 정렬 후 리턴

*/

vector<int> solution(vector<int> arr, int divisor) {
    vector<int> answer;
    for (int i = 0; i < arr.size(); i++)
      if(arr[i] % divisor == 0) answer.push_back(arr[i]);

    if(answer.size() == 0) answer.push_back(-1);
    else sort(answer.begin(), answer.end());
    return answer;
}
