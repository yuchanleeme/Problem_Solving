package level1.문자열내p와y의개수;

class Solution {
    static boolean solution(String s) {
        s = s.toLowerCase();
        int p = 0, y = 0;
        for (int i = 0; i < s.length(); i++) {
            char X = s.charAt(i);
            if(X == 'p') p++;
            else if(X == 'y') y++;
        }

        return p == y;
    }
}