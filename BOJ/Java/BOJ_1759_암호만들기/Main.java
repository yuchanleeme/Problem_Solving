package BOJ_1759_암호만들기;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {
    static int L, C;
    static String[] alpha;
    static ArrayList<Integer> seq;
    static boolean[] chk;

    public static void backTracking(int level, int num){
        if(level == L){
            String temp = "";
            int mouem = 0, jaeum = 0;
            for (int i = 0; i < seq.size(); i++) {
                if(alpha[seq.get(i)].matches("^[aeiou]$")){
                    mouem++;
                }else{
                    jaeum++;
                }
                temp += alpha[seq.get(i)];
            }

            if(mouem >= 1 && jaeum >= 2){
                System.out.println(temp);
            }
            return;
        }


        for (int i = num; i < C; i++) {
            seq.add(i);
            backTracking(level+1, i+1);
            seq.remove(seq.size()-1);
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine()," ");
        L = Integer.parseInt(st.nextToken());
        C = Integer.parseInt(st.nextToken());
        alpha = new String[C];
        seq = new ArrayList<>();

        st = new StringTokenizer(br.readLine(), " ");
        for (int i = 0; i < C; i++) {
            alpha[i] = st.nextToken();

        }
        Arrays.sort(alpha);
        backTracking(0,0 );

    }
}
