/*
<모의고사>
//https://programmers.co.kr/learn/courses/30/lessons/42840
주요: 구현
1. 각 수포자들의 정답 수를 찾는다.
2. 그 중 최댓값을 구해 각 정답 수와 비교한다.
3. 해당하는 수포자들의 번호만 리턴한다.
==========
* 배열과 ArrayList 사이의 값 전달 참고

*/

package level1.모의고사;

import java.util.ArrayList;

class Solution {

    public static int[][] check = { {1,2,3,4,5}, {2,1,2,3,2,4,2,5}, {3,3,1,1,2,2,4,4,5,5} };

    public static int[] solution(int[] answers) {
        int[] idx = {0,0,0};
        int[] res = {0,0,0};
        for(int answer : answers){
            if(idx[0] == 5) idx[0] = 0;
            if(idx[1] == 8) idx[1] = 0;
            if(idx[2] == 10) idx[2] = 0;

            if(check[0][idx[0]++] == answer) res[0]++;
            if(check[1][idx[1]++] == answer) res[1]++;
            if(check[2][idx[2]++] == answer) res[2]++;
        }

        int MaxValue = Math.max(res[0],Math.max(res[1], res[2]));
        ArrayList<Integer> arr = new ArrayList<>();
        for (int i = 0; i < 3; i++) {
            if(res[i] == MaxValue) arr.add(i+1);
        }

        int[] ans = new int[arr.size()];
        for (int i = 0; i < ans.length; i++) {
            ans[i] = arr.get(i);
        }
        return ans;
    }
}
