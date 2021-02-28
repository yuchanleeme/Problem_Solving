/*
<두 개 뽑아서 더하기>
//https://programmers.co.kr/learn/courses/30/lessons/68644
주요: set, 정렬
1. 각 경우의 수를 만들어 set에 넣는다.
2. 해당 set을 정렬해 리턴한다.
==========
* HashSet을 쓰면 정렬 필요
* TreeSet을 쓰면 정렬 해줌

*/

package level1.두개뽑아서더하기;
import java.util.Arrays;
import java.util.HashSet;
import java.util.Set;

public class Solution {
    public static int[] solution(int[] numbers) {

        Set<Integer> set = new HashSet<>();
        for (int i = 0; i < numbers.length; i++) {
            for (int j = i+1; j < numbers.length; j++) {
                set.add(numbers[i]+numbers[j]);
            }
        }

        // 정렬
        int[] answer = new int[set.size()];
        int idx = 0;
        for(int item : set){
            answer[idx++] = item;
        }
        Arrays.sort(answer);
        return answer;
    }
}
