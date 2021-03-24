package level1._2016년;

class Solution {
    public static String solution(int a, int b) {
        String answer = "";
        String[] week = {"SUN","MON","TUE","WED","THU","FRI","SAT"};
        int[] days = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

        int res = 0;
        for (int i = 1; i < a; i++) {
            res += days[i];
        }
        res += b;
        return week[(4+res)%7];
    }
}