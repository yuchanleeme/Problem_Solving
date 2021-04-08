package level1.문자열다루기기본;

class Solution {
    public static boolean solution(String s) {
        return s.matches("^[0-9]{4}|[0-9]{6}$");
    }
}