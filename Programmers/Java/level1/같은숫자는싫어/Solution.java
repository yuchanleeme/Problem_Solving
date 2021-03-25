package level1.같은숫자는싫어;

import java.util.*;

public class Solution {
    public static int[] solution(int []arr) {
        ArrayList<Integer> list = new ArrayList<>();

        for(int item : arr){
            if(list.size() == 0)
                list.add(item);
            else{
                if(list.get(list.size()-1) != item) list.add(item);
            }
        }
        int[] answer = new int[list.size()];
        for (int i = 0; i < list.size(); i++) {
            answer[i] = list.get(i);
        }
        return answer;
    }
}