/*
<신규 아이디 추천>
//https://programmers.co.kr/learn/courses/30/lessons/72410
주요: 문자열, 구현
1. 단계별로 구현한다.
2. 길이가 0일 때를 주의한다.
==========
* toLoewrCase() 사용법, 정규식 사용법
* repalceAll, indexOf, charAt, substring

*/

package level1.신규아이디추천;

class Solution {
    public static String solution(String new_id) {
        // 1단계
        String answer = new_id.toLowerCase();

        // 2단계
        answer = answer.replaceAll("[^0-9a-z_.-]","");

        // 3단계
        while(answer.indexOf("..") != -1){
            answer = answer.replace("..", ".");
        }

        // 4단계
        if(answer.length() > 0 && answer.charAt(0) == '.') answer = answer.substring(1);
        if(answer.length() > 0 && answer.charAt(answer.length()-1) == '.') answer = answer.substring(0, answer.length()-1);

        // 5단계
        if(answer.equals("")) answer = "a";

        // 6단계
        if(answer.length() >= 16) answer = answer.substring(0,15);
        if(answer.charAt(answer.length()-1) == '.') answer = answer.substring(0, answer.length()-1);

        // 7단계
        while(answer.length() < 3){
            answer += answer.charAt(answer.length()-1);
        }
        return answer;
    }
}
