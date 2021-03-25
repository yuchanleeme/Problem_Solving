package level1.가운데글자가져오기;

class Solution {
    public static String solution(String s) {
        String answer = "";
        int len = s.length();
        if(len % 2 == 0)
            return s.substring((len-1)/2, len/2 +1);
        else
            return s.substring(len/2, len/2+1);
    }
}