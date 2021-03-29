package level1.문자열내림차순으로배치하기;

import java.util.Arrays;

class Solution {
    public static String solution(String s) {
        char[] arr = s.toCharArray();
        Arrays.sort(arr); // char 값을 기준으로 정렬한다.

        // 우선 StringBuilder로 char[]를 가져온다.
        StringBuilder sb = new StringBuilder(String.copyValueOf(arr));

        // 가져온 StringBuilder 객체를 reverse 취한다.
        sb.reverse();

        return sb.toString(); // 그걸 String으로 출력한다.
    }
}