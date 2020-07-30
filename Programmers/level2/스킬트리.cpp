#include <vector>
#include <string>
using namespace std;
//https://programmers.co.kr/learn/courses/30/lessons/49993

/*
<스킬 트리>
주요: 구현 , find
1. 일단 스킬트리를 처음부터 순회하면서 해당 글자가 skill에 있는지 찾는다. (find)
  1-1. 스킬이 없다면 다음 스킬트리의 스킬을 찾는다.
  1-2. 스킬이 있는데, 지금 찍을 수 있는 스킬이 아니면 isSkill을 false 하고 for문을 종료한다.
  1-3. 스킬이 있고, 지금 찍을 수 있는 스킬이라면 skill의 idx를 증가시키고 계속 찾는다.
2. 위 1번 과정을 모든 스킬트리 배열에 적용해 조사한 뒤 개수를 리턴한다.
===========
* 왜 계속 틀리는지 몰랐는데 string::npos로 안하고 범위 지정을 해서 였다.
* find() 함수는 못 찾으면 string::npos를 리턴한다.

*/

#include <iostream>
int solution(string skill, vector<string> skill_trees) {
    int answer = 0;

    for(auto s : skill_trees){
        int idx = 0;
        bool isSkill = true;
        for (int i = 0; i < s.length(); i++){
            int num = skill.find(s[i]);
            if(num == string::npos) continue;
            if(skill[idx] == s[i]) idx++;
            else{
                isSkill = false;
                break;
            } 
        }
        if(isSkill) answer++;
    }
    return answer;
}