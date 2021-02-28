/*
<완주하지 못한 선수>
//https://programmers.co.kr/learn/courses/30/lessons/42576
주요: 구현, HashMap
풀이 1. 정렬 후 비교를 통해 선수를 찾는다.
풀이 2. HashMap을 통해 +1 -1을 해서 선수를 찾는다.
==========
* HashMap의 사용
* getOrDefault 메소드 사용

*/

package level1.완주하지못한선수;
import java.util.Arrays;
import java.util.HashMap;

public class Solution {

    // 정렬 후 비교 풀이
    public static String solution1(String[] participant, String[] completion) {
        String answer = "";
        Arrays.sort(participant);
        Arrays.sort(completion);

        for (int i = 0; i < completion.length; i++) {
            if(!participant[i].equals(completion[i])) return participant[i];
        }
        return participant[participant.length-1];
    }

    // HashMap 풀이
    public static String solution2(String[] participant, String[] completion) {
        String answer = "";
        HashMap<String, Integer> hm = new HashMap<>();
        for(String item : participant) hm.put(item, hm.getOrDefault(item,0)+1);
        for(String item : completion) hm.put(item, hm.get(item)-1);
        for(String key : hm.keySet()){
            if(hm.get(key) != 0){
                answer = key;
                break;
            }
        }
        return answer;
    }

}
