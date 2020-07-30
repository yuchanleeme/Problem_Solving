#include <vector>
#include <algorithm>
#include <string>
using namespace std;
//https://programmers.co.kr/learn/courses/30/lessons/42584

/*
<주식 가격>
주요: 구현
1. 앞으로 나오는 가격 중에 나보다 큰 가격이 한번이라도 나오면 중지한다.
2. 그때까지의 값을 answer 벡터에 넣어 리턴한다.
*/

vector<int> solution(vector<int> prices) {
    vector<int> answer;

    for(int i = 0; i < prices.size(); i++){
        int temp = 0;
        for (int j = i+1; j < prices.size(); j++){
            temp++;
            if(prices[i] > prices[j]) break;
        }
        answer.push_back(temp);
    }
    return answer;

}