package level1._3진법뒤집기;

class Solution {
    public static int solution(int n) {
        String res = "";
        while(n != 0){
            res += Integer.toString(n%3);
            n /= 3;
        }
        return Integer.parseInt(res,3);
    }
}