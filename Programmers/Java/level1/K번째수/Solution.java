package level1.K번째수;

import java.util.ArrayList;
import java.util.Collections;

public class Solution {
    public static int[] solution(int[] array, int[][] commands) {
        int[] answer = new int[commands.length];
        for (int i = 0; i < commands.length; i++) {
            int st = commands[i][0];
            int ed = commands[i][1];
            int target = commands[i][2];

            ArrayList<Integer> list = new ArrayList<Integer>();
            for (int j = st-1; j < ed; j++) {
                list.add(array[j]);
            }
            Collections.sort(list);
            answer[i] = list.get(target-1);
        }
        
        return answer;
    }
}
