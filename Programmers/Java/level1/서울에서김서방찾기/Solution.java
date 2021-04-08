package level1.서울에서김서방찾기;
import java.util.Arrays;

class Solution {
    public static String solution(String[] seoul) {
//        int x = Arrays.asList(seoul).indexOf("KIM");
//        return "김서방은 " + x + "에 있다";

        int x = -1;
        for (int i = 0; i < seoul.length; i++) {
            if(seoul[i].equals("Kim")){
                x = i; break;
            }
        }
        return "김서방은 " + x + "에 있다";
    }
}