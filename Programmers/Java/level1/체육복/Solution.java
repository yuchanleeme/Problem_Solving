package level1.체육복;

class Solution {
    public static int solution(int n, int[] lost, int[] reserve) {
        int answer = 0;
        int[] check = new int[n+2];
        for (int i = 0; i < lost.length; i++) {
            check[lost[i]] -= 1;
        }
        for (int i = 0; i < reserve.length; i++) {
            check[reserve[i]] += 1;
        }
        for (int i = 1; i <= n; i++) {
            if(check[i] >= 0) continue;
            else if(check[i] == -1){
                if(check[i-1] == 1){
                    check[i] += 1;
                    check[i-1] -= 1;
                }else if(check[i+1] == 1){
                    check[i] += 1;
                    check[i+1] -=1;
                }
            }
        }

        for (int i = 1; i <= n; i++) {
            if(check[i] >= 0) answer++;
        }
        return answer;
    }
}