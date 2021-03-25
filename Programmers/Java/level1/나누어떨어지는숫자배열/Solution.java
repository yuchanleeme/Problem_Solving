package level1.나누어떨어지는숫자배열;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;

class Solution {
    public int[] solution(int[] arr, int divisor) {
        ArrayList<Integer> list = new ArrayList<>();
        for(int item : arr){
            if(item % divisor == 0) list.add(item);
        }
        Collections.sort(list);
        if(list.size() == 0) return new int[]{-1};
        int[] answer = new int[list.size()];
        for (int i = 0; i < list.size(); i++) {
            answer[i] = list.get(i);
        }
        return answer;
    }

    public int[] solution2(int[] arr, int divisor) {
        int answer[] = Arrays.stream(arr).filter(item -> item % divisor == 0).toArray();
        if(answer.length == 0) return new int[]{-1};
        else{
            Arrays.sort(answer);
            return answer;
        }
    }

}
