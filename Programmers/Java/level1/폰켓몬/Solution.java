package level1.폰켓몬;

import java.util.HashSet;

class Solution {
    public static int solution(int[] nums) {
        HashSet<Integer> hs = new HashSet<>();
        for(int num : nums){
            hs.add(num);
        }

        if(hs.size() >= nums.length/2) return nums.length/2;
        else return hs.size();
    }
}