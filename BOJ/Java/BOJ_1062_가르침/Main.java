package BOJ_1062_가르침;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    static int N, K, ans = 0;
    static String[] words;
    static boolean[] chk;

    static void dfs(int level, int next){
        if(level == K){
            int res = 0;
            for(String word : words){
                boolean canRead = true;
                for (int i = 0; i < word.length(); i++) {
                    if(chk[word.charAt(i) -'a'] == false){
                        canRead = false;
                        break;
                    }
                }

                if(canRead) res++;
            }
            ans = Math.max(ans, res);
            return;
        }

        for (int i = next; i < 26; i++){
            if(chk[i] == true) continue;
            else{
                chk[i] = true;
                dfs(level+1, i+1);
                chk[i] = false;
            }
        }

    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String nk = br.readLine();
        StringTokenizer st = new StringTokenizer(nk, " ");
        N = Integer.parseInt(st.nextToken());
        K = Integer.parseInt(st.nextToken());

        words = new String[N];
        for (int i = 0; i < N; i++) {
            String temp = br.readLine();
            words[i] = temp.substring(4, temp.length()-4);
        }

        if(K < 5){
            System.out.println("0");
        }else{
            chk = new boolean[26];
            // a, n, t, i, c는 고정
            chk['a' - 'a'] = true;
            chk['n' - 'a'] = true;
            chk['t' - 'a'] = true;
            chk['i' - 'a'] = true;
            chk['c' - 'a'] = true;

            dfs(5, 0);
            System.out.println(ans);
        }

    }
}
